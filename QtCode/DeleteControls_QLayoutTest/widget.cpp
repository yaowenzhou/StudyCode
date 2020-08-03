#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QPushButton *button1 = new QPushButton("button1", this);
    QPushButton *button2 = new QPushButton("button2", this);
    QPushButton *button3 = new QPushButton("button3", this);
    QPushButton *button4 = new QPushButton("button4", this);
    QPushButton *button5 = new QPushButton("button5", this);
    QPushButton *button6 = new QPushButton("button6", this);

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);

    delete button2;
    delete button3;

    layout->addWidget(button4);
    layout->addWidget(button5);
    layout->addWidget(button6);

    qDebug() << layout->count();
}

Widget::~Widget()
{
    delete ui;
}

