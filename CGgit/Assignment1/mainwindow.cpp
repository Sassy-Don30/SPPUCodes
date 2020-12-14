#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;

    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui -> textEdit_4->toPlainText().toInt();
    DDA(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    int cx,cy,r;

    cx = ui->textEdit_5->toPlainText().toInt();
    cy = ui->textEdit_6->toPlainText().toInt();
    r = ui-> textEdit_7->toPlainText().toInt();

    Bresenham(cx,cy,r);
    ui -> label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    DDA(100,100,400,100);
    DDA(100,100,100,300);
    DDA(400,300,100,300);
    DDA(400,300,400,100);
    DDA(250,100,400,200);
    DDA(250,100,100,200);
    DDA(250,300,100,200);
    DDA(250,300,400,200);
    Bresenham(250,200,83);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float dx,dy,xinc,yinc,step;
    dx = x2-x1;
    dy = y2-y1;
    step = abs(dx)>abs(dy) ? abs(dx) : abs(dy);
    xinc = dx/step;
    yinc = dy/step;
    float x=x1;
    float y=y1;
    for (int i=0;i<=step;i++)
    {
        img.setPixel(x,y,qRgb(0,255,0));
        x += xinc;
        y += yinc;
    }
}

void MainWindow::Bresenham(int cx, int cy, int r)
{
    int p = 3-(2*r);
    int x=0,y=r;

    while (x<=y)
    {
        img.setPixel(cx+y,cy+x,qRgb(0,0,255));
        img.setPixel(cx+x,cy+y,qRgb(0,0,255));
        img.setPixel(cx-x,cy+y,qRgb(0,0,255));
        img.setPixel(cx-y,cy+x,qRgb(0,0,255));
        img.setPixel(cx-y,cy-x,qRgb(0,0,255));
        img.setPixel(cx-x,cy-y,qRgb(0,0,255));
        img.setPixel(cx+x,cy-y,qRgb(0,0,255));
        img.setPixel(cx+y,cy-x,qRgb(0,0,255));


        x +=1;
        if(p<0)
           p = p + 4*x + 6;
        else {
            p = p + 4*(x-y) + 10;
            y--;
        }

    }
}




