#include "openprothread.h"
#include "protreewidgetitem.h"
#include "const.h"
#include <QDir>
#include <QDebug>
#include <QCollator>
#include <algorithm>
#include "myalgorithm.h"
OpenProThread::OpenProThread(QString src_path, QTreeWidget* self, int& file_cnt,QWidget *parent)
    : QThread{parent},_src_path(src_path),_root(nullptr),_self(self),_file_cnt(file_cnt),_isStop(false)
{}

// 创建项目item
void OpenProThread::OpenProTree(QString src_path, int &file_cnt, QTreeWidget *self)
{
    QDir open_dir(src_path);
    _pre_item = nullptr;
    // 创建项目item
    QMetaObject::invokeMethod(self,[=]() mutable{
        auto* item = new ProTreeWidgetItem(self,open_dir.dirName(),src_path,TreeItemPro);
        item->setData(0,Qt::DisplayRole,open_dir.dirName());
        item->setData(0,Qt::DecorationRole,QIcon(":/icon/icon/dir.png"));
        item->setData(0,Qt::ToolTipRole,src_path);

        // 设置整个项目的根item
        _root = item;

        RecursiveProTree(src_path,file_cnt,_root,self,item);

    },Qt::QueuedConnection);

    if(!_isStop){
        emit SigOpenFinish();
    }

}


// 构建目录树
void OpenProThread::RecursiveProTree(QString _src_path, int &file_cnt, QTreeWidgetItem *root,
                                     QTreeWidget *self, QTreeWidgetItem *parent)
{
    // qDebug() << "preItem: " << _pre_item;
    QDir src_dir(_src_path);
    src_dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);

    // 过滤后的文件集合
    auto infoList = src_dir.entryInfoList();
    // 排序
    std::sort(infoList.begin(), infoList.end(), dirSort);

    // 遍历每一个文件
    for(auto& fileInfo : infoList){

        bool isDir = fileInfo.isDir();

        // 判断是否是文件夹
        if(isDir){
            // 文件数
            file_cnt++;
                auto* item = new ProTreeWidgetItem(parent,root,fileInfo.fileName(),fileInfo.absoluteFilePath(),TreeItemDir);
                item->setData(0,Qt::DisplayRole,fileInfo.fileName());
                item->setData(0,Qt::DecorationRole,QIcon(":/icon/icon/dir.png"));
                item->setData(0,Qt::ToolTipRole,fileInfo.absolutePath());

                // 递归生成子文件夹下的文件
                RecursiveProTree(fileInfo.absoluteFilePath(), file_cnt, root, self, item);

                // 生成后就移除
                infoList.removeOne(fileInfo);
        }
        else{
            // 判断后缀
            const QString& suffix = fileInfo.completeSuffix();
            if(suffix != "jpg" && suffix != "jpeg" && suffix != "png"){
                continue;
            }

            file_cnt++;

            QMetaObject::invokeMethod(self, [=]() mutable{
                auto* item = new ProTreeWidgetItem(parent,root,fileInfo.fileName(),fileInfo.absoluteFilePath(),TreeItemPic);
                item->setData(0,Qt::DisplayRole,fileInfo.fileName());
                item->setData(0,Qt::DecorationRole,QIcon(":/icon/icon/pic.png"));
                item->setData(0,Qt::ToolTipRole,fileInfo.absolutePath());

                QMutexLocker locker(&_pre_item_mutex); // 上锁

                if(_pre_item != nullptr){
                    ProTreeWidgetItem* pre_tree_item = dynamic_cast<ProTreeWidgetItem*>(_pre_item);
                    pre_tree_item->setNextItem(item);

                    // qDebug() << pre_tree_item->getName() << " next -> " << item->getName();
                    // qDebug() << item->getName() << " pre -> " << pre_tree_item->getName();
                }
                item->setPreItem(_pre_item);

                // if(_pre_item == nullptr)
                //     qDebug() << item->getName() << " pre -> nullptr";
                _pre_item = item;

                // locker析构自动解锁

            }, Qt::QueuedConnection);

            // 添加完就移除
            infoList.removeOne(fileInfo);
        }

    }

}

void OpenProThread::run()
{
    OpenProTree(_src_path,_file_cnt,_self);
}
