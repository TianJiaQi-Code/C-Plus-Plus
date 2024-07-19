#include <iostream>
#include <string>
using namespace std;

//// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}

// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	p->PrintA();
	return 0;
}

//// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//};
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//
//int main()
//{
//	cout << sizeof(A1) << " " << sizeof(A2) << " " << sizeof(A3);
//}

//int main()
//{
//
//	std::string str = "";
//	for (int i = 0; i < str.size(); i++)
//	{
//		printf("%X", str[i]);
//	}
//	return 0;
//}