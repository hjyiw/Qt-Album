#include "closeprodialog.h"
#include "ui_closeprodialog.h"

CloseProDialog::CloseProDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CloseProDialog)
{
    ui->setupUi(this);
}

CloseProDialog::~CloseProDialog()
{
    delete ui;
}

bool CloseProDialog::isDelete()
{
    return ui->cbDelete->isChecked();
}
