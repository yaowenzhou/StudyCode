#include "digiclock.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>

DigiClock::DigiClock(QWidget *parent):QLCDNumber(parent)
{
    /* Set clock background */
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::blue);
    setPalette(p);

    /* Set the window style to a form without a panel border and title bar */
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);
    setDigitCount(8);

    QTimer *timer = new QTimer(this);/* Create a new timer object */
    connect(timer, &QTimer::timeout, this, &DigiClock::showTime);
    timer->start(1000);/* Run the timer for a thousand milliseconds */

    showTime();/* Initial time display */
    resize(150,60);/* Sets the size of the electronic clock display */
    showColon = true;
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    else if(event->button() == Qt::RightButton)
        close();
}

void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}

void DigiClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("HH:mm:ss");
    if(showColon)
        showColon = false;
    else
    {
        //text[2] = ' ';
        //text[5] = ' ';
        showColon = true;
    }
    display(text);
}
