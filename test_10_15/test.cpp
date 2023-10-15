#define ADD(x, y) ((x) + (y))

#include <iostream>

using namespace std;

inline int Add(int x, int y)
{
	return x + y;
}

int main()
{
	cout << ADD(3, 5) << endl;
	cout << Add(3, 5) << endl;
}