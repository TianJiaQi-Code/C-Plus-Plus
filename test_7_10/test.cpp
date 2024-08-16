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
//    // 这里我们不需要显式地设置weakThis，但如果你想从Node内部访问自己作为weak_ptr，可以这样：  
//    // node1->weakThis = node1;  
//    // node2->weakThis = node2;  
//
//    // 现在，当main函数结束时，由于shared_ptr的计数归零，node1和node2会被销毁  
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
//    // 当main函数结束时，理论上node1和node2应该被销毁，但由于循环引用，它们不会被销毁  
//    // 这会导致内存泄漏  
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
//// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//// 对Less函数模板进行特化
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
//	cout << Less(p1, p2) << endl; // 调用特化之后的版本，而不走模板生成了
//	return 0;
//}

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

//// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
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