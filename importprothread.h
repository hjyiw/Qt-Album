#ifndef IMPORTPROTHREAD_H
#define IMPORTPROTHREAD_H

#include <QThread>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <Qmutex>

class ImportProThread : public QThread
{
    Q_OBJECT
public:
    explicit ImportProThread(const QString& src_path, const QString& dest_path,
                            int file_count, QTreeWidgetItem* parent_item,
                            QTreeWidgetItem* root, QTreeWidget* self, QWidget* parent = nullptr);

    ~ImportProThread();
protected:
    virtual void run() override;

private:
    QString _src_path; // 原路径
    QString _dest_path; // 目标路径
    int _file_count; // 文件数目
    QTreeWidgetItem* _parent_item; // 父节点
    QTreeWidgetItem* _root; // 根节点
    QTreeWidget* _self; // 所在的TreeWidget
    bool _bstop; // 判断导入停止
    QTreeWidgetItem* _pre_item = nullptr; // 记录前一个item
    QMutex _pre_item_mutex; // 加锁

signals:
    void SigUpdateProg(int,QString);
    void SigOkProg(int);
private:
    void CreateProTree(const QString& src_path, const QString& dest_path,
                        int& file_count,QTreeWidgetItem* parent_item,QTreeWidgetItem* root,
                        QTreeWidget* self);

public slots:
    void SlotCancelProg();
};

#endif // IMPORTPROTHREAD_H
