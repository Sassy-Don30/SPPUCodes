#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<math.h>
#include "QColorDialog"

using namespace std;
static QImage img(500,500,QImage::Format_RGB888);
QColor rang;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    choice = 0;
    DDA(250,0,250,500);
    DDA(0,250,500,250);

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i == j)
            {
                translateDiff[i][j] = 1;
                scaleDiff[i][j] = 1;
                rotateDiff[i][j] = 1;
            }

            else
            {
                translateDiff[i][j] = 0;
                scaleDiff[i][j] = 0;
                rotateDiff[i][j]= 0;
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            originalMat[i][j] = 1;
            resultMat[i][j] = 0;
        }
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

class Matrix{
public:
    float arr1[2][3],arr2[3][3];

    Matrix(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j){
                    this->arr2[i][j] = 1;
                }
                else {
                    this->arr2[i][j] = 0;
                }
            }
        }
    }

    void operator *(Matrix mat2){
        Matrix multMat;

        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++){
                    multMat.arr1[i][j] += arr1[i][k] + mat2.arr2[k][j];
                }

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                multMat.arr2[i][j] = 0;
            }
        }

    }
};


void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float dx, dy, step;
    dx = x2 - x1;
    dy = y2 - y1;

    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x =x1,y = y1;

    float xincr = dx / step, yincr = dy / step;

    for(int i = 0;i<step;++i)
    {
        if(choice == 0)
            img.setPixel(x,y,qRgb(0,255,0));
        else
            img.setPixel(x,y,rang.rgb());

        x += xincr;
        y += yincr;

    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::Multiply(float arr1[2][3],float arr2[3][3])
{

    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 3;j++)
            for (int k = 0;k < 3;k++)
            {
                resultMat[i][j] += arr1[i][k] * arr2[k][j];

            }

    DDA(250+resultMat[0][0],250-resultMat[0][1],250+resultMat[1][0],250-resultMat[1][1]);

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            resultMat[i][j] = 0;
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
   choice = 1;

   int x1, y1, x2, y2;
   x1 = ui->textEdit->toPlainText().toInt();
   y1 = ui->textEdit_2->toPlainText().toInt();
   x2 = ui->textEdit_3->toPlainText().toInt();
   y2 = ui->textEdit_4->toPlainText().toInt();

   originalMat[0][0] = x1;
   originalMat[0][1] = y1;
   originalMat[1][0] = x2;
   originalMat[1][1] = y2;
   DDA(250+x1,250-y1,250+x2,250-y2);
}

void MainWindow::on_pushButton_2_clicked()
{
    choice = 1;

    int tx, ty;
    tx = ui->textEdit_5->toPlainText().toInt();
    ty = ui->textEdit_6->toPlainText().toInt();

    translateDiff[2][0] = tx;
    translateDiff[2][1] = ty;
    Multiply(originalMat,translateDiff);
}


void MainWindow::on_pushButton_3_clicked()
{
    choice = 1;

    int sx, sy;
    sx = ui->textEdit_5->toPlainText().toInt();
    sy = ui->textEdit_6->toPlainText().toInt();

    scaleDiff[1][1] = sy;
    scaleDiff[0][0] = sx;
    Multiply(originalMat,scaleDiff);
}


void MainWindow::on_pushButton_4_clicked()
{
    choice = 1;
    int Angle;
    Angle = ui->textEdit_7->toPlainText().toInt();

    rotateDiff[0][0] = cos(Angle*3.14/180);
    rotateDiff[0][1] = sin(Angle*3.14/180);
    rotateDiff[1][0] = -sin(Angle*3.14/180);
    rotateDiff[1][1] =  cos(Angle*3.14/180);
    Multiply(originalMat,rotateDiff);
}


void MainWindow::on_pushButton_5_clicked()
{
    rang = QColorDialog::getColor();
}
