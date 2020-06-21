#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i = 0;

    qDebug() << QElapsedTimer::ClockType();
    QElapsedTimer timer;
    timer.start();

    for(int j = 0; j < 100000; ++ j)
    {
        i += j;
        //qDebug() << i;
    }
    qDebug() << i;
    qDebug() << timer.elapsed();
    return a.exec();
}
