#include "picshowdialog.h"
#include "ui_picshowdialog.h"
#include "picbutton.h"
#include <QGraphicsOpacityEffect>
#include <QFileDialog>
PicShowDialog::PicShowDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PicShowDialog)
{
    ui->setupUi(this);
    ui->btnPre->setIcons(":/icon/icon/previous.png",
                         ":/icon/icon/previous_hover.png",
                         ":/icon/icon/previous_press.png");
    ui->btnNext->setIcons(":/icon/icon/next.png",
                         ":/icon/icon/next_hover.png",
                         ":/icon/icon/next_press.png");

    // 图片前后切换
    connect(ui->btnPre,&PicButton::clicked,this,SigPreClicked);
    connect(ui->btnNext,&PicButton::clicked,this,SigNextClicked);

    // 设置透明度
    QGraphicsOpacityEffect* opacity_pre = new QGraphicsOpacityEffect(this);
    opacity_pre->setOpacity(0); // [0,1] 0: 完全透明
    ui->btnPre->setGraphicsEffect(opacity_pre); // 设置效果

    QGraphicsOpacityEffect* opacity_next = new QGraphicsOpacityEffect(this);
    opacity_next->setOpacity(0); // [0,1] 0: 完全透明
    ui->btnNext->setGraphicsEffect(opacity_next); // 设置效果

    _isVisible = false; // 记录状态

    // 初始化两个按钮的属性动画 第一个参数指定操作对象
    _animation_pre = new QPropertyAnimation(opacity_pre,"opacity",this); // 第二个为要操作的属性名称
    _animation_next = new QPropertyAnimation(opacity_next,"opacity",this);

    // 设置动画的缓动曲线
    _animation_pre->setEasingCurve(QEasingCurve::Linear); // 线性变化
    _animation_next->setEasingCurve(QEasingCurve::Linear); // 线性变化

    // 设置变化时长
    _animation_pre->setDuration(500); // 500 毫秒
    _animation_next->setDuration(500); // 500 毫秒
}

PicShowDialog::~PicShowDialog()
{
    delete ui;
}


// 动画显示按钮
void PicShowDialog::showPreNextBtns(bool isShow)
{
    // 从 透明到 不透明
    if(isShow && !_isVisible){
        _animation_pre->stop(); // 先停止
        _animation_pre->setStartValue(0); // 设置动画的起始透明度值为 0（完全透明）
        _animation_pre->setEndValue(1); // 设置动画的起始透明度值为 1（完全不透明）
        _animation_pre->start();

        _animation_next->stop(); // 先停止
        _animation_next->setStartValue(0); // 设置动画的起始透明度值为 0（完全透明）
        _animation_next->setEndValue(1); // 设置动画的起始透明度值为 1（完全不透明）
        _animation_next->start();

        // 记录状态
        _isVisible = true;
    }

    // 从 不透明 到 透明
    if(!isShow && _isVisible){
        _animation_pre->stop(); // 先停止
        _animation_pre->setStartValue(1);
        _animation_pre->setEndValue(0);
        _animation_pre->start();

        _animation_next->stop(); // 先停止
        _animation_next->setStartValue(1);
        _animation_next->setEndValue(0);
        _animation_next->start();

        // 记录状态
        _isVisible = false;
    }
}

// 窗口尺寸改变
void PicShowDialog::ReSizePix(const int &w, const int &h)
{
    if(_selected_path == "" || _selected_path.isEmpty()){
        return;
    }

    _pixmap = _pixmap.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->lblPic->setPixmap(_pixmap);
}

bool PicShowDialog::event(QEvent *e)
{
    switch(e->type()){
        case QEvent::Enter:
            showPreNextBtns(true);
            break;
        case QEvent::Leave:
            showPreNextBtns(false);
            break;
        default:
            break;
    }
    return QDialog::event(e);
}

// 展示图片
void PicShowDialog::SlotShowPic(const QString &pic_path)
{
    // 缓存图片
    _selected_path = pic_path;

    // 加载图片
    _pixmap.load(pic_path);

    int pic_width = this->width() - 20;
    int pic_height = this->height() - 20;
    // 缩放图片
    _pixmap = _pixmap.scaled(pic_width,pic_height,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->lblPic->setPixmap(_pixmap);

}

// 关闭项目
void PicShowDialog::SlotClearItem()
{
    _selected_path = "";
    ui->lblPic->clear();
}

