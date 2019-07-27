#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    int cost = 0;

public:
    explicit Widget(QWidget *parent = nullptr);
    void ChangeMoney(int n);
    void CalCharge(char *p);
    void SetPerm();
    ~Widget();

private slots:
    void on_tea100_clicked();

    void on_coke150_clicked();

    void on_coffee200_clicked();

    void on_money10_clicked();

    void on_money50_clicked();

    void on_money100_clicked();

    void on_money500_clicked();

    void on_return_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
