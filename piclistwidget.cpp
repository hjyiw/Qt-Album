#include "piclistwidget.h"
#include "protreewidgetitem.h"
#include "const.h"
#include "piclistitem.h"
#include <QPainter>
PicListWidget::PicListWidget(QWidget *parent)
    : QListWidget{parent},_pic_cnt(0),_last_idx(17)
{
    this->setViewMode(QListWidget::IconMode);
    this->setIconSize(QSize(PREICON_SIZE,PREICON_SIZE));
    this->setSpacing(5); // 预览图间隔
    this->setFlow(QListView::LeftToRight); // 从左到右流动

    // 点击预览图
    connect(this,&PicListWidget::itemDoubleClicked,this,&PicListWidget::SlotDoubleClicked);
}

PicListWidget::~PicListWidget()
{

}

void PicListWidget::addPicItem(QString path)
{
    if(path.isEmpty()){
        return ;
    }

    // 在 dest_pix 上画 src_pix, dest_pix为固定长宽
    QPixmap src_pix(path);
    src_pix = src_pix.scaled(PREICON_SIZE,PREICON_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPixmap dest_pix(QSize(PREICON_SIZE,PREICON_SIZE));
    dest_pix.fill(QColor(220,220,220,50));

    QPainter p(&dest_pix);

    const int src_width = src_pix.width();
    const int src_height = src_pix.height();
    const int dest_width = dest_pix.width();
    const int dest_height = dest_pix.height();

    int x = (dest_width - src_width) / 2;
    int y = (dest_height - src_height) / 2;

    p.drawPixmap(x,y,src_pix);

    // 更新index
    _pic_cnt ++ ;

    // 创建listItem
    PicListItem* pic_list_item = new PicListItem(_pic_cnt,QIcon(dest_pix),path,this);
    pic_list_item->setSizeHint(QSize(PREITEM_SIZE,PREITEM_SIZE));
    this->addItem(pic_list_item);

    _pic_map[path] = pic_list_item;

    if(_pic_cnt == 1){
        _pos_origin = this->pos();
    }


}

// 加载预览图
void PicListWidget::SlotUpList(QTreeWidgetItem *item)
{
    if(!item){
        return;
    }

    auto* pro_item = dynamic_cast<ProTreeWidgetItem*>(item);

    QString path = pro_item->getPath();

    if(_pic_map.find(path) != _pic_map.end()){
        return;
    }

    addPicItem(path);

}

// 选中预览图
void PicListWidget::SlotSelectedItem(QTreeWidgetItem *item)
{
    if(!item){
        return;
    }

    auto* pro_item = dynamic_cast<ProTreeWidgetItem*>(item);

    QString path = pro_item->getPath();

    auto iter = _pic_map.find(path);

    // 没有找到
    if(iter == _pic_map.end()){
        return;
    }

    // 获取到列表项
    auto* pic_item = dynamic_cast<PicListItem*>(iter.value());

    // 获取索引
    int idx = pic_item->getIdx();

    if(idx >= 17){
        QPoint curPos = this->pos();
        this->move(curPos.x() - (idx - _last_idx) * 100,curPos.y());
        _last_idx = idx;
    }
    else{
        this->move(_pos_origin);
        _last_idx = 17;
    }
    this->setCurrentItem(iter.value());
}

// 双击预览图
void PicListWidget::SlotDoubleClicked(QListWidgetItem *item)
{
    if(!item){
        return;
    }

    PicListItem* pic_list_item = dynamic_cast<PicListItem*>(item);

    QString path = pic_list_item->getPath();

    emit SigDoubleClicked(path);
}
