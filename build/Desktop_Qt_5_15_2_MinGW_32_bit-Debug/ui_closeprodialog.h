/********************************************************************************
** Form generated from reading UI file 'closeprodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSEPRODIALOG_H
#define UI_CLOSEPRODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CloseProDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QCheckBox *cbDelete;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CloseProDialog)
    {
        if (CloseProDialog->objectName().isEmpty())
            CloseProDialog->setObjectName(QString::fromUtf8("CloseProDialog"));
        CloseProDialog->resize(301, 205);
        verticalLayout_3 = new QVBoxLayout(CloseProDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, -1, -1, -1);
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(CloseProDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        cbDelete = new QCheckBox(CloseProDialog);
        cbDelete->setObjectName(QString::fromUtf8("cbDelete"));

        verticalLayout->addWidget(cbDelete);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        widget = new QWidget(CloseProDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout_2->addWidget(widget);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(CloseProDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CloseProDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CloseProDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CloseProDialog);
    } // setupUi

    void retranslateUi(QDialog *CloseProDialog)
    {
        CloseProDialog->setWindowTitle(QCoreApplication::translate("CloseProDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CloseProDialog", "\346\230\257\345\220\246\345\205\263\351\227\255\345\275\223\345\211\215\351\241\271\347\233\256\357\274\237", nullptr));
        cbDelete->setText(QCoreApplication::translate("CloseProDialog", "\345\220\214\346\227\266\345\210\240\351\231\244\351\241\271\347\233\256\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CloseProDialog: public Ui_CloseProDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSEPRODIALOG_H
