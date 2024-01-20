#include <iostream>
#include "vector.h"

using namespace std;

namespace tjq
{
	void TestVector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it1 = v.begin();
		while (it1 != v.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector2()
	{
		vector<int> v1(10, 1);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2(v1.begin(), v1.end());
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		string s1("12345");
		vector<int> v3(s1.begin(), s1.end());
		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector3()
	{
		vector<int> v;
		for (size_t i = 0; i < 100; i++)
		{
			v.push_back(i);
		}

		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(10);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.reserve(10);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
	}

	void TestVector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin(), 0);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		// 要求删除所有的偶数
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector6()
	{
		vector<string> vstr;
		vstr.push_back("1111");
		vstr.push_back("1111");
		vstr.push_back("1111");
		vstr.push_back("1111");
		vstr.push_back("1111");

		for (auto e : vstr)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

int main()
{
	//tjq::TestVector1();
	//tjq::TestVector2();
	//tjq::TestVector3();
	//tjq::TestVector4();
	//tjq::TestVector5();
	tjq::TestVector6();

	return 0;
}