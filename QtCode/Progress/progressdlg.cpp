//此案例充分证明了槽函数的阻塞性
//案例解析见 Qt5 开发及实例 —— 第4版 P102—4.8 进度条 的讲解
#include "progressdlg.h"
#include <QProgressDialog>
#include <QFont>
#include <QPushButton>

ProgressDlg::ProgressDlg(QWidget *parent)
    : QDialog(parent)
{
    QFont font("ZYSong18030", 12);
    setFont(font);
    setWindowTitle("Progress");

    fileNum = new QLabel("文件数目：");
    fileNumLineEdit = new QLineEdit("100000");
    progressType = new QLabel("显示类型：");
    comboBox = new QComboBox;
    comboBox->addItem("progressBar");
    comboBox->addItem("progressDialog");
    progressBar = new QProgressBar;
    progressBar->setValue(0);
    startBtn = new QPushButton("开始");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileNum, 0, 0);
    mainLayout->addWidget(fileNumLineEdit, 0, 1);
    mainLayout->addWidget(progressType, 1, 0);
    mainLayout->addWidget(comboBox, 1, 1);
    mainLayout->addWidget(progressBar, 2, 0, 1, 2);
    mainLayout->addWidget(startBtn, 3, 1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    connect(startBtn, &QPushButton::clicked, this, &ProgressDlg::startProgress);

}

ProgressDlg::~ProgressDlg()
{
}

void ProgressDlg::startProgress()
{
    bool ok;
    int num = fileNumLineEdit->text().toInt(&ok);
    if(comboBox->currentIndex() == 0)
    {
        progressBar->setRange(0, num);
        for (int i = 1; i < num + 1; ++i)
        {
            progressBar->setValue(i);
        }
    }
    else if (comboBox->currentIndex() == 1)
    {
        //创建一个进度对话框
        QProgressDialog *progressDialog = new QProgressDialog(this);
        QFont font("ZYSong18030", 12);
        progressDialog->setFont(font);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(5);
        progressDialog->setWindowTitle("Please Wait");
        progressDialog->setLabelText("Copying...");
        progressDialog->setCancelButtonText("Cancel");
        progressDialog->setRange(0, num);
        for (int i = 1; i < num + 1; ++i)
        {
            progressDialog->setValue(i);
            if(progressDialog->wasCanceled())
                return;
        }
    }
}

