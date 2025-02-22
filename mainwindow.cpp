#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include "wizard.h"
#include "protree.h"
#include <QFileDialog>
#include "picshowdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();

    //
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    // 设置最小尺寸
    this->setMinimumSize(1300,850);

    // 整体水平布局
    QHBoxLayout* mainHLayout = new QHBoxLayout();
    mainHLayout->setContentsMargins(0,0,0,0);

    // 水平布局里面两个垂直布局
    QVBoxLayout* proVLayout = new QVBoxLayout();
    proVLayout->setContentsMargins(0,0,0,0);

    // 添加项目树
    _protree = new ProTree();

    proVLayout->addWidget(_protree);

    QVBoxLayout* picVLayout = new QVBoxLayout();
    picVLayout->setContentsMargins(0,0,0,0);

    // 添加PicShow
    _picshow = new PicShowDialog();
    picVLayout->addWidget(_picshow);


    mainHLayout->addLayout(proVLayout,1);
    mainHLayout->addLayout(picVLayout,4);

    ui->centralwidget->setLayout(mainHLayout);

    // 最大化显示
    this->setWindowTitle("Album");
    this->showMaximized();

    // 添加菜单和菜单项

    // 文件
    QMenu* menu_file = this->menuBar()->addMenu(tr("文件(&F)"));

    // 创建项目
    QAction* action_create_pro = new QAction(tr("创建项目"),menu_file);
    action_create_pro->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    action_create_pro->setIcon(QIcon(":/icon/icon/createpro.png"));

    // 打开项目
    QAction* action_open_pro = new QAction(tr("打开项目"),menu_file);
    action_open_pro->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    action_open_pro->setIcon(QIcon(":/icon/icon/openpro.png"));

    menu_file->addAction(action_create_pro);
    menu_file->addAction(action_open_pro);

    // 设置
    QMenu* menu_setting = this->menuBar()->addMenu(tr("设置(&S)"));

    // 背景音乐
    QAction* action_music = new QAction(QIcon(":/icon/icon/music.png"),tr("背景音乐"),menu_setting);
    action_music->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_M));

    menu_setting->addAction(action_music);

    // 转化proTree
    ProTree* pro_tree = dynamic_cast<ProTree*>(_protree);

    // 转化picshow
    auto* pic_show = dynamic_cast<PicShowDialog*>(_picshow);

    // 获取proTreeWidget
    auto* pro_tree_widget = pro_tree->getProTreeWidget();


    // 创建项目
    connect(action_create_pro,&QAction::triggered,this,&MainWindow::SlotCreatePro);

    // 打开项目
    connect(action_open_pro,&QAction::triggered,this,&MainWindow::SlotOpenPro);

    // 连接打开项目的信号和槽
    connect(this,&MainWindow::SigOpenPro,pro_tree,&ProTree::SlotOpenPro);

    // 背景音乐
    connect(action_music,&QAction::triggered,pro_tree_widget,&ProTreeWidget::SlotSetMusic);


    // 连接展示图片的信号和槽
    connect(pro_tree_widget,&ProTreeWidget::SigUpdateItem,pic_show,&PicShowDialog::SlotShowPic);

    // 连接切换图片的信号和槽
    connect(pic_show,&PicShowDialog::SigPreClicked,pro_tree_widget,&ProTreeWidget::SlotPrePic);
    connect(pic_show,&PicShowDialog::SigNextClicked,pro_tree_widget,&ProTreeWidget::SlotNextPic);

    // 连接关闭项目的信号和槽
    connect(pro_tree_widget,&ProTreeWidget::SigClearItem,pic_show,&PicShowDialog::SlotClearItem);

}


// 窗口尺寸改变
void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    auto* pic_show_dialog = dynamic_cast<PicShowDialog*>(_picshow);
    const int w = pic_show_dialog->width();
    const int h = pic_show_dialog->height();
    pic_show_dialog->ReSizePix(w,h);
}


// 创建项目
void MainWindow::SlotCreatePro(bool)
{
    qDebug() << "action_create_pro triggered";
    Wizard wizard(this);

    wizard.setWindowTitle(tr("创建项目"));
    auto page0 = wizard.page(0);
    page0->setTitle(tr("设置项目配置"));

    // 传配置
    connect(&wizard,&Wizard::SigProSettings,dynamic_cast<ProTree*>(_protree),&ProTree::SlotAddProToTree);
    wizard.show();
    wizard.exec();

    // 退出事件循环
    disconnect(&wizard);
}

// 打开项目
void MainWindow::SlotOpenPro(bool)
{
    // 获取要打开的目录路径
    QString dirName = QFileDialog::getExistingDirectory(this,tr("打开项目"),QDir::currentPath());
    qDebug() << "open dirName: " << dirName;
    emit SigOpenPro(dirName);
}
