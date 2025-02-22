/********************************************************************************
** Form generated from reading UI file 'slideshowdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDESHOWDIALOG_H
#define UI_SLIDESHOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "picanimationwidget.h"
#include "picbutton.h"
#include "piclistwidget.h"
#include "picstatebutton.h"

QT_BEGIN_NAMESPACE

class Ui_SlideShowDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *PicWidget;
    QGridLayout *gridLayout;
    QWidget *PreWidget;
    QHBoxLayout *horizontalLayout_5;
    PicButton *btnPre;
    QHBoxLayout *horizontalLayout_2;
    PicStateButton *btnPlay;
    PicButton *btnClose;
    PicAnimationWidget *PicShowWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *NextWidget;
    QHBoxLayout *horizontalLayout_4;
    PicButton *btnNext;
    QWidget *SlideWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *Widget;
    PicListWidget *lwSlide;

    void setupUi(QDialog *SlideShowDialog)
    {
        if (SlideShowDialog->objectName().isEmpty())
            SlideShowDialog->setObjectName(QString::fromUtf8("SlideShowDialog"));
        SlideShowDialog->resize(488, 381);
        verticalLayout_4 = new QVBoxLayout(SlideShowDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        PicWidget = new QWidget(SlideShowDialog);
        PicWidget->setObjectName(QString::fromUtf8("PicWidget"));
        gridLayout = new QGridLayout(PicWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        PreWidget = new QWidget(PicWidget);
        PreWidget->setObjectName(QString::fromUtf8("PreWidget"));
        PreWidget->setMinimumSize(QSize(90, 0));
        PreWidget->setMaximumSize(QSize(90, 16777215));
        horizontalLayout_5 = new QHBoxLayout(PreWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, 9, 9, 9);
        btnPre = new PicButton(PreWidget);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));

        horizontalLayout_5->addWidget(btnPre);


        gridLayout->addWidget(PreWidget, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnPlay = new PicStateButton(PicWidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));

        horizontalLayout_2->addWidget(btnPlay);

        btnClose = new PicButton(PicWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(40, 24));

        horizontalLayout_2->addWidget(btnClose);


        gridLayout->addLayout(horizontalLayout_2, 0, 2, 1, 1);

        PicShowWidget = new PicAnimationWidget(PicWidget);
        PicShowWidget->setObjectName(QString::fromUtf8("PicShowWidget"));
        horizontalLayout_3 = new QHBoxLayout(PicShowWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, -1);

        gridLayout->addWidget(PicShowWidget, 1, 1, 1, 1);

        NextWidget = new QWidget(PicWidget);
        NextWidget->setObjectName(QString::fromUtf8("NextWidget"));
        NextWidget->setMinimumSize(QSize(90, 0));
        NextWidget->setMaximumSize(QSize(90, 16777215));
        horizontalLayout_4 = new QHBoxLayout(NextWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnNext = new PicButton(NextWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));

        horizontalLayout_4->addWidget(btnNext);


        gridLayout->addWidget(NextWidget, 1, 2, 1, 1);


        verticalLayout_4->addWidget(PicWidget);

        SlideWidget = new QWidget(SlideShowDialog);
        SlideWidget->setObjectName(QString::fromUtf8("SlideWidget"));
        SlideWidget->setMinimumSize(QSize(0, 120));
        SlideWidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(SlideWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Widget = new QWidget(SlideWidget);
        Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setMinimumSize(QSize(0, 120));
        Widget->setMaximumSize(QSize(16777215, 120));
        lwSlide = new PicListWidget(Widget);
        lwSlide->setObjectName(QString::fromUtf8("lwSlide"));
        lwSlide->setGeometry(QRect(5, 5, 16777215, 110));
        lwSlide->setMinimumSize(QSize(0, 110));
        lwSlide->setMaximumSize(QSize(16777215, 110));

        horizontalLayout->addWidget(Widget);


        verticalLayout_4->addWidget(SlideWidget);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 1);

        retranslateUi(SlideShowDialog);

        QMetaObject::connectSlotsByName(SlideShowDialog);
    } // setupUi

    void retranslateUi(QDialog *SlideShowDialog)
    {
        SlideShowDialog->setWindowTitle(QCoreApplication::translate("SlideShowDialog", "Dialog", nullptr));
        btnPre->setText(QString());
        btnPlay->setText(QString());
        btnClose->setText(QString());
        btnNext->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SlideShowDialog: public Ui_SlideShowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDESHOWDIALOG_H
