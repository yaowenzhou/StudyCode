#include <QCoreApplication>
#include <stdio.h>

void printCharNumber(const char* number)
{
    printf("this is char print: %d\n", number[0]);
}

void printUint8_tNumber(const uint8_t* number)
{
    printf("This is uint8_t print: %d\n", number[0]);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    uint8_t uint8Number = 16;
    printCharNumber(&uint8Number);
    printUint8_tNumber(&uint8Number);

    return a.exec();
}
