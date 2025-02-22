#include "protree.h"
#include <QVBoxLayout>
#include <QDir>
#include <QDebug>
#include "const.h"
#include <QMessageBox>
ProTree::ProTree(QWidget *parent)
    : QDialog{parent},_open_pro_thread(nullptr)
{
    this->setMinimumWidth(220);
    this->setMaximumWidth(220);
    this->setContentsMargins(5,5,5,5);
    lblProTree = new QLabel(this);
    lblProTree->setObjectName("lblProTree");
    lblProTree->setText("目录结构");
    twProTree = new ProTreeWidget(this);
    QVBoxLayout* vlayout_main = new QVBoxLayout();
    vlayout_main->setContentsMargins(0,0,0,0);
    vlayout_main->addWidget(lblProTree);
    vlayout_main->addWidget(twProTree);
    this->setLayout(vlayout_main);

}

// 创建项目
void ProTree::SlotAddProToTree(QString name, QString path)
{
    QDir dir(path);
    QString file_path = dir.absoluteFilePath(name);


    // 判断创建的项目是否重名 相当于缓存
    if(_path_set.find(file_path) != _path_set.end()){
        qDebug() << "pro had been loaded";
        return;
    }

    // 项目目录
    QDir pro_dir(file_path);
    if(pro_dir.exists()){
        qDebug() << "pro has exist";
        return;
    }
    // 递归创建
    bool enable = pro_dir.mkpath(file_path);
    if(!enable){
        qDebug() << "mkpath fail!";
        return;
    }


    // 添加到目录树
    auto* item = new ProTreeWidgetItem(twProTree,name,file_path,TreeItemPro);
    item->setData(0,Qt::DisplayRole,name);
    item->setData(0,Qt::DecorationRole,QIcon(":/icon/icon/dir.png"));
    item->setData(0,Qt::ToolTipRole,file_path);


    // 记录项目
    _path_set.insert(file_path);

}

// 打开已存在项目
void ProTree::SlotOpenPro(QString dirName)
{
    // 如果_path_set中已存在改文件
    if(_path_set.find(dirName) != _path_set.end()){
        QMessageBox::warning(this,tr("打开项目"),tr("改项目已存在！"));
        return;
    }

    int file_cnt = 0;
    _open_pro_thread = std::make_shared<OpenProThread>(dirName,twProTree,std::ref(file_cnt),this);

    connect(_open_pro_thread.get(),&OpenProThread::SigOpenFinish,this,[=](){
        _path_set.insert(dirName);
    });
    _open_pro_thread->start();
}

QSet<QString> &ProTree::getPathSet()
{
    return _path_set;
}

ProTreeWidget *ProTree::getProTreeWidget()
{
    return twProTree;
}
