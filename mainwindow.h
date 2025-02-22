#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QWidget*  _protree; // 目录树
    QWidget*  _picshow; // 图片展示
private:
    void init();

protected:
    // 窗口尺寸改变
    void resizeEvent(QResizeEvent* event) override;  // 必须添加override关键字

private slots:
    void SlotCreatePro(bool);
    void SlotOpenPro(bool);

signals:
    void SigOpenPro(QString dirName);
};
#endif // MAINWINDOW_H
