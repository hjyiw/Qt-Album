QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    closeprodialog.cpp \
    comfirmpage.cpp \
    importprothread.cpp \
    main.cpp \
    mainwindow.cpp \
    myalgorithm.cpp \
    openprothread.cpp \
    picanimationwidget.cpp \
    picbutton.cpp \
    piclistitem.cpp \
    piclistwidget.cpp \
    picshowdialog.cpp \
    picstatebutton.cpp \
    prosetpage.cpp \
    protree.cpp \
    protreewidget.cpp \
    protreewidgetitem.cpp \
    slideshowdialog.cpp \
    wizard.cpp

HEADERS += \
    closeprodialog.h \
    comfirmpage.h \
    const.h \
    importprothread.h \
    mainwindow.h \
    myalgorithm.h \
    openprothread.h \
    picanimationwidget.h \
    picbutton.h \
    piclistitem.h \
    piclistwidget.h \
    picshowdialog.h \
    picstatebutton.h \
    prosetpage.h \
    protree.h \
    protreewidget.h \
    protreewidgetitem.h \
    slideshowdialog.h \
    wizard.h

FORMS += \
    closeprodialog.ui \
    comfirmpage.ui \
    mainwindow.ui \
    picshowdialog.ui \
    prosetpage.ui \
    slideshowdialog.ui \
    wizard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

RC_ICONS = "icon/bulm.ico"
