#include <iostream>
#include <string>
using namespace std;

//// 1.�������������н���ǣ� A�����뱨�� B�����б��� C����������
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

// 1.�������������н���ǣ� A�����뱨�� B�����б��� C����������
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

//// ���м��г�Ա���������г�Ա����
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//};
//// ���н��г�Ա����
//class A2 {
//public:
//	void f2() {}
//};
//// ����ʲô��û��---����
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