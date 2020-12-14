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
    void DDA(int x1, int y1, int x2, int y2);
    void mousePressEvent(QMouseEvent *ev);
    int coder(int,int);
    void Eraser(int x1, int y1, int x2, int y2);
    void clipper(int x1, int y1, int x2, int y2);


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    int ver, a[20],b[20],cnt,i,reg,fcode,scode,tx,ty,temp;
    //short int tcode[20],bcode[20],rcode[20],lcode[20];
    bool start,accept;
    float slope,dx,dy;
};
#endif // MAINWINDOW_H
