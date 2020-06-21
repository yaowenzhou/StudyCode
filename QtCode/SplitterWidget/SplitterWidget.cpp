#include <QDebug>
#include "SplitterWidget"
#include "ui_SplitterWidget.h"

SplitterWidget::SplitterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SplitterWidget)
    , settings("MySofts", "SplitterWidget")
{
    ui->setupUi(this);
    //这里用来从注册表中加载分割器上一次关闭前的状态
    //注册表的路径为：HKEY_CURRENT_USER\Software\MySofts\SpliterWidget
    if (settings.contains("SplitterSizes")) {
        ui->splitter->restoreState(settings.value("SplitterSizes").toByteArray());
        qDebug() << "is restored";
    } else {
        qDebug() << "This is first lanch SplitterWidget";
    }
}

SplitterWidget::~SplitterWidget()
{
    delete ui;
}

void SplitterWidget::closeEvent(QCloseEvent *e)
{
    settings.setValue("SplitterSizes", ui->splitter->saveState());
    QWidget::closeEvent(e);
}

void SplitterWidget::on_checkBox_toggled(bool checked)
{
    ui->splitter->setOpaqueResize(checked);
}

void SplitterWidget::on_checkBox_2_toggled(bool checked)
{
    ui->splitter->setChildrenCollapsible(checked);
}
