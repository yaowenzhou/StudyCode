#pragma comment(lib, "User32.lib")

#include "widget.h"

#include <QApplication>
//#include <QCoreApplication>
#include <Windows.h>
//#include <consoleapi3.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AllocConsole();
    SetConsoleTitleA("ConsoleAllocFreeTest");
    HWND handle = GetConsoleWindow();
    FILE *pf;
    freopen_s(&pf, "CONOUT$", "w", stdout);
    freopen_s(&pf, "CONOUT$", "w", stderr);
    printf_s("This is console test...\n");
    qDebug() << "qDebug() outputs information to standard output device by default.";
    qDebug() << "qDebug() 默认将信息输出到标准输出。";
    //use function 'SendMessageA' to close console window.
    //FreeConsole() only can unbind  the program and console.
    FreeConsole();
    //SendMessageA(handle, WM_CLOSE, 0, 0);
    Widget w;
    w.show();
    return a.exec();
}
