#include <iostream>
using namespace std;
#include "BinarySearchTree.h"

namespace key
{
	void Test1()
	{
		BSTree<int> t;
		int a[] = { 8,3,1,10,6,4,7,14,13 };
		for (auto e : a)
		{
			t.Insert(e);
		}

		t.InOrder();

		t.Erase(8);
		t.InOrder();

		t.Erase(14);
		t.InOrder();

		t.Erase(4);
		t.InOrder();

		t.Erase(6);
		t.InOrder();
		cout << endl;

		for (auto e : a)
		{
			t.Erase(e);
			t.InOrder();
		}

		t.InOrder();
	}

	void Test2()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a)
		{
			t.InsertR(e);
		}

		t.InOrder();

		t.EraseR(8);
		t.InOrder();

		t.EraseR(14);
		t.InOrder();

		t.EraseR(4);
		t.InOrder();
		cout << endl;

		for (auto e : a)
		{
			t.EraseR(e);
			t.InOrder();
		}

		t.InOrder();
	}
}

//int main()
//{
//	//key::Test1();
//	//key::Test2();
//
//	key_value::BSTree<string, string> dict;
//	dict.Insert("sort", "����");
//	dict.Insert("left", "������");
//	dict.Insert("right", "������");
//	dict.Insert("string", "�ַ���");
//
//	string str;
//	while (cin >> str)
//	{
//		auto ret = dict.Find(str);
//		if (ret)
//		{
//			cout << ret->_value << endl;
//		}
//		else
//		{
//			cout << "����" << endl;
//		}
//	}
//
//	return 0;
//}

namespace key_value
{
	void TestBSTree1()
	{
		// ���뵥�ʣ����ҵ��ʶ�Ӧ�����ķ���
		BSTree<string, string> dict;
		dict.Insert("string", "�ַ���");
		dict.Insert("tree", "��");
		dict.Insert("left", "��ߡ�ʣ��");
		dict.Insert("right", "�ұ�");
		dict.Insert("sort", "����");
		// ����ʿ������е���
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret == nullptr)
			{
				cout << "����ƴд���󣬴ʿ���û���������:" << str << endl;
			}
			else
			{
				cout << str << "���ķ���:" << ret->_value << endl;
			}
		}
	}

	void TestBSTree2()
	{
		// ͳ��ˮ�����ֵĴ���
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
		"ƻ��", "�㽶", "ƻ��", "�㽶" };
		BSTree<string, int> countTree;
		for (const auto& str : arr)
		{
			// �Ȳ���ˮ���ڲ�����������
			// 1�����ڣ�˵��ˮ����һ�γ��֣������<ˮ��, 1>
			// 2���ڣ�����ҵ��Ľڵ���ˮ����Ӧ�Ĵ���++
			//BSTreeNode<string, int>* ret = countTree.Find(str);
			auto ret = countTree.Find(str);
			if (ret == NULL)
			{
				countTree.Insert(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}
		countTree.InOrder();
	}
}

int main()
{
	//key_value::TestBSTree1();
	key_value::TestBSTree2();
	return 0;
}