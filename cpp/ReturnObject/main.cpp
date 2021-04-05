/*
 * @Author: your name
 * @Date: 2020-12-19 20:56:21
 * @LastEditTime : 2021-04-05 16:02:34
 * @LastEditors  : yaowenzhou
 * @Description: C++返回一个对象的过程
 * @FilePath: /Study/during_return.cpp
 */

#include <iostream>

using namespace std;

class Person
{
public:
    int* data;
    Person()
    {
        cout << "Constructor ----> " << this << endl;
        data = new int(0);
    }
    Person(const Person &p)
    {
        cout << "Copy constructor ---->" << this << endl;

        this->data = p.data;
        cout << "copy end..." << endl;
    }
    ~Person()
    {
        cout << "Destructor ---->" << this << endl;
        cout << "In destructor, data: " << data << endl;
        delete data;
    }
    void operator=(const Person& p ) {
        cout << "operator= ----> " << this << endl;
        *this->data = *p.data;
    }
};

Person get(Person &p)
{
    cout << "In Person::get()----" << endl;
    // 1. 拷贝构造一个临时对象
    // 2. 赋值操作符
    // 3. 析构临时对象
    return p;
}
Person &getP(Person &p)
{
    cout << "In Person::getP()----" << endl;
    return p;
}

int main()
{
    Person p1, p2;
    cout << "p1's address is:" << &p1 << endl;
    cout << "p2's address is:" << &p2 << endl;
    *p1.data = 10;
    cout << "p1's data is:" << *p1.data << endl;
    cout << "start get..." << endl;
    p2 = getP(p1);
    p2 = get(p1);
    return 0;
}
