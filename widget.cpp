#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdlib.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    SetPerm();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SetPerm(){
    if(cost >= 200){
        ui->tea100->setEnabled(true);
        ui->coke150->setEnabled(true);
        ui->coffee200->setEnabled(true);
    }
    else if(cost >=150){
        ui->tea100->setEnabled(true);
        ui->coke150->setEnabled(true);
        ui->coffee200->setEnabled(false);
    }
    else if(cost >= 100){
        ui->tea100->setEnabled(true);
        ui->coke150->setEnabled(false);
        ui->coffee200->setEnabled(false);
    }
    else{
        ui->tea100->setEnabled(false);
        ui->coke150->setEnabled(false);
        ui->coffee200->setEnabled(false);
    }
}

void Widget::ChangeMoney(int n)
{
    cost += n;
    ui->lcdNumber->display(cost);
    SetPerm();
};

void Widget::on_tea100_clicked()
{
    ChangeMoney(-100);
}

void Widget::on_coke150_clicked()
{
    ChangeMoney(-150);
}

void Widget::on_coffee200_clicked()
{
    ChangeMoney(-200);

}

void Widget::on_money10_clicked()
{
    ChangeMoney(10);
}

void Widget::on_money50_clicked()
{
    ChangeMoney(50);
}

void Widget::on_money100_clicked()
{
    ChangeMoney(100);
}

void Widget::on_money500_clicked()
{
    ChangeMoney(500);
}

void Widget::on_return_2_clicked()
{
    char p[100];
    CalCharge(p);
    QMessageBox::information(this, "Here you are!", p);
    ui->lcdNumber->display(0);
    SetPerm();
}

void Widget::CalCharge(char *p)
{
    int num[4];
    int money[4] = {500, 100, 50, 10};

    for(int i = 0;i < 4; i++){
        num[i] = cost/money[i];
        cost %= money[i];
    }

     sprintf(p, "%d: %d\n%d: %d\n%d: %d\n%d: %d\n", money[0], num[0], money[1], num[1], money[2], num[2], money[3], num[3]);
}

