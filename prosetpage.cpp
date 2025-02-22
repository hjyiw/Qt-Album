#include "prosetpage.h"
#include "ui_prosetpage.h"
#include <QDir>
#include <QFileDialog>
#include <QDebug>
ProSetPage::ProSetPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::ProSetPage)
{
    ui->setupUi(this);

    // 给输入框进行域绑定
    registerField("path",ui->lePath);
    registerField("name*",ui->leName);

    // 编辑后发送completeChanged信号，自动调用isCompleted槽函数
    connect(ui->leName,&QLineEdit::textChanged,this,&ProSetPage::completeChanged);
    connect(ui->lePath,&QLineEdit::textChanged,this,&ProSetPage::completeChanged);

    // 默认当前路径
    ui->lePath->setText(QDir::currentPath());
    ui->lePath->setCursorPosition(ui->lePath->text().size()-1);

    // 打开lineEdit删除键
    ui->leName->setClearButtonEnabled(true);
    ui->lePath->setClearButtonEnabled(true);
}

ProSetPage::~ProSetPage()
{
    delete ui;
}

bool ProSetPage::isComplete() const
{
    // 判空
    if(ui->leName->text().isEmpty() || ui->lePath->text().isEmpty()){
        ui->lblTips->setText("Name or Path should not be empty!");
        return false;
    }

    // 判断路径是否存在
    QDir pathDir(ui->lePath->text());
    if(!pathDir.exists()){
        ui->lblTips->setText("path is not exist");
        return false;
    }

    // 判断当前路径下该文件是否存在
    QString absolutePath = pathDir.absoluteFilePath(ui->leName->text());
    // qDebug() << "absolute path: " << absolutePath;
    if(QDir(absolutePath).exists()){
        ui->lblTips->setText("project has exists, change path or name!");
        return false;
    }

    // 清空提示条
    ui->lblTips->setText("");
    return QWizardPage::isComplete();
}

void ProSetPage::on_btnBrowse_clicked()
{
    QString fileDirectory = QFileDialog::getExistingDirectory(this,"打开文件夹",QDir::currentPath());
    ui->lePath->setText(fileDirectory);
}

