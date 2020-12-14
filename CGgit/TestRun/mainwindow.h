#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *ev);
    void DDA(int,int,int,int);

private:
    Ui::MainWindow *ui;
    bool start;
    int a[20],b[20],cnt,ver;

};
#endif // MAINWINDOW_H
