#ifndef PICLISTITEM_H
#define PICLISTITEM_H

#include <QListWidgetItem>

class PicListItem : public QListWidgetItem
{
public:
    explicit PicListItem(const int idx,const QIcon &icon, const QString &text,
                         QListWidget *listview = nullptr, int type = Type);
    QString getPath();
    int getIdx();
private:
    QString _path;
    int _idx;
signals:
};

#endif // PICLISTITEM_H
