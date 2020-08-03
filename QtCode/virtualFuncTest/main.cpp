#include <QCoreApplication>
#include <iostream>

class Base
{
public:
    virtual void a() = 0;

};

//void Base::a(){
//    std::cout << "This is 'void Base::a()' virtual function." << std::endl;
//}

class Opt:public Base
{
public:
    void a();
    void a(int);
};

void Opt::a() {
    std::cout << "This is 'void Opt::a()' function." << std::endl;
}

void Opt::a(int x) {
    std::cout << "This is 'void Opt::a(int)' function." << std::endl;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Base base;
    Opt opt;
    //base.a();
    //opt.Base::a();
    opt.a();
    opt.a(3);

    return a.exec();
}
