#include "a.h"

A::A(QObject *parent) : QObject(parent)
{
    a = 10;
}

A::~A()
{
    qDebug() << "This is A destructor...";
}

void A::print()
{
    //qDebug() << "This is A print method, a = " << a;
    qDebug() << "This is A print method;";
}

B::B(QObject *parent) : QObject(parent)
{
    a = new A(nullptr);
}

B::~B()
{
    qDebug() << "set a's parent is this.";
    a->setParent(this);
    qDebug() << "This is B destructor....";
}
