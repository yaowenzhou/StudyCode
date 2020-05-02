﻿#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

class ProgressDlg : public QDialog
{
    Q_OBJECT

public:
    ProgressDlg(QWidget *parent = nullptr);
    ~ProgressDlg();

private slots:
    void startProgress();
private:
    QLabel *fileNum;
    QLineEdit *fileNumLineEdit;
    QLabel *progressType;
    QComboBox *comboBox;
    QProgressBar *progressBar;
    QPushButton *startBtn;
    QGridLayout *mainLayout;
};
#endif // PROGRESSDLG_H
