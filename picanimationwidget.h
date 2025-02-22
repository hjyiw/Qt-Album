#ifndef PICANIMATIONWIDGET_H
#define PICANIMATIONWIDGET_H

#include <QTimer>
#include <QWidget>
#include <QTreeWidgetItem>
#include <QMap>

class PicAnimationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PicAnimationWidget(QWidget *parent = nullptr);
    ~PicAnimationWidget();

    void setPixMap(QTreeWidgetItem* cur_item);

    void animationStart();

private:
    bool _isStart;
    double _factor;

    QPixmap _pixmap1;
    QPixmap _pixmap2;

    QTimer* _timer;

    QTreeWidgetItem* _cur_item; // 当前item

    QMap<QString,QTreeWidgetItem*> _map_item;

private:

    void animationStop();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
private slots:
    void SlotTimerOut();

public slots:
    void SlotNextPic();
    void SlotPrePic();
    void SlotUpdatePic(QString path);
    void SlotPlayOrPause();
signals:
    void SigUpList(QTreeWidgetItem*);
    void SigSelectedItem(QTreeWidgetItem*);
    void SigPalyChanged(bool);
    void SigMusicStartOrStop(bool);
};

#endif // PICANIMATIONWIDGET_H
