#include "importprothread.h"

#include <QDir>
#include <QDebug>
#include "protreewidgetitem.h"
#include "const.h"
#include <QCollator>
#include <algorithm>
#include "myalgorithm.h"

ImportProThread::ImportProThread(const QString &src_path, const QString &dest_path,
                                 int file_count, QTreeWidgetItem *parent_item,
                                 QTreeWidgetItem *root, QTreeWidget *self, QWidget *parent)
    :QThread(parent),_src_path(src_path),_dest_path(dest_path),_file_count(file_count),_parent_item(parent_item),
    _root(root),_self(self),_bstop(false)
{

}

ImportProThread::~ImportProThread()
{

}

void ImportProThread::run()
{
    QMetaObject::invokeMethod(_self, [=]() mutable{
        // 开始拷贝构建目录树
        CreateProTree(_src_path,_dest_path,_file_count,_parent_item,_root,_self);
    }, Qt::QueuedConnection);
    // 取消操作
    if(_bstop){
        // 获取根目录路径
        auto path = dynamic_cast<ProTreeWidgetItem*>(_root)->getPath();

        // 删视图中的item
        int idx = _self->indexOfTopLevelItem(_root);
        delete _self->takeTopLevelItem(idx);

        // 删除文件夹
        QDir root_dir(path);
        // 递归删除
        root_dir.removeRecursively();

        return;
    }
    emit SigOkProg(_file_count);

}

// 递归拷贝和创建目录树
void ImportProThread::CreateProTree(const QString &src_path, const QString &dest_path,
                                    int& file_count, QTreeWidgetItem *parent_item,
                                    QTreeWidgetItem *root,QTreeWidget *self
                                    )
{
    // 按下停止键
    if(_bstop){
        return;
    }

    // 判断两个路径是否相同
    bool needCopy = true;
    if(src_path == dest_path){
        needCopy = false;
    }

    // 原目录
    QDir src_dir(src_path);

    // 过滤文件(里面是需要的)
    src_dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    QFileInfoList filter_files_list = src_dir.entryInfoList();

    // 排序
    std::sort(filter_files_list.begin(),filter_files_list.end(),dirSort);

    // 遍历
    for(auto& fileInfo : filter_files_list){
        if(!needCopy){
            continue;
        }
        if(_bstop){
            return;
        }
        // 判断是文件还是目录
        bool isDir = fileInfo.isDir();
        if(isDir){
            // 目录
            if(_bstop){
                return;
            }

            QString dirName = fileInfo.absolutePath();
            // 更新进度条
            file_count++;
            emit SigUpdateProg(file_count,dirName);

            // 目的目录
            QDir dest_dir(dest_path);
            QString sub_dir_path = dest_dir.absoluteFilePath(fileInfo.fileName());

            // 要拷贝到的子目录
            QDir sub_dir(sub_dir_path);


            // 如果不存在该目录则创建
            if(!sub_dir.exists()){
                bool ok = sub_dir.mkpath(sub_dir_path);
                if(!ok){
                    continue;
                }
            }

            // 创建该子目录item
            auto* item = new ProTreeWidgetItem(parent_item,root,fileInfo.fileName(),sub_dir_path,TreeItemDir);
            item->setData(0,Qt::DisplayRole,fileInfo.fileName());
            item->setData(0,Qt::DecorationRole,QIcon(":/icon/icon/dir.png"));
            item->setData(0,Qt::ToolTipRole,sub_dir_path);

            CreateProTree(fileInfo.absoluteFilePath(),sub_dir_path,file_count,item,root,self);
        }
        else{
            if(!needCopy){
                continue;
            }
            if(_bstop){
                return;
            }

            // 获取文件后缀
            const QString& file_suffix = fileInfo.completeSuffix();

            // 筛选出图片
            if(file_suffix != "png" && file_suffix != "jpeg" && file_suffix != "jpg"){
                continue;
            }

            // 图片源路径
            QString src_file_path = src_dir.absoluteFilePath(fileInfo.fileName());

            // 图片目标路径
            QDir dest_dir(dest_path);
            QString dest_file_path = dest_dir.absoluteFilePath(fileInfo.fileName());

            // 拷贝
            if(!QFile::copy(src_file_path,dest_file_path)){
                qDebug() << "copy file fail";
                continue;
            }

            // 拷贝文件++
            _file_count ++;
            emit SigUpdateProg(_file_count,dest_file_path);

            QMetaObject::invokeMethod(self, [=]() mutable{
                auto* item = new ProTreeWidgetItem(parent_item, root, fileInfo.fileName(), dest_file_path, TreeItemPic);
                item->setData(0, Qt::DisplayRole, fileInfo.fileName());
                item->setData(0, Qt::DecorationRole, QIcon(":/icon/icon/pic.png"));
                item->setData(0, Qt::ToolTipRole, dest_file_path);

                // 加锁
                QMutexLocker locker(&_pre_item_mutex);
                // 构建链表
                if (_pre_item) {
                    auto* pre_pro_item = dynamic_cast<ProTreeWidgetItem*>(_pre_item);
                    pre_pro_item->setNextItem(item);
                }
                item->setPreItem(_pre_item);
                _pre_item = item;

            }, Qt::QueuedConnection);

        }
    }

}


// 取消导入
void ImportProThread::SlotCancelProg()
{
    _bstop = true;
}
