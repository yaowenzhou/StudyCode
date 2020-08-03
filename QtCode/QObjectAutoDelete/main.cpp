#include <QCoreApplication>
#include "a.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    B *b = new B();
    qDebug() << "b delete start";
    delete b;
    qDebug() << "b delete end";

    A *c = b->a;
    c->print();

    return a.exec();
}
