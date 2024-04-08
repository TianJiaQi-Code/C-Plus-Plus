#include <iostream>
#include <string>
using namespace std;
#include "RBTree.h"
#include "MySet.h"
#include "MyMap.h"

namespace tjq
{
	void TestSet1()
	{
		set<int> s;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		for (auto e : a)
		{
			s.insert(e);
		}

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void TestMap1()
	{
		map<int, int> m;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		for (auto e : a)
		{
			m.insert(make_pair(e, e));
		}

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			//it->first += 100;
			it->second += 100;
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}

	void TestMap2()
	{
		string arr[] = { "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï",
"Æ»¹û", "Ïã½¶", "Æ»¹û", "Î÷¹Ï", "Ïã½¶", "²ÝÝ®" };
		map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}

int main()
{
	//tjq::TestSet1();
	//tjq::TestMap1();
	tjq::TestMap2();
	return 0;
}