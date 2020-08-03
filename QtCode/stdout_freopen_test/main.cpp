#include <QCoreApplication>
#include <Windows.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("Stdout test...");
    FILE * pf ;//= fopen("./log.txt", "w");
    freopen_s(&pf, "./log.txt", "w", stdout);
    printf("This is stdout test after freopen");
    fclose(pf);
    return a.exec();
}
