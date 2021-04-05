/*
 * @Author       : yaowenzhou
 * @Date         : 2021-04-05 16:05:35
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-04-05 16:06:49
 * @version      :
 * @Description  : 多态性
 */
#include <iostream>

using namespace std;

class Person {
 public:
  virtual void talk() { cout << "I'm a person..." << endl; }
};

class Student : public Person {
 public:
  virtual void talk() { cout << "I'm a student..." << endl; }
};

int main() {
  Person *p1 = new Person();
  Person *p2 = new Student();
  p1->talk();
  p2->talk();
}
