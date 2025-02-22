#include "protreewidgetitem.h"
#include "const.h"

ProTreeWidgetItem::ProTreeWidgetItem(QTreeWidget *treeview, const QString &name,
                                     const QString &path, int type)
    : QTreeWidgetItem(treeview,type),_name(name),_path(path),_root(this),_pre_item(nullptr),_next_item(nullptr)
{

}

ProTreeWidgetItem::ProTreeWidgetItem(QTreeWidgetItem *parent, QTreeWidgetItem *root,
                                   const QString &name, const QString &path, int type)
    :QTreeWidgetItem(parent,type),_name(name),_path(path),_root(root),_pre_item(nullptr),_next_item(nullptr)
{

}

QString &ProTreeWidgetItem::getPath()
{
    return _path;
}

ProTreeWidgetItem *ProTreeWidgetItem::getRoot()
{
    return dynamic_cast<ProTreeWidgetItem*>(_root);
}

ProTreeWidgetItem *ProTreeWidgetItem::getPreItem()
{
    return dynamic_cast<ProTreeWidgetItem*>(_pre_item);
}

ProTreeWidgetItem *ProTreeWidgetItem::getNextItem()
{
    return dynamic_cast<ProTreeWidgetItem*>(_next_item);
}

QString &ProTreeWidgetItem::getName()
{
    return _name;
}

// 获取第一张照片
ProTreeWidgetItem *ProTreeWidgetItem::getFirstItem()
{
    // 获取子节点数量
    int childCnt = this-> childCount();

    // 从前往后遍历
    for(int i = 0;i < childCnt;i++){
        auto* item = this->child(i);

        auto* tree_item = dynamic_cast<ProTreeWidgetItem*>(item);

        // 是图片
        if(tree_item->type() == TreeItemPic){
            return tree_item;
        }

        // 是目录
        auto* first_item = tree_item->getFirstItem();

        // 没找到就继续找
        if(!first_item){
            continue;
        }

        return first_item;

    }

    return nullptr;


}

// 获取最后一张照片
ProTreeWidgetItem *ProTreeWidgetItem::getLastItem()
{
    // 获取子节点个数
    int childCnt = this->childCount();

    // 从后往前找
    for(int i = childCnt - 1;i >= 0;i++){
        auto* sub_item = this->child(i);
        // 转化
        auto* tree_sub_item = dynamic_cast<ProTreeWidgetItem*>(sub_item);

        // 如果是图片
        if(tree_sub_item->type() == TreeItemPic){
            return tree_sub_item;
        }

        // 是目录
        auto* last_item = tree_sub_item->getLastItem();

        // 没找到继续找
        if(last_item == nullptr){
            continue;
        }

        return last_item;
    }

    return nullptr;
}

void ProTreeWidgetItem::setRoot(QTreeWidgetItem *item)
{
    _root = item;
}

void ProTreeWidgetItem::setPreItem(QTreeWidgetItem *item)
{
    _pre_item = item;
}

void ProTreeWidgetItem::setNextItem(QTreeWidgetItem *item)
{
    _next_item = item;
}



