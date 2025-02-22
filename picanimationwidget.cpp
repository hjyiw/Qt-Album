#include "picanimationwidget.h"
#include "protreewidgetitem.h"
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
PicAnimationWidget::PicAnimationWidget(QWidget *parent)
    : QWidget{parent},_isStart(true),_factor(0.0f),_cur_item(nullptr)
{
    _timer = new QTimer(this);
    connect(_timer,&QTimer::timeout,this,&PicAnimationWidget::SlotTimerOut);
}

PicAnimationWidget::~PicAnimationWidget()
{

}

// 缓存图片
void PicAnimationWidget::setPixMap(QTreeWidgetItem *cur_item)
{
    if(!cur_item){
        return;
    }

    // 记录当前item
    _cur_item = cur_item;

    // 双图片缓存
    auto* pro_cur_item = dynamic_cast<ProTreeWidgetItem*>(cur_item);
    auto* pro_next_item = pro_cur_item->getNextItem();

    QString cur_path = pro_cur_item->getPath();
    _pixmap1.load(cur_path);

    // 加入map
    if(_map_item.find(cur_path) == _map_item.end()){
        _map_item[cur_path] = pro_cur_item;
        emit SigUpList(_cur_item);
    }
    emit SigSelectedItem(_cur_item);

    // 缓存下一张
    if(!pro_next_item){
        return;
    }
    QString next_path = pro_next_item->getPath();

    // 缓存图片
    _pixmap2.load(next_path);

    // 加入map
    if(_map_item.find(next_path) == _map_item.end()){
        _map_item[next_path] = pro_next_item;
        emit SigUpList(pro_next_item);
    }
}

// 开始展示
void PicAnimationWidget::animationStart()
{
    _factor = 0.0f;
    _timer->start(250);
    _isStart = true;
    SigMusicStartOrStop(_isStart);
}

// 停止
void PicAnimationWidget::animationStop()
{
    _timer->stop();
    _isStart = false;
    _factor = 0.0f;
    SigMusicStartOrStop(_isStart);
}

// 重写绘图事件
void PicAnimationWidget::paintEvent(QPaintEvent *event)
{
    if(_pixmap1.isNull()){
        animationStop();
        return;
    }

    // 绘制主图片
    QPainter main_painter(this);
    // 抗锯齿
    main_painter.setRenderHint(QPainter::Antialiasing,true);

    // 缩放图片
    QRect rect = geometry();
    int w = rect.width();
    int h = rect.height();
    _pixmap1 = _pixmap1.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // 绘制双图层
    QPixmap alpha_pix(_pixmap1.size());

    // 先设置透明
    alpha_pix.fill(Qt::transparent);

    // 计算通道值
    int alpha = 255*(1.0 - _factor); // 0 为完全透明

    QPainter p(&alpha_pix);


    p.setCompositionMode(QPainter::CompositionMode_Source); // 绘制原图层
    p.drawPixmap(0,0,_pixmap1);

    // 用指定颜色的alpha通道与现有像素相乘，实现透明度控制
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.fillRect(alpha_pix.rect(),QColor(0,0,0,alpha));

    p.end();

    int x = (w - alpha_pix.width()) / 2;
    int y = (h - alpha_pix.height()) / 2;
    main_painter.drawPixmap(x,y,alpha_pix);

    if(_pixmap2.isNull()){
        animationStop();
        return;
    }

    alpha = 255*_factor;

    // 缩放图片
    _pixmap2 = _pixmap2.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // 绘制双图层
    QPixmap alpha_pix2(_pixmap2.size());
    alpha_pix2.fill(Qt::transparent);

    QPainter p2(&alpha_pix2);
    p2.setRenderHint(QPainter::Antialiasing);

    p2.setCompositionMode(QPainter::CompositionMode_Source);
    p2.drawPixmap(0,0,_pixmap2);

    p2.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p2.fillRect(alpha_pix2.rect(),QColor(0,0,0,alpha));
    p2.end();

    x = (w - _pixmap2.width()) / 2;
    y = (h - _pixmap2.height()) / 2;

    main_painter.drawPixmap(x,y,alpha_pix2);
    event->accept();
}

// 改变透明因子
void PicAnimationWidget::SlotTimerOut()
{
    if(!_cur_item){
        animationStop();
        return;
    }

    // 透明因子++
    _factor += 0.1f;

    // 已完成一组图片交替
    if(_factor >= 1){
        auto* pro_cur_item = dynamic_cast<ProTreeWidgetItem*>(_cur_item);
        auto* _next_item = pro_cur_item->getNextItem();
        if(!_next_item){
            animationStop();
            update();
            return;
        }
        _cur_item = _next_item;
        _factor = 0.0f;
        setPixMap(_cur_item);
        update();
        return;
    }

    update();
}

// 前一张
void PicAnimationWidget::SlotNextPic()
{
    if(!_cur_item){
        return;
    }

    // 停止播放
    animationStop();
    emit SigPalyChanged(_isStart);

    auto* pro_cur_item = dynamic_cast<ProTreeWidgetItem*>(_cur_item);

    auto* pro_next_item = pro_cur_item->getNextItem();

    if(pro_next_item){
        this->setPixMap(pro_next_item);
    }
    update();
}

// 后一张
void PicAnimationWidget::SlotPrePic()
{
    if(!_cur_item){
        return;
    }

    // 停止播放
    animationStop();
    emit SigPalyChanged(_isStart);

    auto* pro_cur_item = dynamic_cast<ProTreeWidgetItem*>(_cur_item);

    auto* pro_pre_item = pro_cur_item->getPreItem();

    if(pro_pre_item){
        this->setPixMap(pro_pre_item);
    }

    update();
}

// 双击预览图
void PicAnimationWidget::SlotUpdatePic(QString path)
{
    auto iter = _map_item.find(path);

    if(iter == _map_item.end()){
        return;
    }

    // 找到了
    auto* pro_item = dynamic_cast<ProTreeWidgetItem*>(iter.value());

    this->animationStop();
    emit SigPalyChanged(_isStart);
    setPixMap(pro_item);
    update();

}


// 开始或暂停
void PicAnimationWidget::SlotPlayOrPause()
{
    if(_isStart){
        // 关掉
        animationStop();
    }
    else{
        // 开启
        animationStart();
    }
}
