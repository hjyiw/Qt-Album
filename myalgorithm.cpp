#include "myalgorithm.h"

#include <QCollator>

bool dirSort(const QFileInfo &a, const QFileInfo &b)
{
    // 目录优先于文件
    if (a.isDir() != b.isDir()) {
        return a.isDir() > b.isDir(); // 目录在前
    }
    // 名称排序（自然数字模式）
    static QCollator collator;
    collator.setNumericMode(true);
    return collator.compare(a.fileName(), b.fileName()) < 0;
}
