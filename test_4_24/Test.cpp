#define _CRT_SECURE_NO_WARNINGS 1

//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}

//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int x1 = 1;
//	int x2{ 2 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	Point p{ 1, 2 };
//	// C++11���б��ʼ��Ҳ����������new���ʽ��
//	int* pa = new int[4] { 0 };
//	return 0;
//}

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2022, 1, 1); // old style
//	// C++11֧�ֵ��б��ʼ�����������ù��캯����ʼ��
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}

//int main()
//{
//	// the type of il is an initializer_list
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}

#include <vector>
#include <list>
#include <string>
#include <map>

//namespace tjq
//{
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T* iterator;
//
//		vector(initializer_list<T> l)
//		{
//			_start = new T[l.size()];
//			_finish = _start + l.size();
//			_endofstorage = _start + l.size();
//
//			iterator vit = _start;
//			typename initializer_list<T>::iterator lit = l.begin();
//			while (lit != l.end())
//			{
//				*vit++ = *lit++;
//			}
//		}
//
//		vector<T>& operator=(initializer_list<T> l)
//		{
//			vector<T> tmp(l);
//			std::swap(_start, tmp._start);
//			std::swap(_finish, tmp._finish);
//			std::swap(_endofstorage, tmp._endofstorage);
//
//			return *this;
//		}
//
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _endofstorage;
//	};
//}
//
//int main()
//{
//	vector<int> v = { 1,2,3,4 };
//
//	tjq::vector<int> v1{1, 2, 3, 4};
//	tjq::vector<int> v2 = { 1,2,3,4 };
//
//
//	list<int> lt = { 1,2 };
//	// ����{"sort", "����"}���ȳ�ʼ������һ��pair����
//	map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
//	// ʹ�ô����Ŷ�������ֵ
//	v = { 10, 20, 30 };
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	return 0;
//}

//// decltype��һЩʹ��ʹ�ó���
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret��������double
//	decltype(&x) p; // p��������int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}

//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void *)0)
//#endif
//#endif

//int main()
//{
//	// ���µ�p��b��c��*p������ֵ
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	// ���¼����Ƕ�������ֵ����ֵ����
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	// ���¼������ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);
//	// ���¼������Ƕ���ֵ����ֵ����
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	// �������ᱨ��error C2106: ��=��: �����������Ϊ��ֵ
//	10 = 1;
//	x + y = 1;
//	fmin(x, y) = 1;
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	rr2 = 5.5; // ����
//	return 0;
//}

//int main()
//{
//	// ��ֵ����ֻ��������ֵ������������ֵ��
//	int a = 10;
//	int& ra1 = a; // raΪa�ı���
//	//int& ra2 = 10; // ����ʧ�ܣ���Ϊ10����ֵ
//	// const��ֵ���üȿ�������ֵ��Ҳ��������ֵ��
//	const int& ra3 = 10;
//	const int& ra4 = a;
//	return 0;
//}

//int main()
//{
//	// ��ֵ����ֻ����ֵ������������ֵ��
//	int&& r1 = 10;
//	// error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
//	// message : �޷�����ֵ�󶨵���ֵ����
//	int a = 10;
//	int&& r2 = a;
//	// ��ֵ���ÿ�������move�Ժ����ֵ
//	int&& r3 = std::move(a);
//	return 0;
//}

#include <assert.h>

namespace tjq
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}


		string(const char* str = "")
			: _size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			: _str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;
			string tmp(s._str);
			swap(tmp);
		}

		//tjq::string to_string(int value)
		//{
		//	tjq::string str;
		//	// ...

		//	return str;
		//}


		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}

		// �ƶ�����
		string(string&& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};
}

namespace tjq
{
	tjq::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		tjq::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}



//tjq::string to_string(int value)
//{
//	tjq::string str;
//	// ...
//
//	return str;
//}

int main()
{
	tjq::string str = "abcdef";

	tjq::string str1(str);

	tjq::string ret = tjq::to_string(-1234);

	return 0;
}

//int main()
//{
//	// ��tjq::string to_string(int value)�����п��Կ���������ֻ��ʹ�ô�ֵ���أ�
//	// ��ֵ���ػᵼ������1�ο�������(�����һЩ��һ��ı��������������ο�������)��
//	tjq::string ret1 = tjq::to_string(1234);
//	tjq::string ret2 = tjq::to_string(-1234);
//	return 0;
//}

//void func1(tjq::string s)
//{}
//void func2(const tjq::string& s)
//{}
//int main()
//{
//	tjq::string s1("hello world");
//	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
//	func1(s1);
//	func2(s1);
//	// string operator+=(char ch) ��ֵ���ش������
//	// string& operator+=(char ch) ����ֵ����û�п��������Ч��
//	s1 += '!';
//	return 0;
//}