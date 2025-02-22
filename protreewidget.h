#ifndef PROTREEWIDGET_H
#define PROTREEWIDGET_H

#include <QTreeWidget>
#include <QAction>
#include <QProgressDialog>
#include "importprothread.h"
#include <QSet>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class SlideShowDialog;

class ProTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit ProTreeWidget(QWidget *parent = nullptr);

signals:

private:
    QTreeWidgetItem * _rightclicked_item; // 右键的item
    QTreeWidgetItem * _active_item; // 活动项目

    QAction* _action_import;
    QAction* _action_close;
    QAction* _action_setstart;
    QAction* _action_slideshow;

    // 记录文件
    QSet<QString> _file_set;
    // 进度条
    QProgressDialog* _import_prog;

    // 导入项目线程
    std::shared_ptr<ImportProThread> _thread_import_pro;

    // 记录点击的item
    QTreeWidgetItem* _selected_item;

    // 轮播图
    std::shared_ptr<SlideShowDialog> _slide_show_dialog;

    // 音乐播放器
    QMediaPlayer* _music_player;
    QMediaPlaylist* _music_list;

private slots:
    void SlotItemClicked(QTreeWidgetItem *item, int column);
    void SlotImport();
    void SlotUpdateProg(int file_count, QString added_name);
    void SlotOkProg(int file_count);
    void SlotCancelProg();
    void SlotSetStart();
    void SlotClose();
    void SlotSlideShow();
    void SlotUpdateItem(QTreeWidgetItem *DoubleClickedItem, int column);

public slots:
    void SlotPrePic();
    void SlotNextPic();
    void SlotSetMusic();
    void SlotPlayMusic(bool isPlay);


signals:
    void SigCancelProg();
    void SigUpdateItem(const QString& pic_path);
    void SigClearItem();

};

#endif // PROTREEWIDGET_H
