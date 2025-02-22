#include "mainwindow.h"
#include "slideshowdialog.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/style/style.qss");
    if(!qss.open(QFile::ReadOnly)){
        qDebug() << "open qss file failed";
        return 1;
    }
    a.setStyleSheet(qss.readAll());
    qss.close();
    MainWindow w;
    w.show();
    // SlideShowDialog w(nullptr,nullptr);
    // w.show();
    return a.exec();
}
