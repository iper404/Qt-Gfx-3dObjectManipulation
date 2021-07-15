#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_clearPushButton_clicked()
{
    ui->openGLWidget->onClearButton();
}

void Dialog::on_vertexModeRad_clicked()
{
    radial = 1;
    mode = "Vertex Mode";
    ui->currModeLabel->setText(mode);
}

void Dialog::on_translateModeRad_clicked()
{
    radial = 2;
    mode = "Translate Mode";
    ui->currModeLabel->setText(mode);
}

void Dialog::on_xAxisRad_clicked()
{
    axisRad = 1;
    axis = "X-Axis";
    ui->currAxisLabel->setText(axis);
}

void Dialog::on_yAxisRad_clicked()
{
    axisRad = 2;
    axis = "Y-Axis";
    ui->currAxisLabel->setText(axis);
}

void Dialog::on_zAxisRad_clicked()
{
    axisRad = 3;
    axis = "Z-Axis";
    ui->currAxisLabel->setText(axis);
}

void Dialog::mousePressEvent(QMouseEvent *ev){

    if(radial == 2){//translate mode -- calculate distance btwn mouse clicks
        x1 = ev->x();
        y1 = ev->y();
    }

    if(radial == 1 && triCount == 0){ //vertex mode -- place vertex
        //save coordinates of 'x' and 'y' to x1, y1
        x1 = ev->x();
        y1 = ev->y();

        triCount++;

        ui->openGLWidget->onVertexOne(x1, y1);

    }

    else if(radial == 1 && triCount == 1){ //vertex mode -- place vertex
        //save coordinates of 'x' and 'y' to x1, y1
        x2 = ev->x();
        y2 = ev->y();
        triCount++;

        ui->openGLWidget->onVertexTwo(x2, y2);
    }

    else if(radial == 1 && triCount == 2){ //vertex mode -- place vertex
        //save coordinates of 'x' and 'y' to x1, y1
        x3 = ev->x();
        y3 = ev->y();
        triCount++;

        ui->openGLWidget->onVertexThree(x3, y3);

        triCount = 0; //reset triangle
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
        x3 = 0;
        y3 = 0;

        cout << "Tricount: " << triCount << "\n\n";
    }
}

void Dialog::mouseReleaseEvent(QMouseEvent *ev){
    if(radial == 2){
        x2 = ev->x();
        y2 = ev->y();

        ui->openGLWidget->onTranslateButton(x1, y1, x2, y2, axisRad);
    }
}

