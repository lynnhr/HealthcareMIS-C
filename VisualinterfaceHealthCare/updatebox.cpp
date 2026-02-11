#include "updatebox.h"
#include "qpushbutton.h"
#include "ui_updatebox.h"

updateBox::updateBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::updateBox)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&updateBox::updateSec);
}

updateBox::~updateBox()
{
    delete ui;
}

void updateBox::updateSec()
{
    QString RecordNumber=ui->lineEdit->text();

    QString sec=ui->lineEdit_2->text();
    emit newSec(RecordNumber,sec);

}

