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

private slots:
    void on_pushButton_clicked();
    void SetXY(int, int);
    void HilbertA(int);
    void HilbertB(int);
    void HilbertC(int);
    void HilbertD(int);
    void LineDraw(int, int);
    void DDA(int ,int ,int ,int);

private:
    Ui::MainWindow *ui;
    int dist, dist0, x, y;
};
#endif // MAINWINDOW_H
