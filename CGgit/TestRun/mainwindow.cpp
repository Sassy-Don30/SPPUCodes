#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "iostream"

using namespace std;

static QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    cnt = 0;
    ver = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    cout<<"Hiii"<<endl;
    if(start){
        cnt++;
        int p = ev->pos().x();
        int q = ev->pos().y();
        a[ver] = p;
        b[ver] = q;

        if(ev->button() == Qt::RightButton)
            start = false;
        if(cnt == 2){
            if(ver>0){
                DDA(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
            cnt = 0;
        }
        ver++;
    }
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float dx,dy,step;
    dx = x2-x1;
    dy = y2-y1;
    step = abs(dx)>abs(dy) ? abs(dx) : abs(dy);
    float x=x1,y=y1;
    float Xinc = dx/step,Yinc = dy/step;

    for(int i=0;i<step;++i){
        img.setPixel(x,y,qRgb(0,255,255));
        x += Xinc;
        y += Yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

