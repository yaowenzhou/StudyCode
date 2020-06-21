#include "palette.h"

#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>

Palette::Palette(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(contentFrame);
}

Palette::~Palette()
{
}

void Palette::createCtrlFrame()
{
    ctrlFrame = new QFrame;//颜色选择面板

    windowLabel = new QLabel("QPalette::Window:");
    windowComboBox = new QComboBox;
    fillColorList(windowComboBox);
    connect(windowComboBox, static_cast<void (QComboBox:: *)(int)>(&QComboBox::activated), this, &Palette::showWindow);

    windowTextLabel = new QLabel("QPalette::WindowText:");
    windowTextComboBox = new QComboBox;
    fillColorList(windowTextComboBox);
    connect(windowTextComboBox, static_cast<void (QComboBox:: *)(int)>(&QComboBox::activated), this, &Palette::showWindowText);

    buttonLabel = new QLabel("QPalette::Button:");
    buttonComboBox = new QComboBox;
    fillColorList(buttonComboBox);
    connect(buttonComboBox, static_cast<void (QComboBox:: *)(int)>(&QComboBox::activated), this, &Palette::showButton);

    buttonTextLabel = new QLabel("QPalette::ButtonText:");
    buttonTextComboBox = new QComboBox;
    fillColorList(buttonTextComboBox);
    connect(buttonTextComboBox, static_cast<void (QComboBox:: *)(int)>(&QComboBox::activated), this, &Palette::showButtonText);

    baseLabel = new QLabel("QPalette::Base:");
    baseComboBox = new QComboBox;
    fillColorList(baseComboBox);
    connect(baseComboBox, static_cast<void (QComboBox:: *)(int)>(&QComboBox::activated), this, &Palette::showBase);

    QGridLayout *mainLayout = new QGridLayout(ctrlFrame);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(windowLabel, 0, 0);
    mainLayout->addWidget(windowComboBox, 0, 1);
    mainLayout->addWidget(windowTextLabel, 1, 0);
    mainLayout->addWidget(windowTextComboBox, 1, 1);
    mainLayout->addWidget(buttonLabel, 2, 0);
    mainLayout->addWidget(buttonComboBox, 2, 1);
    mainLayout->addWidget(buttonTextLabel, 3, 0);
    mainLayout->addWidget(buttonTextComboBox, 3, 1);
    mainLayout->addWidget(baseLabel, 4, 0);
    mainLayout->addWidget(baseComboBox, 4, 1);
}

void Palette::createContentFrame()
{
    contentFrame = new QFrame();
    label1 = new QLabel("请选择一个值：");
    comboBox1 = new QComboBox;
    label2 = new QLabel("请输入字符串：");
    lineEdit2 = new QLineEdit;
    textEdit = new QTextEdit;
    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget(label1, 0, 0);
    topLayout->addWidget(comboBox1, 0, 1);
    topLayout->addWidget(label2, 1, 0);
    topLayout->addWidget(lineEdit2, 1, 1);
    topLayout->addWidget(textEdit, 2, 0, 1, 2);
    OkBtn = new QPushButton("确认");
    CancelBtn = new QPushButton("取消");
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch(1);
    bottomLayout->addWidget(OkBtn);
    bottomLayout->addWidget(CancelBtn);
    QVBoxLayout *mainLayout = new QVBoxLayout(contentFrame);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);


    OkBtn->setAutoFillBackground(true);     //允许自动填充
    CancelBtn->setAutoFillBackground(true);
    contentFrame->setAutoFillBackground(true);
}

void Palette::fillColorList(QComboBox *comboBox)
{
    QStringList colorList = QColor::colorNames();
    QString color;
    foreach(color, colorList)
    {
        QPixmap pix(QSize(70, 20));
        pix.fill(QColor(color));
        comboBox->addItem(QIcon(pix), NULL);
        comboBox->setIconSize(QSize(70, 20));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

void Palette::showWindow()
{
    //获得当前选择的颜色值
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Window, color);
    //把修改后的调色板信息应用到contentFrame窗体中，更新显示
    //contentFrame->setAutoFillBackground(true);
    contentFrame->setPalette(p);
    //contentFrame->update();
}

void Palette::showWindowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = colorList[windowTextComboBox->currentIndex()];
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::WindowText, color);
    contentFrame->setPalette(p);
}

void Palette::showButton()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Button, color);
    contentFrame->setAutoFillBackground(true);
    contentFrame->setPalette(p);
    //OkBtn->setStyleSheet("background-color:rgb(0, 0, 0)");
    //contentFrame->update();
}

void Palette::showButtonText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonTextComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::ButtonText, color);
    contentFrame->setPalette(p);
}

void Palette::showBase()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[baseComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Base, color);
    contentFrame->setPalette(p);
}

