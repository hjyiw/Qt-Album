#ifndef CLOSEPRODIALOG_H
#define CLOSEPRODIALOG_H

#include <QDialog>

namespace Ui {
class CloseProDialog;
}

class CloseProDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CloseProDialog(QWidget *parent = nullptr);
    ~CloseProDialog();

    bool isDelete();

private:
    Ui::CloseProDialog *ui;
};

#endif // CLOSEPRODIALOG_H
