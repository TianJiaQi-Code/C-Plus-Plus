#include <iostream>
#include <vector>
using namespace std;
#include "BitSet.h"


namespace tjq
{
	void test_bitset()
	{
		bitset<100> bs1;
		bs1.set(50);
		bs1.set(30);
		bs1.set(90);

		for (size_t i = 0; i < 100; i++)
		{
			if (bs1.test(i))
			{
				cout << i << "->" << "在" << endl;
			}
			else
			{
				//cout << i << "->" << "不在" << endl;
			}
		}
		bs1.reset(90);
		bs1.set(91);

		cout << endl << endl;

		for (size_t i = 0; i < 100; i++)
		{
			if (bs1.test(i))
			{
				cout << i << "->" << "在" << endl;
			}
			else
			{
				//cout << i << "->" << "不在" << endl;
			}
		}
	}

	void test_bitset2()
	{
		int a[] = { 5,7,9,2,5,99,5,5,7,5,3,9,2,55,1,5,6 };
		two_bit_set<100> bs;
		for (auto e : a)
		{
			bs.set(e);
		}

		for (size_t i = 0; i < 100; i++)
		{
			if (bs.test(i))
			{
				cout << i << endl;
			}
		}
	}
}

int main()
{
	//tjq::test_bitset();
	tjq::test_bitset2();

	return 0;
}