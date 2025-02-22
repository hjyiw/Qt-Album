#ifndef PICBUTTON_H
#define PICBUTTON_H

#include <QPushButton>
#include <QIcon>
#include <QEvent>
class PicButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PicButton(QWidget *parent = nullptr);

    void setIcons(QString normal_icon, QString hover_icon, QString press_icon);

    void setNormalIcon();
    void setHoverIcon();
    void setPressIcon();
signals:

private:
    QString _normal_icon;
    QString _hover_icon;
    QString _press_icon;

protected:
    virtual bool event(QEvent *e);
};

#endif // PICBUTTON_H
