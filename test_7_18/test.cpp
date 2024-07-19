#include <iostream>
using namespace std;

union data
{
	int n;
	char s[11];
	double d;
};

int main()
{
	union data d;
	printf("%d", sizeof(d));
}

//int main()
//{
//	int a = 8;
//	a -= a += a * 3;
//	printf("%d", a);
//}

//int main()
//{
//	float x = 1.23456789;
//	printf("%f", x);
//}

//int main()
//{
//	char a[] = "abcdefg", b[10] = "abcdefg";
//	printf("%d %d\n", sizeof(a), sizeof(b));
//}

//int main()
//{
//	int i, s = 0;
//	for (i = 1; i < 10; i += 2)
//	{
//		s += i + 1;
//		printf("%d ", i + 1);
//		printf("\n");
//	}
//	printf("%d\n", s);
//	return 0;
//}