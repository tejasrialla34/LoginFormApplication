#include "widget.h"
#include "ui_widget.h"
#include<QColor>
#include<QColorDialog>
#include<QFont>
#include<QMessageBox>
#include<QFontDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QPalette pal=ui->label->palette();
        QColor color=pal.color(QPalette::WindowText);
        QColor chosencolor=QColorDialog::getColor(color,this,"Choose Text Color!");
        if(chosencolor.isValid())
        {
            pal.setColor(QPalette::WindowText,chosencolor);
            ui->label->setPalette(pal);
            qDebug()<<"Valid Color Chosen!";
        }
        else
        {
            qDebug()<<"Invalid Color Chosen!";
        }
}

void Widget::on_pushButton_2_clicked()
{
    QPalette pal=ui->label->palette();
        QColor color=pal.color(QPalette::Window);
        QColor chosencolor=QColorDialog::getColor(color,this,"Choose Background Color!");
        if(chosencolor.isValid())
        {
            pal.setColor(QPalette::Window,chosencolor);
            ui->label->setPalette(pal);
            qDebug()<<"Valid Color Chosen!";
        }
        else
        {
            qDebug()<<"Invalid Color Chosen!";
        }
}

void Widget::on_pushButton_3_clicked()
{
    bool ok;
       QFont f=QFontDialog::getFont(&ok,QFont("Times new roman,20"),this);
       if(ok)
       {
           ui->label->setFont(f);
       }
       else
       {
           QMessageBox::information(this,"Error","No Font Chosen");
       }
}
