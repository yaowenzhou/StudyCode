#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button == static_cast<QAbstractButton *>(ui->buttonBox->button(QDialogButtonBox::Ok)))
    {
        qDebug() << R"(Button "OK" has been clicked.)";
    }
    else if(button == ui->buttonBox->button(QDialogButtonBox::Cancel))
    {
        qDebug() << R"(Button "Cancle" has been clicked.)";
    }
}
