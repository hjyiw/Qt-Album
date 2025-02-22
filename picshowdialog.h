#ifndef PICSHOWDIALOG_H
#define PICSHOWDIALOG_H

#include <QDialog>
#include <QEvent>
#include <QPropertyAnimation> // 属性动画
#include <QPixmap>

namespace Ui {
class PicShowDialog;
}

class PicShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PicShowDialog(QWidget *parent = nullptr);
    ~PicShowDialog();

private:
    Ui::PicShowDialog *ui;
    QPropertyAnimation* _animation_pre; // 属性动画
    QPropertyAnimation* _animation_next;

    bool _isVisible; // 前后切换是否可见

    // 缓存图片
    QPixmap _pixmap;
    QString _selected_path;

private:
    void showPreNextBtns(bool isShow);

public:
    void ReSizePix(const int& w,const int& h);

protected:
    virtual bool event(QEvent *e);


public slots:
    void SlotShowPic(const QString& pic_path);
    void SlotClearItem();

signals:
    void SigPreClicked();
    void SigNextClicked();
};

#endif // PICSHOWDIALOG_H
