/********************************************************************************
** Form generated from reading UI file 'picshowdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICSHOWDIALOG_H
#define UI_PICSHOWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "picbutton.h"

QT_BEGIN_NAMESPACE

class Ui_PicShowDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QWidget *NextWidget;
    QHBoxLayout *horizontalLayout_3;
    PicButton *btnNext;
    QSpacerItem *verticalSpacer;
    QWidget *Prewidget;
    QHBoxLayout *horizontalLayout_2;
    PicButton *btnPre;
    QSpacerItem *horizontalSpacer;
    QLabel *lblPic;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PicShowDialog)
    {
        if (PicShowDialog->objectName().isEmpty())
            PicShowDialog->setObjectName(QString::fromUtf8("PicShowDialog"));
        PicShowDialog->resize(469, 358);
        horizontalLayout = new QHBoxLayout(PicShowDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        NextWidget = new QWidget(PicShowDialog);
        NextWidget->setObjectName(QString::fromUtf8("NextWidget"));
        NextWidget->setMinimumSize(QSize(80, 0));
        NextWidget->setMaximumSize(QSize(80, 16777215));
        horizontalLayout_3 = new QHBoxLayout(NextWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnNext = new PicButton(NextWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setMinimumSize(QSize(60, 50));
        btnNext->setMaximumSize(QSize(60, 50));

        horizontalLayout_3->addWidget(btnNext);


        gridLayout->addWidget(NextWidget, 1, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        Prewidget = new QWidget(PicShowDialog);
        Prewidget->setObjectName(QString::fromUtf8("Prewidget"));
        Prewidget->setMinimumSize(QSize(80, 0));
        Prewidget->setMaximumSize(QSize(80, 16777215));
        horizontalLayout_2 = new QHBoxLayout(Prewidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnPre = new PicButton(Prewidget);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));
        btnPre->setMinimumSize(QSize(60, 50));
        btnPre->setMaximumSize(QSize(60, 50));

        horizontalLayout_2->addWidget(btnPre);


        gridLayout->addWidget(Prewidget, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        lblPic = new QLabel(PicShowDialog);
        lblPic->setObjectName(QString::fromUtf8("lblPic"));

        gridLayout->addWidget(lblPic, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(PicShowDialog);

        QMetaObject::connectSlotsByName(PicShowDialog);
    } // setupUi

    void retranslateUi(QDialog *PicShowDialog)
    {
        PicShowDialog->setWindowTitle(QCoreApplication::translate("PicShowDialog", "Dialog", nullptr));
        btnNext->setText(QString());
        btnPre->setText(QString());
        lblPic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PicShowDialog: public Ui_PicShowDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICSHOWDIALOG_H
