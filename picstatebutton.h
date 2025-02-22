#ifndef PICSTATEBUTTON_H
#define PICSTATEBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QEvent>

class PicStateButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PicStateButton(QWidget *parent = nullptr);
    void setIcons(const QString& normal_play_icon, const QString& hover_play_icon,
                  const QString& press_play_icon,const QString& normal_stop_icon,
                  const QString& hover_stop_icon,const QString& press_stop_icon);

private:
    QString _normal_play_icon;
    QString _hover_play_icon;
    QString _press_play_icon;
    QString _normal_stop_icon;
    QString _hover_stop_icon;
    QString _press_stop_icon;

    QPixmap _pixmap;

    bool _isPlay;

private:
    void setNormal();
    void setHover();
    void setPress();

public:

protected:
    virtual bool event(QEvent *e) override;

public slots:
    void SlotPlayChanged(bool isStart);

signals:
};

#endif // PICSTATEBUTTON_H
