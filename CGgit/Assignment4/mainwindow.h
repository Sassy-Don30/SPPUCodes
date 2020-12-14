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
//    class MainWindow::Matrix;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void DDA(int,int,int,int);
    void Multiply(float arr1[2][3],float arr2[3][3]);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    float tx,ty,choice,translateDiff[3][3],scaleDiff[3][3],rotateDiff[3][3];
    float originalMat[2][3],resultMat[3][3];

};
#endif // MAINWINDOW_H
