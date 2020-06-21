#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	for (int j = 0; j < 100; ++j)
	{
		i += j;
	}
	cout << i << endl;
	return 0;
}