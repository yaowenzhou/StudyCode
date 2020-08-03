#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    installEventFilter(this);
    ui->pushButton->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->pushButton && event->type() == QEvent::Type::MouseButtonPress) {
        qDebug() << "This is eventFilter, pushButton has been checked: " << ui->pushButton->isChecked();
    }
    return QWidget::eventFilter(watched, event);
}


void Widget::on_pushButton_clicked()
{
    qDebug() << "This is slot, pushButton is checked: " << ui->pushButton->isChecked();
}
