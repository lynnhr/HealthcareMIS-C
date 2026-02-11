#include "findbox.h"
#include "ui_findbox.h"

findBox::findBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::findBox)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &findBox::searchPt);

}

findBox::~findBox()
{
    delete ui;
}

void findBox::searchPt()
{
    QString ptRecordNumber=ui->lineEdit->text();
    emit onSearch(ptRecordNumber);

}

