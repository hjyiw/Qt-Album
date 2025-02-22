#include "picbutton.h"
#include <QPixmap>
#include <QDebug>
PicButton::PicButton(QWidget *parent)
    : QPushButton{parent}
{
}

void PicButton::setIcons(QString normal_icon, QString hover_icon, QString press_icon)
{
    _normal_icon = normal_icon;
    _hover_icon = hover_icon;
    _press_icon = press_icon;

    QPixmap pixmap;
    pixmap.load(normal_icon);
    QPixmap scaledPix = pixmap.scaled(this->size(),
                                      Qt::KeepAspectRatio, // Qt::KeepAspectRatio参数保证图像宽高比不变
                                      Qt::SmoothTransformation);
    this->setIcon(scaledPix);
    this->setIconSize(this->size());
}

void PicButton::setNormalIcon()
{
    QPixmap pixmap;
    pixmap.load(_normal_icon);
    QPixmap scaledPix = pixmap.scaled(this->size(),
                                      Qt::KeepAspectRatio, // Qt::KeepAspectRatio参数保证图像宽高比不变
                                      Qt::SmoothTransformation);
    this->setIcon(scaledPix);
    this->setIconSize(this->size());

}

void PicButton::setHoverIcon()
{
    QPixmap pixmap;
    pixmap.load(_hover_icon);
    QPixmap scaledPix = pixmap.scaled(this->size(),
                                      Qt::KeepAspectRatio, // Qt::KeepAspectRatio参数保证图像宽高比不变
                                      Qt::SmoothTransformation);
    this->setIcon(scaledPix);
    this->setIconSize(this->size());
}

void PicButton::setPressIcon()
{
    QPixmap pixmap;
    pixmap.load(_press_icon);
    QPixmap scaledPix = pixmap.scaled(this->size(),
                                      Qt::KeepAspectRatio, // Qt::KeepAspectRatio参数保证图像宽高比不变
                                      Qt::SmoothTransformation); // 在缩放图像时启用高质量插值算法，减少锯齿（Aliasing）和像素化现象
    this->setIcon(scaledPix);
    this->setIconSize(this->size());
}

bool PicButton::event(QEvent *e)
{
    switch(e->type()){
        case QEvent::Enter:
            setHoverIcon();
            break;
        case QEvent::Leave:
            setNormalIcon();
            break;
        case QEvent::MouseButtonPress:
            setPressIcon();
            break;
        default:
            break;
    }
    return QPushButton::event(e);
}
