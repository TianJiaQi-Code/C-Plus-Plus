#include <iostream>
#include <vector>
using namespace std;
#include "HashTable.h"

namespace open_address
{
	void TestHT1()
	{
		int a[] = { 1,4,24,34,7,44,17,37 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		for (auto e : a)
		{
			auto ret = ht.Find(e);
			if (ret)
			{
				cout << ret->_kv.first << ":E" << endl;
			}
			else
			{
				cout << e << ":D" << endl;
			}
		}
		cout << endl;

		ht.Erase(34);
		ht.Erase(4);
		for (auto e : a)
		{
			auto ret = ht.Find(e);
			if (ret)
			{
				cout << ret->_kv.first << ":E" << endl;
			}
			else
			{
				cout << e << ":D" << endl;
			}
		}
	}

	void TestHT2()
	{
		HashTable<string, string> dict;
		dict.Insert(make_pair("sort", "ÅÅÐò"));
		dict.Insert(make_pair("string", "×Ö·û´®"));
	}
}

int main()
{
	//open_address::TestHT1();
	open_address::TestHT2();
	return 0;
}