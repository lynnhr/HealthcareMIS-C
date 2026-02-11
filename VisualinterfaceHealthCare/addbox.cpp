#include "addbox.h"
#include "ui_addbox.h"

addBox::addBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addBox)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&addBox::getVal);
}

addBox::~addBox()
{
    delete ui;
}

void addBox::getVal()
{
    QString RecordNumber=ui->lineEdit->text();
    QString Name=ui->lineEdit_2->text();
    QString Section=ui->lineEdit_3->text();

    emit enterInfo(RecordNumber,Name,Section) ;

}

