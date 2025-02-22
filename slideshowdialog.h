#ifndef SLIDESHOWDIALOG_H
#define SLIDESHOWDIALOG_H

#include <QDialog>
#include <QTreeWidget>

namespace Ui {
class SlideShowDialog;
}

class SlideShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SlideShowDialog(QTreeWidgetItem* firstItem,QTreeWidgetItem* lastItem,QWidget *parent = nullptr);
    ~SlideShowDialog();

private:
    Ui::SlideShowDialog *ui;
    QTreeWidgetItem* _first_item;
    QTreeWidgetItem* _last_item;

private slots:
    void SlotCloseClicked();
};

#endif // SLIDESHOWDIALOG_H
