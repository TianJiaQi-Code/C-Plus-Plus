#include <iostream>

using namespace std;

// КЏЪ§жиди

void Add(int x, int y)
{
	cout << x + y << '\n';
}

void Add(double x, double y)
{
	cout << x + y << '\n';
}

int main()
{
	int a = 10, b = 20;
	double c = 3.14, d = 5.2;
	Add(a, b);
	Add(c, d);
	return 0;
}