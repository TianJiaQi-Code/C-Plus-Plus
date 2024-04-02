#include <iostream>
using namespace std;
#include "AVLTree.h"

void TestAVLTree1()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
		cout << e << "->" << t.IsBalance() << endl;
	}

	t.InOrder();
	cout << t.IsBalance() << endl;
}

void TestAVLTree2()
{
	const int N = 1000000;
	vector<int> v;
	v.reserve(N);
	srand((unsigned int)time(0));

	for (int i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
		//cout << v.back() << endl;
	}

	size_t begin2 = clock();
	AVLTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	size_t end2 = clock();

	cout << "Insert:" << end2 - begin2 << endl;

	cout << t.IsBalance() << endl;

	cout << "Height:" << t.Height() << endl;
	cout << "Size:" << t.Size() << endl;

	size_t begin1 = clock();
	// ȷ���ڵ�ֵ
	for (auto e : v)
	{
		t.Find(e);
	}

	// ���ֵ
	for (int i = 0; i < N; i++)
	{
		t.Find((rand() + i));
	}

	size_t end1 = clock();

	cout << "Find:" << end1 - begin1 << endl;
}

int main()
{
	//TestAVLTree1();
	TestAVLTree2();
	return 0;
}