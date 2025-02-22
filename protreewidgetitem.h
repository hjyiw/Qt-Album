#ifndef PROTREEWIDGETITEM_H
#define PROTREEWIDGETITEM_H

#include <QTreeWidget>
#include <QTreeWidgetItem>

class ProTreeWidgetItem : public QTreeWidgetItem
{
public:
    // 项目item
    ProTreeWidgetItem(QTreeWidget *treeview, const QString& name,
                    const QString& path, int type = Type);

    // 子item
    ProTreeWidgetItem(QTreeWidgetItem *parent, QTreeWidgetItem *root ,
                    const QString& name, const QString& path, int type = Type);

private:
    QString _name;
    QString _path;
    QTreeWidgetItem* _root;
    QTreeWidgetItem* _pre_item;
    QTreeWidgetItem* _next_item;

signals:

public:
    QString& getPath();
    ProTreeWidgetItem* getRoot();
    ProTreeWidgetItem* getPreItem();
    ProTreeWidgetItem* getNextItem();
    QString& getName();
    ProTreeWidgetItem* getFirstItem();
    ProTreeWidgetItem* getLastItem();

    void setRoot(QTreeWidgetItem* item);
    void setPreItem(QTreeWidgetItem* item);
    void setNextItem(QTreeWidgetItem* item);
};

#endif // PROTREEWIDGETITEM_H
