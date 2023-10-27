#include "Date.h"

using namespace std;

void TestDate1()
{
	Date d1(2023, 10, 24);
	d1.Print();

	Date ret1 = d1 - 100;
	ret1.Print();

	Date ret2 = d1 - 10000;
	ret2.Print();

	Date ret3 = d1 + 100;
	ret3.Print();

	Date ret4 = d1 + 10000;
	ret4.Print();
}

void TestDate2()
{
	Date d1(2023, 10, 24);
	d1.Print();

	++d1;
	d1.operator++();
	d1.Print();

	d1++;
	d1.operator++(1);	// Ãÿ ‚¥¶¿Ì
	d1.Print();
}

void TestDate3()
{
	Date d1(2023, 10, 24);
	d1.Print();

	Date d2(2024, 5, 5);
	d2.Print();

	Date d3(2024, 8, 1);
	d3.Print();

	cout << d2 - d1 << endl;
	cout << d1 - d3 << endl;
}

void TestDate4()
{
	Date d1(2023, 10, 24);
	d1 += -100;
	d1.Print();
}

void TestDate5()
{
	Date d1(2023, 10, 24);
	Date d2(2024, 5, 5);
	Date d3(2024, 8, 1);
	Date d4(2023, 10, 24);

	if (d1 == d2)
		cout << "==" << endl;
	else
		cout << "!=" << endl;

	if (d1 > d2)
		cout << '>' << endl;
	else
		cout << "<=" << endl;
}

int main()
{
	//TestDate1();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	TestDate5();
	return 0;
}