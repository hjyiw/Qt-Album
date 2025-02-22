/********************************************************************************
** Form generated from reading UI file 'prosetpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROSETPAGE_H
#define UI_PROSETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_ProSetPage
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lePath;
    QLineEdit *leName;
    QLabel *lblPath;
    QLabel *lblName;
    QPushButton *btnBrowse;
    QLabel *lblTips;

    void setupUi(QWizardPage *ProSetPage)
    {
        if (ProSetPage->objectName().isEmpty())
            ProSetPage->setObjectName(QString::fromUtf8("ProSetPage"));
        ProSetPage->resize(586, 431);
        gridLayout_2 = new QGridLayout(ProSetPage);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lePath = new QLineEdit(ProSetPage);
        lePath->setObjectName(QString::fromUtf8("lePath"));

        gridLayout->addWidget(lePath, 2, 2, 1, 1);

        leName = new QLineEdit(ProSetPage);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 0, 2, 1, 1);

        lblPath = new QLabel(ProSetPage);
        lblPath->setObjectName(QString::fromUtf8("lblPath"));

        gridLayout->addWidget(lblPath, 2, 1, 1, 1);

        lblName = new QLabel(ProSetPage);
        lblName->setObjectName(QString::fromUtf8("lblName"));

        gridLayout->addWidget(lblName, 0, 1, 1, 1);

        btnBrowse = new QPushButton(ProSetPage);
        btnBrowse->setObjectName(QString::fromUtf8("btnBrowse"));

        gridLayout->addWidget(btnBrowse, 2, 3, 1, 1);

        lblTips = new QLabel(ProSetPage);
        lblTips->setObjectName(QString::fromUtf8("lblTips"));

        gridLayout->addWidget(lblTips, 3, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ProSetPage);

        QMetaObject::connectSlotsByName(ProSetPage);
    } // setupUi

    void retranslateUi(QWizardPage *ProSetPage)
    {
        ProSetPage->setWindowTitle(QCoreApplication::translate("ProSetPage", "WizardPage", nullptr));
        lblPath->setText(QCoreApplication::translate("ProSetPage", "Path:", nullptr));
        lblName->setText(QCoreApplication::translate("ProSetPage", "name:", nullptr));
        btnBrowse->setText(QCoreApplication::translate("ProSetPage", "browse", nullptr));
        lblTips->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProSetPage: public Ui_ProSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROSETPAGE_H
