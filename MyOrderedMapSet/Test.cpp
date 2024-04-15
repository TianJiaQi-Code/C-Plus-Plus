#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "HashTable.h"
#include "MyOrderedMap.h"
#include "MyOrderedSet.h"

namespace tjq
{
	void test_set1()
	{
		unordered_set<int> us;
		us.insert(3);
		us.insert(1);
		us.insert(5);
		us.insert(15);
		us.insert(45);
		us.insert(7);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_map1()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "ÅÅĞò"));
		dict.insert(make_pair("left", "×ó"));
		dict.insert(make_pair("right", "ÓÒ"));

		for (auto& kv : dict)
		{
			kv.second += 'y';

			cout << kv.first << ":" << kv.second << endl;
		}
	}
}

int main()
{
	//tjq::test_set1();
	tjq::test_map1();
	return 0;
}