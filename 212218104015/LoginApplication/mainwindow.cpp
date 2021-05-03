#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<unistd.h>
#include<QTimer>

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
    QString user=ui->lineEdit->text();
        QString pass=ui->lineEdit_2->text();
        if(user=="tejasri"&&pass=="4015")
        {
            ui->label_3->setText("Login Successful!!");
            QTimer::singleShot(5000, this, [this] () { ui->label_3->setText(""); });
        }
        else
        {
            ui->label_3->setText("Username or Password Incorrect!!");
            QTimer::singleShot(5000, this, [this] () { ui->label_3->setText(""); });
        }
}
