﻿#include "Butterfly"
#include <math.h>

const static double PI = 3.1416;

Butterfly::Butterfly(QObject *parent) : QObject(parent)
{
    up = true;
    pix_up.load("up.png");
    pix_dn.load("down.png");
    startTimer(100);
}

void Butterfly::timerEvent(QTimerEvent *)
{
    //border control
    qreal edgeR = scene()->sceneRect().right() + boundingRect().width()/2;	//Limit the right border of butterfly flying.
    qreal edgeT = scene()->sceneRect().top() - boundingRect().height()/2;	//Limit the upper border of butterfly flying.
    qreal edgeB = scene()->sceneRect().bottom() + boundingRect().height()/2;//Limit the lower border of butterfly flying.
    if (pos().x() >= edgeR)
        setPos(scene()->sceneRect().left(), pos().y());
    if (pos().y() <= edgeT)
        setPos(pos().x(), scene()->sceneRect().bottom());
    if (pos().y() >= edgeB)
        setPos(pos().x(), scene()->sceneRect().top());
    angle += (qrand()%10)/20.0;
    qreal dx = fabs(sin(angle*PI)*10.0);
    qreal dy = (qrand()%20)-10.0;
    setPos(mapToParent(dx, dy));
}

QRectF Butterfly::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-pix_up.width()/2-adjust, -pix_up.height()/2-adjust,
                  pix_up.width()+adjust*2, pix_up.height()+adjust*2);
}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (up) {
        painter->drawPixmap(boundingRect().topLeft(), pix_up);
        up = !up;
    } else {
        painter->drawPixmap(boundingRect().topLeft(), pix_dn);
        up = !up;
    }
}

