#include "protreewidget.h"
#include <QGuiApplication>
#include <QMenu>
#include "const.h"
#include <QDebug>
#include "protreewidgetitem.h"
#include <QFileDialog>
#include <functional>
#include "closeprodialog.h"
#include "protree.h"
#include "slideshowdialog.h"
ProTreeWidget::ProTreeWidget(QWidget *parent)
    : QTreeWidget{parent}, _rightclicked_item(nullptr),_active_item(nullptr),_thread_import_pro(nullptr)
{
    // 隐藏表头
    this->setHeaderHidden(true);

    // 初始化Action
    _action_import = new QAction(QIcon(":/icon/icon/import.png"),tr("导入文件"),this);
    _action_close = new QAction(QIcon(":/icon/icon/close.png"),tr("关闭项目"),this);
    _action_setstart = new QAction(QIcon(":/icon/icon/core.png"),tr("设为活动项目"),this);
    _action_slideshow = new QAction(QIcon(":/icon/icon/slideshow.png"),tr("滚动展示"),this);

    // 导入文件
    connect(_action_import,&QAction::triggered,this,&ProTreeWidget::SlotImport);

    // 设为活动项目
    connect(_action_setstart,&QAction::triggered,this,&ProTreeWidget::SlotSetStart);

    // 关闭项目
    connect(_action_close,&QAction::triggered,this,&ProTreeWidget::SlotClose);

    // 轮播图播放
    connect(_action_slideshow,&QAction::triggered,this,&ProTreeWidget::SlotSlideShow);

    // 右键
    connect(this,&ProTreeWidget::itemPressed,this,&ProTreeWidget::SlotItemClicked);

    // 双击打开图片
    connect(this,&ProTreeWidget::itemDoubleClicked,this,&ProTreeWidget::SlotUpdateItem);

    // 初始化音乐播放器
    _music_player = new QMediaPlayer(this);
    _music_list = new QMediaPlaylist(this);
    _music_list->setPlaybackMode(QMediaPlaylist::Loop); // 循环
    _music_player->setPlaylist(_music_list);
    _music_player->setVolume(10);

}

// 右键item
void ProTreeWidget::SlotItemClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);

    // 判断是否是右键
    if( QGuiApplication::mouseButtons() != Qt::RightButton){
        return;
    }


    // 缓存右键的item
    _rightclicked_item = item;

    // 判断item类型
    if(item->type() == TreeItemPro){
        // 创建弹出菜单
        QMenu menu(this);
        menu.addAction(_action_import);
        menu.addAction(_action_setstart);
        menu.addAction(_action_slideshow);
        menu.addAction(_action_close);

        // 展示
        menu.exec(QCursor::pos());
    }



}

// 导入项目
void ProTreeWidget::SlotImport()
{

    if(!_rightclicked_item){
        qDebug() << "_rightclicked_item is nullptr";
        return;
    }

    // 当前项目路径
    QString pro_path = dynamic_cast<ProTreeWidgetItem*>(_rightclicked_item)->getPath();

    // 要导入的文件路径
    QString import_file = QFileDialog::getExistingDirectory(this,"选择导入目录",pro_path);

    if(import_file.isEmpty()){
        qDebug() << "import file is empty";
        return ;
    }

    // 初始化进度条
    int file_count = 0;
    _import_prog = new QProgressDialog(this);
    _import_prog->setWindowTitle(tr("文件导入进度"));
    _import_prog->setFixedWidth(IMPORT_PROG_WIDTH);
    _import_prog->setRange(0,IMPORT_PROG_WIDTH);


    // 多线程导入文件
    _thread_import_pro = std::make_shared<ImportProThread>(std::ref(import_file),std::ref(pro_path),
                                                           file_count,_rightclicked_item,_rightclicked_item,this);

    // 更新进度
    connect(_thread_import_pro.get(),&ImportProThread::SigUpdateProg,this,&ProTreeWidget::SlotUpdateProg);

    // 完成
    connect(_thread_import_pro.get(),&ImportProThread::SigOkProg,this,&ProTreeWidget::SlotOkProg);


    // 取消
    connect(_import_prog,&QProgressDialog::canceled,this,&ProTreeWidget::SlotCancelProg);
    connect(this,&ProTreeWidget::SigCancelProg,_thread_import_pro.get(),&ImportProThread::SlotCancelProg);


    // 开启线程
    _thread_import_pro->start();

    // 进入事件循环
    _import_prog->exec();



}

// 更新进度条
void ProTreeWidget::SlotUpdateProg(int file_count, QString added_name )
{
    // 防止进度条闪退
    if(!_import_prog){
        return;
    }
    _import_prog->setValue(file_count % IMPORT_MAX_FILE);

    // 记录文件
    _file_set.insert(added_name);
}


// 完成导入
void ProTreeWidget::SlotOkProg(int file_count)
{
    Q_UNUSED(file_count);

    _import_prog->setValue(IMPORT_MAX_FILE);
    _import_prog->deleteLater();
}

// 取消导入
void ProTreeWidget::SlotCancelProg()
{
    // 发送取消信号给线程
    emit SigCancelProg();
    _import_prog->deleteLater();
    _import_prog = nullptr;
}

// 设为活动项目
void ProTreeWidget::SlotSetStart()
{
    if(!_rightclicked_item){
        return;
    }
    QFont nullFont;
    nullFont.setBold(false);
    if(_active_item != nullptr){
        _active_item->setFont(0,nullFont);
    }

    _active_item = _rightclicked_item;
    nullFont.setBold(true);
    _active_item->setFont(0,nullFont);
}


// 关闭项目
void ProTreeWidget::SlotClose()
{
    CloseProDialog closeProDialog;
    auto res = closeProDialog.exec();

    if(res != QDialog::Accepted){
        return;
    }

    // 获取是否同时删除文件
    bool isDelete = closeProDialog.isDelete();

    // 获取当前项目的index

    // 转化_rightclicked_item
    ProTreeWidgetItem* delete_item =  dynamic_cast<ProTreeWidgetItem*>(_rightclicked_item);

    auto idx = this->indexOfTopLevelItem(delete_item);
    QString delete_path = delete_item->getPath();

    // 移除存储在ProTree中_path_set
    dynamic_cast<ProTree*>(this->parent()) -> getPathSet().remove(delete_path);

    // 判断是否删除文件
    if(isDelete){
        QDir delete_dir(delete_path);
        delete_dir.removeRecursively();
    }

    // 删除item
    if(delete_item == _active_item){
        _active_item = nullptr;
    }

    // 判断右键的item是否为展示图片的项目item

    // 转化_selected_item
    auto* pro_tree_item_select = dynamic_cast<ProTreeWidgetItem*>(_selected_item);

    if(pro_tree_item_select && delete_item == pro_tree_item_select->getRoot()){
        _selected_item = nullptr;
        emit SigClearItem();
    }


    delete this->takeTopLevelItem(idx);

    _rightclicked_item = nullptr;

}

// 轮播图
void ProTreeWidget::SlotSlideShow()
{
    if(!_rightclicked_item){
        return;
    }

    auto* pro_tree_item = dynamic_cast<ProTreeWidgetItem*>(_rightclicked_item);

    // 获取第一张和最后一张图片
    ProTreeWidgetItem* first_item = pro_tree_item->getFirstItem();
    ProTreeWidgetItem* last_item = pro_tree_item->getLastItem();

    _slide_show_dialog = std::make_shared<SlideShowDialog>(first_item,last_item,this);
    // 设为模态
    _slide_show_dialog->setModal(true);

    // 最大化显示
    _slide_show_dialog->showMaximized();
}

// 双击
void ProTreeWidget::SlotUpdateItem(QTreeWidgetItem *DoubleClickedItem, int column)
{
    Q_UNUSED(column);
    // 是否是左键双击
    if(QGuiApplication::mouseButtons() != Qt::LeftButton){
        return;
    }

    // item是否为空
    if(DoubleClickedItem == nullptr){
        return;
    }

    // 记录选中的item
    _selected_item = DoubleClickedItem;

    auto* ProTreeItem = dynamic_cast<ProTreeWidgetItem*>(DoubleClickedItem);

    // 判断类型是否为图片
    if(ProTreeItem->type() == TreeItemPic){
        // 发送信号到picshow
        emit SigUpdateItem(ProTreeItem->getPath());
    }
}

// 上一张图片
void ProTreeWidget::SlotPrePic()
{
    if(_selected_item == nullptr){
        return;
    }

    auto* pro_tree_item = dynamic_cast<ProTreeWidgetItem*>(_selected_item);

    // 获取前一个item
    auto* pre_item = pro_tree_item->getPreItem();

    if(!pre_item){
        return;
    }
    _selected_item = pre_item;
    this->setCurrentItem(pre_item);

    if(pre_item != nullptr){
        emit SigUpdateItem(pre_item->getPath());
    }
}

// 下一张图片
void ProTreeWidget::SlotNextPic()
{

    if(_selected_item == nullptr){
        return;
    }

    auto* pro_tree_item = dynamic_cast<ProTreeWidgetItem*>(_selected_item);

    // 获取前一个item
    auto* next_item = pro_tree_item->getNextItem();

    if(!next_item){
        return;
    }
    _selected_item = next_item;
    this->setCurrentItem(next_item);


    if(next_item != nullptr){
        emit SigUpdateItem(next_item->getPath());
    }
}

// 设置音乐
void ProTreeWidget::SlotSetMusic()
{
    QStringList musics = QFileDialog::getOpenFileNames(this,tr("选择背景音乐"),QDir::currentPath(),"musics (*.mp3)");

    if(musics.empty()) return;

    for(auto music : musics){
        _music_list->addMedia(QUrl::fromLocalFile(music));
    }
}

// 播放音乐
void ProTreeWidget::SlotPlayMusic(bool isPlay)
{
    qDebug() << "music isPlay: " << isPlay;
    if(!_music_player){
        return ;
    }
    qDebug() << "music play";
    qDebug() << _music_list;
    if(isPlay)
        _music_player->play();
    else
        _music_player->pause();
}
