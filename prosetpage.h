#ifndef PROSETPAGE_H
#define PROSETPAGE_H

#include <QWizardPage>

namespace Ui {
class ProSetPage;
}

class ProSetPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ProSetPage(QWidget *parent = nullptr);
    ~ProSetPage();

private:
    Ui::ProSetPage *ui;

protected:
    virtual bool isComplete() const override;
private slots:
    void on_btnBrowse_clicked();
};

#endif // PROSETPAGE_H
