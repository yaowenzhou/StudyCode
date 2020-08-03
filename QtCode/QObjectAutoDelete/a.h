#ifndef A_H
#define A_H

#include <QObject>
#include <QDebug>

class A : public QObject
{
    Q_OBJECT
public:
    explicit A(QObject *parent = nullptr);
    ~A();
    void print();
    int a;

signals:

};

class B : public QObject
{
public:
    explicit B(QObject *parent = nullptr);
    ~B();

    A *a;
};

#endif // A_H
