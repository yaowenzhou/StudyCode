#include "widget.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(QRect(50, 90, 125, 400));
    //下面这句很重要，只有设置了这一句，QScrollArea的widget的size才能比QScrollArea大，然后才能出现滚动条
    scrollArea->setWidgetResizable(true);
    QWidget *scrollWidget = new QWidget(this);
    //QWidget *scrollWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(scrollWidget);
    QPushButton *btn[33];
    for (int x = 0; x < 33; ++x) {
        btn[x] = new QPushButton("QPushButton" + QString::number(x), scrollWidget);
        btn[x]->resize(100, 30);
        mainLayout->addWidget(btn[x]);
    }
    scrollArea->setWidget(scrollWidget);
}

Widget::~Widget()
{
}

