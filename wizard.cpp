#include "wizard.h"
#include "ui_wizard.h"
#include <QDebug>
Wizard::Wizard(QWidget *parent)
    : QWizard(parent)
    , ui(new Ui::Wizard)
{
    ui->setupUi(this);
}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::done(int result)
{
    // 取消
    if(result == QDialog::Rejected){
        return QWizard::done(result);
    }

    QString name = field("name").toString();
    QString path = field("path").toString();
    qDebug() << "name : " << name;
    qDebug() << "path : " << path;
    emit SigProSettings(name,path);

    return QWizard::done(result);

}
