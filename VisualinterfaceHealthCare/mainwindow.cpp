#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,addbox(new addBox(this))
    ,findbox(new findBox(this))
    ,updatebox(new updateBox(this))
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this, &MainWindow::addFun);
    connect(addbox,&addBox::enterInfo,this,&MainWindow::getInfo);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::SearchFun);
    connect(findbox, &findBox::onSearch, this,&MainWindow::onFind);
    connect(ui->pushButton_3,&QPushButton::clicked,this, &MainWindow::updateFun);
    connect(updatebox,&updateBox::newSec,this,&MainWindow::onUpdate);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addbox;
    delete findbox;
    delete updatebox;
}
QStringList RecordNumberList;
QStringList Namelist;
QStringList secList;
bool found=false;


void MainWindow::addFun()
{
    addbox->show();
    }
void MainWindow::getInfo(const QString &rn,const QString &n, const QString &s){
    RecordNumberList.append(rn);
    Namelist.append(n);
    secList.append(s);
    QMessageBox::information(this,"Sucess",
                             "Patient Added Successfullyy!");


}



void MainWindow::SearchFun()
{
    findbox->show();

}
void MainWindow::onFind(const QString &rn){
    for (int i=0;i<RecordNumberList.length();i++){
        if(rn==RecordNumberList[i]){
            found=true;

            QMessageBox::information(this, "Success",
                                     "Record number: " + RecordNumberList[i] + "\n" +
                                         "Name of Student: " + Namelist[i] + "\n" +
                                         "Section of Student: " + secList[i]);

            break;
        }

    }
    if(!found){
        QMessageBox::information(this,"Error",
                                 "Sorry Invalid Record Number!");
    }
}


void MainWindow::updateFun()
{
    updatebox->show();
}

void MainWindow::onUpdate(const QString &rn, const QString &s){
    for (int i=0;i<RecordNumberList.length();i++){
        if (rn==RecordNumberList[i]){
            found=true;
            secList[i]=s;
            QMessageBox::information(this, "Success",

                                         "Section of Patient in hospital: " + secList[i]);
            break;

        }
    }
    if(!found){
        QMessageBox::information(this,"Error",
                                 "Sorry Invalid Record Number!");
    }
}

