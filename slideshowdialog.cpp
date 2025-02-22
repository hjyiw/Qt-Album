#include "slideshowdialog.h"
#include "ui_slideshowdialog.h"
#include "protreewidget.h"

SlideShowDialog::SlideShowDialog(QTreeWidgetItem* firstItem,QTreeWidgetItem* lastItem,QWidget *parent)
    : ui(new Ui::SlideShowDialog),QDialog(parent),_first_item(firstItem),_last_item(lastItem)
{
    ui->setupUi(this);

    // 去边框
    this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    // 加图标
    ui->btnClose->setIcons(":/icon/icon/closeshow.png",":/icon/icon/closeshow_hover.png",":/icon/icon/closeshow_press.png");
    ui->btnClose->setFixedSize(60,30);
    ui->btnPre->setIcons(":/icon/icon/previous.png",":/icon/icon/previous_hover.png",":/icon/icon/previous_press.png");
    ui->btnNext->setIcons(":/icon/icon/next.png",":/icon/icon/next_hover.png",":/icon/icon/next_press.png");
    ui->btnPlay->setIcons(":/icon/icon/play.png",":/icon/icon/play_hover.png",
                          ":/icon/icon/play_press.png",":/icon/icon/pause.png",
                          ":/icon/icon/pause_hover.png",":/icon/icon/pause_press.png");
    ui->btnPlay->setFixedSize(60,30);

    // 关闭
    connect(ui->btnClose,&PicButton::clicked,this,&SlideShowDialog::SlotCloseClicked);

    // 播放
    connect(ui->btnPlay,&PicButton::clicked,ui->PicShowWidget,&PicAnimationWidget::SlotPlayOrPause);

    // 更新预览列表
    connect(ui->PicShowWidget,&PicAnimationWidget::SigUpList,ui->lwSlide,&PicListWidget::SlotUpList);
    connect(ui->PicShowWidget,&PicAnimationWidget::SigSelectedItem,ui->lwSlide,&PicListWidget::SlotSelectedItem);

    // 前后切换
    connect(ui->btnNext,&PicButton::clicked,ui->PicShowWidget,&PicAnimationWidget::SlotNextPic);
    connect(ui->btnPre,&PicButton::clicked,ui->PicShowWidget,&PicAnimationWidget::SlotPrePic);

    // 双击预览图
    connect(ui->lwSlide,&PicListWidget::SigDoubleClicked,ui->PicShowWidget,&PicAnimationWidget::SlotUpdatePic);

    // 播放状态改变
    connect(ui->PicShowWidget,&PicAnimationWidget::SigPalyChanged,ui->btnPlay,&PicStateButton::SlotPlayChanged);

    // 播放音乐
    auto* pro_tree = dynamic_cast<ProTreeWidget*>(parent);
    connect(ui->PicShowWidget,&PicAnimationWidget::SigMusicStartOrStop,pro_tree,&ProTreeWidget::SlotPlayMusic);

    ui->PicShowWidget->setPixMap(firstItem);
    ui->PicShowWidget->animationStart();

}

SlideShowDialog::~SlideShowDialog()
{
    delete ui;
}

void SlideShowDialog::SlotCloseClicked()
{
    emit ui->PicShowWidget->SigMusicStartOrStop(false);
    this->close();
}

