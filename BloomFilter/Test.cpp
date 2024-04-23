#include <iostream>
#include <vector>
using namespace std;
#include "BloomFilter.h"

void TestBloomFilter1()
{
	string strs[] = { "�ٶ�", "�ֽ�", "��Ѷ" };
	BloomFilter<10> bf;
	for (auto& s : strs)
	{
		bf.Set(s);
	}

	for (auto& s : strs)
	{
		cout << bf.Test(s) << endl;
	}

	for (auto& s : strs)
	{
		cout << bf.Test(s + 'a') << endl;
	}

	cout << bf.Test("�ڶ�") << endl;
	cout << bf.Test("�ٶ�") << endl;
}

void TestBloomFilter2()
{
	srand(time(0));
	const size_t N = 10000000;
	BloomFilter<N> bf;

	vector<string> v1;
	std::string url = "��˽�";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + to_string(i));
	}

	for (auto& str : v1)
	{
		bf.Set(str);
	}

	vector<string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		string urlstr = url;
		urlstr += to_string(9999999 + i);
		v2.push_back(urlstr);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.Test(str))	// ����
		{
			++n2;
		}
	}
	cout << "�����ַ��������ʣ�" << (double)n2 / (double)N << endl;

	// �����Ƶ��ַ�����
	vector<string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "�����";
		url += to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.Test(str))
		{
			++n3;
		}
	}
	cout << "�������ַ���������" << (double)n3 / (double)N << endl;
}

int main()
{
	//TestBloomFilter1();
	TestBloomFilter2();
	return 0;
}