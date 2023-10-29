//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//// C语言没办法解决类似这样的命名冲突问题，所以C++提出了namespace来解决
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}
//// 编译后后报错：error C2365: “rand”: 重定义；以前的定义是“函数”

//// bit是命名空间的名字，一般开发中是用项目名字做命名空间名。
//// 我们上课用的是bit，大家下去以后自己练习用自己名字缩写即可，如张三：zs
//// 1. 正常的命名空间定义
//namespace bit
//{
//	// 命名空间中可以定义变量/函数/类型
//	int rand = 10;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
////2. 命名空间可以嵌套
//// test.cpp
//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
////3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
//// ps：一个工程中的test.h和上面test.cpp中两个N1会被合并成一个
//// test.h
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}

//namespace bit
//{
//	// 命名空间中可以定义变量/函数/类型
//	int a = 0;
//	int b = 1;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//int main()
//{
//	// 编译报错：error C2065: “a”: 未声明的标识符
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	printf("%d\n", N::a);
//	return 0;
//}

//using N::b;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}

//using namespce N;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	Add(10, 20);
//	return 0;
//}

//#include<iostream>
//// std是C++标准库的命名空间名，C++将标准库的定义实现都放到这个命名空间中
//using namespace std;
//int main()
//{
//	cout << "Hello world!!!" << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a;
//	double b;
//	char c;
//	// 可以自动识别变量的类型
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}
//// ps：关于cout和cin还有很多更复杂的用法，比如控制浮点数输出精度，控制整形输出进制格式等
//// 等。因为C++兼容C语言的用法，这些又用得不是很多，我们这里就不展开学习了。后续如果有需要，我
//// 们再配合文档学习。

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(); // 没有传参时，使用参数的默认值
//	Func(10); // 传参时，使用指定的实参
//	return 0;
//}

//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}

//void Func(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}

////a.h
//void Func(int a = 10);
//// a.cpp
//void Func(int a = 20)
//{}
//// 注意：如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该
//用那个缺省值。

#include<iostream>
using namespace std;
// 1、参数类型不同
int Add(int left, int right)
{
	cout << "int Add(int left, int right)" << endl;
	return left + right;
}
double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;
	return left + right;
}
// 2、参数个数不同
void f()
{
	cout << "f()" << endl;
}
void f(int a)
{
	cout << "f(int a)" << endl;
}
// 3、参数类型顺序不同
void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}
void f(char b, int a)
{
	cout << "f(char b, int a)" << endl;
}
int main()
{
	Add(10, 20);
	Add(10.1, 20.2);
	f();
	f(10);
	f(10, 'a');
	f('a', 10);
	return 0;
}