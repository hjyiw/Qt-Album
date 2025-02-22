#include "picstatebutton.h"

PicStateButton::PicStateButton(QWidget *parent)
    : QPushButton{parent},_isPlay(true) // 默认播放
{}

void PicStateButton::setIcons(const QString &normal_play_icon, const QString &hover_play_icon,
                              const QString &press_play_icon, const QString &normal_stop_icon,
                              const QString &hover_stop_icon, const QString &press_stop_icon)
{
    this->setFixedSize(40,30);

    _normal_play_icon = normal_play_icon;
    _hover_play_icon = hover_play_icon;
    _press_play_icon = press_play_icon;
    _normal_stop_icon = normal_stop_icon;
    _hover_stop_icon = hover_stop_icon;
    _press_stop_icon = press_stop_icon;

    _pixmap.load(_normal_stop_icon);
    _pixmap = _pixmap.scaled(this->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->setIcon(_pixmap);
    this->setIconSize(this->size());
}

void PicStateButton::setNormal()
{
    if(!_isPlay){
        _pixmap.load(_normal_play_icon);
    }
    else{
        _pixmap.load(_normal_stop_icon);
    }
    _pixmap = _pixmap.scaled(this->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->setIcon(_pixmap);
    this->setIconSize(this->size());
}

void PicStateButton::setHover()
{
    if(!_isPlay){
        _pixmap.load(_hover_play_icon);
    }
    else{
        _pixmap.load(_hover_stop_icon);
    }
    _pixmap = _pixmap.scaled(this->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->setIcon(_pixmap);
    this->setIconSize(this->size());
}

void PicStateButton::setPress()
{


    if(!_isPlay){
        _pixmap.load(_press_play_icon);
    }
    else{
        _pixmap.load(_press_stop_icon);
    }
    _pixmap = _pixmap.scaled(this->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->setIcon(_pixmap);
    this->setIconSize(this->size());
    // 更新状态
    _isPlay = !_isPlay;

}

bool PicStateButton::event(QEvent *e)
{
    switch(e->type()){
        case QEvent::Enter:
            setHover();
            break;
        case QEvent::Leave:
            setNormal();
            break;
        case QEvent::MouseButtonPress:
            setPress();
            break;
        case QEvent::MouseButtonRelease:
            setNormal();
            break;
        default:
            break;
    }
    return QPushButton::event(e);
}

// 播放状态切换
void PicStateButton::SlotPlayChanged(bool isStart)
{
    _isPlay = isStart;
    setNormal();
}



