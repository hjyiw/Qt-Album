/********************************************************************************
** Form generated from reading UI file 'comfirmpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMFIRMPAGE_H
#define UI_COMFIRMPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_ComfirmPage
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWizardPage *ComfirmPage)
    {
        if (ComfirmPage->objectName().isEmpty())
            ComfirmPage->setObjectName(QString::fromUtf8("ComfirmPage"));
        ComfirmPage->resize(397, 300);
        gridLayout = new QGridLayout(ComfirmPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ComfirmPage);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ComfirmPage);

        QMetaObject::connectSlotsByName(ComfirmPage);
    } // setupUi

    void retranslateUi(QWizardPage *ComfirmPage)
    {
        ComfirmPage->setWindowTitle(QCoreApplication::translate("ComfirmPage", "WizardPage", nullptr));
        label->setText(QCoreApplication::translate("ComfirmPage", "\347\202\271\345\207\273\345\256\214\346\210\220\357\274\214\345\256\214\346\210\220\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComfirmPage: public Ui_ComfirmPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMFIRMPAGE_H
