#ifndef OPENPROTHREAD_H
#define OPENPROTHREAD_H

#include <QThread>
#include "protreewidget.h"
#include <QMutex>
class OpenProThread : public QThread
{
    Q_OBJECT
public:
    explicit OpenProThread(QString src_path, QTreeWidget* self, int& file_cnt,QWidget *parent = nullptr);

private:
    QString _src_path;
    QTreeWidgetItem* _root;
    QTreeWidget* _self;
    int _file_cnt;
    bool _isStop;

    // 添加互斥锁
    QMutex _pre_item_mutex;
    // 记录前一个item
    QTreeWidgetItem* _pre_item = nullptr;
signals:
    void SigOpenFinish();

private:
    void OpenProTree(QString src_path,int& file_cnt, QTreeWidget* self);
    void RecursiveProTree(QString _src_path,int& file_cnt, QTreeWidgetItem* root,
                          QTreeWidget* self, QTreeWidgetItem* parent);
protected:
    virtual void run() override;
};

#endif // OPENPROTHREAD_H
