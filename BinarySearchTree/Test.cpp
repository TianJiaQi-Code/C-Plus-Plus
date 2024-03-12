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
//	dict.Insert("sort", "排序");
//	dict.Insert("left", "左子树");
//	dict.Insert("right", "右子树");
//	dict.Insert("string", "字符串");
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
//			cout << "错误" << endl;
//		}
//	}
//
//	return 0;
//}

namespace key_value
{
	void TestBSTree1()
	{
		// 输入单词，查找单词对应的中文翻译
		BSTree<string, string> dict;
		dict.Insert("string", "字符串");
		dict.Insert("tree", "树");
		dict.Insert("left", "左边、剩余");
		dict.Insert("right", "右边");
		dict.Insert("sort", "排序");
		// 插入词库中所有单词
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret == nullptr)
			{
				cout << "单词拼写错误，词库中没有这个单词:" << str << endl;
			}
			else
			{
				cout << str << "中文翻译:" << ret->_value << endl;
			}
		}
	}

	void TestBSTree2()
	{
		// 统计水果出现的次数
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
		"苹果", "香蕉", "苹果", "香蕉" };
		BSTree<string, int> countTree;
		for (const auto& str : arr)
		{
			// 先查找水果在不在搜索树中
			// 1、不在，说明水果第一次出现，则插入<水果, 1>
			// 2、在，则查找到的节点中水果对应的次数++
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