#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
using namespace  std;
#include<QColorDialog>
QColor c;

static QImage img(500,500,QImage::Format_RGB888);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    accept = false;
    ver = 0;
    cnt = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float dx, dy, step;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    float x =x1,y = y1;

    float xincr = dx / step, yincr = dy / step;

    for(int i = 0;i<step;++i)
    {
        img.setPixel(x,y,qRgb(0,255,0));
        x += xincr;
        y += yincr;

    }
     ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{

    if(start)
    {
        cnt++;
        int p = ev->pos().x();
        int q = ev->pos().y();
        a[ver] = p;
        b[ver] = q;

        if(ev->button() == Qt::RightButton)
        {
            start = false;
        }

        if(cnt == 2)
       {
            if(ver > 0)
        {
            DDA(a[ver],b[ver],a[ver-1],b[ver-1]);
        }
        cnt = 0;
        }

        ver++;

      }


}

int MainWindow::coder(int x, int y)
{

      reg = 0;
      if(y > 350)
          reg += 8;
      if(y < 150)
          reg += 4;
      if(x > 450)
          reg += 2;
      if(x < 50)
          reg += 1;

      return reg;

}

void MainWindow::Eraser(int x1, int y1, int x2, int y2)
{
    float dx, dy, step;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    float x =x1,y = y1;

    float xincr = dx / step, yincr = dy / step;

    for(int i = 0;i<step;++i)
    {
        img.setPixel(x,y,qRgb(0,0,0));
        x += xincr;
        y += yincr;

    }
     ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::clipper(int x1, int y1, int x2, int y2)
{
     fcode = coder(x1,y1);
     scode = coder(x2,y2);
     accept = false;
     Eraser(x1,y1,x2,y2);
     dy = y2 - y1;
           dx = x2 - x1;
           if(dy == 0.0f) slope = 1.0;
           if(dx == 0.0f) slope = 0.0;
           if((dy != 0.0f)&&(dx != 0.0f))
           {
               slope = dy/dx;
           }

     while (true)
     {
         if((fcode == 0) && (scode == 0))
         {
             accept = true;
             break;
         }
         else if(fcode & scode)
         {
             break;
         }
         else
         {

             if(fcode != 0)
                 temp = fcode;
             else
                 temp = scode;
             if(temp & 8)
             {
                 tx = x1 + (350-y1)/slope;
                 ty = 350;
             }
             else if(temp & 4)
             {
                 tx = x1 +(150-y1)/slope;
                 ty = 150;
             }
             if( temp & 2)
             {
                 ty = y1 + slope*(450-x1);
                 tx = 450;
             }
             else if( temp & 1 )
             {
                 ty = y1 + slope*(50-x1);
                 tx = 50;
             }

             if(temp == fcode)
             {
                 x1 = tx;
                 y1 = ty;
                 fcode = coder(x1,y1);
             }
             else
             {
                 x2 = tx;
                 y2 = ty;
                 scode = coder(x2,y2);
             }

         }
     }
     if(accept)
     {
         DDA(x1,y1,x2,y2);
         img.setPixel(x1,y1,qRgb(0,255,0));
         img.setPixel(x2,y2,qRgb(0,255,0));
     }


}



void MainWindow::on_pushButton_clicked()
{
    DDA(50,150,450,150);
    DDA(50,150,50,350);
    DDA(50,350,450,350);
    DDA(450,150,450,350);


}

void MainWindow::on_pushButton_2_clicked()
{


       for(i = 0;i < ver;i+=2)
       {
           clipper(a[i],b[i],a[i+1],b[i+1]);
       }
}

void MainWindow::on_pushButton_3_clicked()
{

}
