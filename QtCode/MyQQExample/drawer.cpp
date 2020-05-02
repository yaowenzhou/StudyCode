#include "drawer.h"
#include <QGroupBox>
#include <QVBoxLayout>


Drawer::Drawer(QWidget *parent, Qt::WindowFlags f):QToolBox(parent, f)
{
    setWindowTitle("My QQ");
    toolBtn1_1 = new QToolButton;
    toolBtn1_1->setText("张三");
    //当鼠标移开时，按钮自动恢复为弹起状态
    toolBtn1_1->setAutoRaise(true);
    /*
     * 设置按钮的ToolButtonStyle
     * Qt::ToolButtonIconOnly：Only display the icon.
     * Qt::ToolButtonTextOnly：Only display the text.
     * Qt::ToolButtonTextBesideIcon：The text appears beside the icon.
     * Qt::ToolButtonTextUnderIcon：The text appears under the icon.
     * Qt::ToolButtonFollowStyle：Follow the style.
    */
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextOnly);

    toolBtn1_2 = new QToolButton;
    toolBtn1_2->setText("李四");
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextOnly);

    toolBtn1_3 = new QToolButton;
    toolBtn1_3->setText("王五");
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextOnly);

    toolBtn1_4 = new QToolButton;
    toolBtn1_4->setText("小赵");
    toolBtn1_4->setAutoRaise(true);
    toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextOnly);

    toolBtn1_5 = new QToolButton;
    toolBtn1_5->setText("小孙");
    toolBtn1_5->setAutoRaise(true);
    toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextOnly);

    QGroupBox *groupBox1 = new QGroupBox;
    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1);
    layout1->setMargin(10);
    layout1->setAlignment(Qt::AlignHCenter);
    //向groupBox中添加各个按钮
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addWidget(toolBtn1_4);
    layout1->addWidget(toolBtn1_5);
    //插入一个占位符
    layout1->addStretch();


    toolBtn2_1 = new QToolButton;
    toolBtn2_1->setText("小王");
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextOnly);

    toolBtn2_2 = new QToolButton;
    toolBtn2_2->setText("小张");
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextOnly);

    QGroupBox *groupBox2 = new QGroupBox;
    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);



    toolBtn3_1 = new QToolButton;
    toolBtn3_1->setText("小陈");
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextOnly);

    toolBtn3_2 = new QToolButton;
    toolBtn3_2->setText("小李");
    toolBtn3_2->setAutoRaise(true);
    toolBtn3_2->setToolButtonStyle(Qt::ToolButtonTextOnly);

    QGroupBox *groupBox3 = new QGroupBox;
    QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignHCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(toolBtn3_2);

    //将准备好的抽屉插入到ToolBox中
    this->addItem((QWidget *)groupBox1, "我的好友");
    this->addItem((QWidget *)groupBox2, "陌生人");
    this->addItem((QWidget *)groupBox3, "黑名单");
}
