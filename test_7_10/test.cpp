#include <iostream>
#include <string>
using namespace std;
#include "unique_ptr.hpp"

		int main()
		{
			cout << "Hello World!" << endl;
		}

//#include <memory>  
//#include <iostream>  
//
//class Node {
//public:
//    std::shared_ptr<Node> strongNeighbor;
//    std::weak_ptr<Node> weakThis;
//
//    Node() {}
//    ~Node() { std::cout << "Destroying Node\n"; }
//};
//
//int main() {
//    auto node1 = std::make_shared<Node>();
//    auto node2 = std::make_shared<Node>();
//
//    node1->strongNeighbor = node2;
//    node2->strongNeighbor = node1;
//
//    // �������ǲ���Ҫ��ʽ������weakThis������������Node�ڲ������Լ���Ϊweak_ptr������������  
//    // node1->weakThis = node1;  
//    // node2->weakThis = node2;  
//
//    // ���ڣ���main��������ʱ������shared_ptr�ļ������㣬node1��node2�ᱻ����  
//
//    return 0;
//}

//#include <memory>  
//#include <iostream>  
//
//class Node {
//public:
//    std::shared_ptr<Node> neighbor;
//    Node() {}
//    ~Node() { std::cout << "Destroying Node\n"; }
//};
//
//int main() {
//    auto node1 = std::make_shared<Node>();
//    auto node2 = std::make_shared<Node>();
//
//    node1->neighbor = node2;
//    node2->neighbor = node1;
//
//    // ��main��������ʱ��������node1��node2Ӧ�ñ����٣�������ѭ�����ã����ǲ��ᱻ����  
//    // ��ᵼ���ڴ�й©  
//
//    return 0;
//}

//int main()
//{
//	tjq::unique_ptr<int> sp1(new int);
//	//tjq::unique_ptr<int> sp2(sp1);
//	//tjq::unique_ptr<int> sp2 = sp1;
//
//	std::unique_ptr<int> sp3(new int);
//	//std::unique_ptr<int> sp4(sp3);
//	//std::unique_ptr<int> sp4 = sp3;
//
//	return 0;
//}

//class Date
//{};
//
//// ����ģ�� -- ����ƥ��
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//// ��Less����ģ������ػ�
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl;
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl;
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // �����ػ�֮��İ汾��������ģ��������
//	return 0;
//}

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

//// 1.�������������н���ǣ� A�����뱨�� B�����б��� C����������
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	return 0;
//}

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