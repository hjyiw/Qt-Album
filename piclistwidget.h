#ifndef PICLISTWIDGET_H
#define PICLISTWIDGET_H

#include <QListWidget>
#include <QTreeWidgetItem>
#include <QMap>

class PicListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit PicListWidget(QWidget *parent = nullptr);

    virtual ~PicListWidget();

private:
    void addPicItem(QString path);

private:
    QMap<QString,QListWidgetItem*> _pic_map;
    int _pic_cnt;
    QPoint _pos_origin;

    int _last_idx;
public slots:
    void SlotUpList(QTreeWidgetItem* item);
    void SlotSelectedItem(QTreeWidgetItem* item);

private slots:
    void SlotDoubleClicked(QListWidgetItem *item);
signals:
    SigDoubleClicked(QString path);
};

#endif // PICLISTWIDGET_H
