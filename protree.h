#ifndef PROTREE_H
#define PROTREE_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QTreeWidget>
#include "protreewidget.h"
#include "protreewidgetitem.h"
#include <QSet>
#include "openprothread.h"
class ProTree : public QDialog
{
    Q_OBJECT
public:
    explicit ProTree(QWidget *parent = nullptr);
    ProTreeWidget* getProTreeWidget();

private:
    QLabel* lblProTree;
    ProTreeWidget* twProTree;
    QSet<QString> _path_set;
    std::shared_ptr<OpenProThread> _open_pro_thread; // 打开已存在目录的线程

public slots:
    void SlotAddProToTree(QString name, QString path);
    void SlotOpenPro(QString dirName);

signals:

public:
    QSet<QString>& getPathSet();

};

#endif // PROTREE_H
