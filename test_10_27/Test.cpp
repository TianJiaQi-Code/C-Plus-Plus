//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//// C����û�취�������������������ͻ���⣬����C++�����namespace�����
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}
//// �����󱨴�error C2365: ��rand��: �ض��壻��ǰ�Ķ����ǡ�������

//// bit�������ռ�����֣�һ�㿪����������Ŀ�����������ռ�����
//// �����Ͽ��õ���bit�������ȥ�Ժ��Լ���ϰ���Լ�������д���ɣ���������zs
//// 1. �����������ռ䶨��
//namespace bit
//{
//	// �����ռ��п��Զ������/����/����
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
////2. �����ռ����Ƕ��
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
////3. ͬһ��������������ڶ����ͬ���Ƶ������ռ�,����������ϳ�ͬһ�������ռ��С�
//// ps��һ�������е�test.h������test.cpp������N1�ᱻ�ϲ���һ��
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
//	// �����ռ��п��Զ������/����/����
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
//	// ���뱨��error C2065: ��a��: δ�����ı�ʶ��
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
//// std��C++��׼��������ռ�����C++����׼��Ķ���ʵ�ֶ��ŵ���������ռ���
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
//	// �����Զ�ʶ�����������
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}
//// ps������cout��cin���кܶ�����ӵ��÷���������Ƹ�����������ȣ���������������Ƹ�ʽ��
//// �ȡ���ΪC++����C���Ե��÷�����Щ���õò��Ǻܶ࣬��������Ͳ�չ��ѧϰ�ˡ������������Ҫ����
//// ��������ĵ�ѧϰ��

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10); // ����ʱ��ʹ��ָ����ʵ��
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
//// ע�⣺��������붨��λ��ͬʱ���֣�ǡ������λ���ṩ��ֵ��ͬ���Ǳ��������޷�ȷ�����׸�
//���Ǹ�ȱʡֵ��

#include<iostream>
using namespace std;
// 1���������Ͳ�ͬ
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
// 2������������ͬ
void f()
{
	cout << "f()" << endl;
}
void f(int a)
{
	cout << "f(int a)" << endl;
}
// 3����������˳��ͬ
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