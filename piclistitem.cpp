#include "piclistitem.h"

PicListItem::PicListItem(const int idx,const QIcon &icon, const QString &text,
                         QListWidget *listview, int type)
    : QListWidgetItem{icon,text,listview,type},_path(text),_idx(idx)
{}

QString PicListItem::getPath()
{
    return _path;
}

int PicListItem::getIdx()
{
    return _idx;
}
