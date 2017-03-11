#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMaximumSize(489,126);
    setMinimumSize(489,126);
    QObject::connect(ui->cal,SIGNAL(clicked()),this,SLOT(calSLot()));
    QObject::connect(ui->SecondLineEdit,SIGNAL(returnPressed()),this,SLOT(calSLot()));
    QObject::connect(ui->FirstLineEdit,SIGNAL(returnPressed()),this,SLOT(calSLot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::calSLot(){
    int first=ui->FirstLineEdit->text().toInt();
    int second=ui->SecondLineEdit->text().toInt();
    int result;
    if (ui->comboBox->currentIndex()==0)
        result=first+second;
    if (ui->comboBox->currentIndex()==1)
        result=first-second;
    if (ui->comboBox->currentIndex()==2)
        result=first*second;
    if (ui->comboBox->currentIndex()==3){
        if (second==0){
            QMessageBox::warning(this,"Error Message","Second Cannot Be Zero!");
        }
        else{
        result=first/second;
        }
    }
    ui->ThirdLineEdit->setText(QString::number(result));
    ui->SecondLineEdit->clear();
    ui->FirstLineEdit->clear();
}
