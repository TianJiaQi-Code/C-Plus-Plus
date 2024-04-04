#include <iostream>
using namespace std;
#include "RBTree.h"

void TestRBTree1()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();
	cout << t.IsBalance() << endl;
}

int main()
{
	TestRBTree1();
	return 0;
}