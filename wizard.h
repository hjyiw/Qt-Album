﻿#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>

namespace Ui {
class Wizard;
}

class Wizard : public QWizard
{
    Q_OBJECT

public:
    explicit Wizard(QWidget *parent = nullptr);
    ~Wizard();

private:
    Ui::Wizard *ui;

protected:
    void done(int result) override;

signals:
    void SigProSettings(QString name,QString path);
};

#endif // WIZARD_H
