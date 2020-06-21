#include <iostream>

using namespace std;

class A
{
public:
	A(int _a);
	~A();
	int ap;
	void print();
	void printf();
	int a();
};

A::A(int _a)
{
	ap = _a;
}

A::~A() {

}

void A::print()
{
	cout << "This is print." << endl;
}

void A::printf()
{
	cout << a() << endl;
}

int A::a()
{
	return 128;
}

int main()
{
	A* a = new A(10);
	delete a;

	A::print();

	cout << "a.a(): " << a->a() << endl;
	return 0;
}
