#include "widget.h"
#include <stdio.h>
#include <QDebug>
#include <QLabel>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(500, 300);
    QLabel *label = new QLabel("Label", this);
    label->resize(100, 50);
    QPushButton *pushButton = new QPushButton("PushButton", this);
    qDebug() << "1\t" << label;
    qDebug() << "2\t" << (void *)label;
    connect(pushButton,
            &QPushButton::clicked,
            [&pushButton, &label, this] () {
                                                qDebug() << "3\t" << (void *)label;
//                                                label->setParent(pushButton);
//                                                qDebug() << this->children();
//                                                delete pushButton;
//                                                //pushButton = nullptr;
//                                                qDebug() << this->children();
                                            });
}

Widget::~Widget()
{
}

