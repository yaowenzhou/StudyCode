#include <QCoreApplication>
#include <QDebug>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString qStr = "看我神威，无坚不摧";
    //QString qSstr = "12345678";
    QByteArray byteArray = qStr.toUtf8();
    char msg[128] = {0};

    for (int x = 0; x < byteArray.size(); ++x) {
        msg[x] = byteArray[x];
    }

    char *msg_ = byteArray.data();

    qDebug() << "qStr's length: " << qStr.length();
    qDebug() << "qStr's size: " << qStr.size();
    qDebug() << "byteArray's length: " << byteArray.length();
    qDebug() << "byteArray's size: " << byteArray.size();
    qDebug() << "byteArray: " << byteArray;
    printf("msg: %s\n", msg);
    qDebug() << "msg_'s length" << strlen(msg_);
    printf("msg_: %s\n", msg_);

    return a.exec();
}
