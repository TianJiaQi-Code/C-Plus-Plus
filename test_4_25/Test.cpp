#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

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
			//cout << "string(char* str)" << endl;
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

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);
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

	private:
		char* _str;
		size_t _size;
		size_t _capacity; // �������������ʶ��\0
	};


	tjq::string to_string(int value)
	{
		tjq::string str;

		str += 'a';

		return str;
	}
}



//void push_back(value_type&& val);

//int main()
//{
//	list<tjq::string> lt;
//	tjq::string s1("1111");
//
//	// ������õ��ǿ�������
//	lt.push_back(s1);
//
//	// ������ö����ƶ�����
//	lt.push_back("2222");
//	lt.push_back(std::move(s1));
//
//	return 0;
//}

//int main()
//{
//	tjq::string s1("hello world");
//	// ����s1����ֵ�����õ��ǿ�������
//	tjq::string s2(s1);
//	// �������ǰ�s1 move�����Ժ�, �ᱻ������ֵ�������ƶ�����
//	// ��������Ҫע�⣬һ���ǲ�Ҫ�����õģ���Ϊ���ǻᷢ��s1��
//	// ��Դ��ת�Ƹ���s3��s1���ÿ��ˡ�
//	tjq::string s3(std::move(s1));
//	return 0;
//}

//int main()
//{
//	tjq::string ret1;
//	ret1 = tjq::to_string(1234);
//	return 0;
//}

//int main()
//{
//	// ��tjq::string to_string(int value)�����п��Կ���������ֻ��ʹ�ô�ֵ���أ�
//	// ��ֵ���ػᵼ������1�ο�������(�����һЩ��һ��ı��������������ο�������)��
//	tjq::string ret1 = tjq::to_string(1234);
//	tjq::string ret2 = tjq::to_string(-1234);
//
//	ret1 += 'a';
//
//
//	return 0;
//}

//void func1(tjq::string s)
//{}
//
//void func2(const tjq::string& s)
//{}
//
//int main()
//{
//	tjq::string s1("hello world");
//	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
//	func1(s1);
//	func2(s1);
//
//	// string operator+=(char ch) ��ֵ���ش������
//	// string& operator+=(char ch) ����ֵ����û�п��������Ч��
//	s1 += '!';
//
//	return 0;
//}

//void Fun(int& x) { cout << "��ֵ����" << endl; }
//void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
//
//void Fun(int&& x) { cout << "��ֵ����" << endl; }
//void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
//// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
//// ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
//// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
//// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��
//
//// std::forward<T>(t)�ڴ��εĹ����б�����t��ԭ���������ԡ�
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(std::forward<T>(t));
//}
//
////template<typename T>
////void PerfectForward(T&& t)
////{
////	Fun(t);
////}
//
//int main()
//{
//	PerfectForward(10); // ��ֵ
//	int a;
//	PerfectForward(a); // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//	const int b = 8;
//	PerfectForward(b); // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//	return 0;
//}

template<class T>
struct ListNode
{
	ListNode* _next = nullptr;
	ListNode* _prev = nullptr;
	T _data;
};
template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushBack(T&& x)
	{
		//Insert(_head, x);
		Insert(_head, std::forward<T>(x));
	}
	void PushFront(T&& x)
	{
		//Insert(_head->_next, x);
		Insert(_head->_next, std::forward<T>(x));
	}
	void Insert(Node* pos, T&& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = std::forward<T>(x); // �ؼ�λ��
		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
	void Insert(Node* pos, const T& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = x; // �ؼ�λ��
		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
private:
	Node* _head;
};

//int main()
//{
//	List<tjq::string> lt;
//	lt.PushBack("1111");
//	lt.PushFront("2222");
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		: _name(name)
//		, _age(age)
//	{}
//
//	Person(const Person& p)
//		: _name(p._name)
//		, _age(p._age)
//	{}
//
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			_name = p._name;
//			_age = p._age;
//		}
//		return *this;
//	}
//
//	~Person()
//	{}
//
//private:
//	tjq::string _name;
//	int _age;
//};
//
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	Person s4;
//	s4 = std::move(s2);
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		: _name(name)
//		, _age(age)
//	{}
//	Person(const Person& p)
//		: _name(p._name)
//		, _age(p._age)
//	{}
//	Person(Person&& p) = default;
//private:
//	tjq::string _name;
//	int _age;
//};
//
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		: _name(name)
//		, _age(age)
//	{}
//	Person(const Person& p) = delete;
//private:
//	tjq::string _name;
//	int _age;
//};
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	return 0;
//}

//// Args��һ��ģ���������args��һ�������ββ�����
//// ����һ��������Args...args������������п��԰���0�������ģ�������
//template <class ...Args>
//void ShowList(Args... args)
//{}

//// �ݹ���ֹ����
//template <class T>
//void ShowList(const T& t)
//{
//	cout << t << endl;
//}
//// չ������
//template <class T, class ...Args>
//void ShowList(T value, Args... args)
//{
//	cout << value << " ";
//	ShowList(args...);
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}

//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
////չ������
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}

//template <class... Args>
//void emplace_back(Args&&... args);

//int main()
//{
//	std::list< std::pair<int, char> > mylist;
//	// emplace_back֧�ֿɱ�������õ�����pair����Ĳ������Լ�ȥ��������
//	// ��ô���������ǿ��Կ��������÷��ϣ���push_backûʲô̫�������
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//	mylist.emplace_back(make_pair(30, 'c'));
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//	return 0;
//}

//int main()
//{
//	// ����������һ�´��п���������ƶ������tjq::string����������
//	// ���ǻᷢ����ʵ���Ҳ����emplace_back��ֱ�ӹ����ˣ�push_back
//	// ���ȹ��죬���ƶ����죬��ʵҲ���á�
//	std::list< std::pair<int, tjq::string> > mylist;
//	mylist.emplace_back(10, "sort");
//	mylist.emplace_back(make_pair(20, "sort"));
//	mylist.push_back(make_pair(30, "sort"));
//	mylist.push_back({ 40, "sort" });
//
//	return 0;
//}

//#include <algorithm>
//#include <functional>
//int main()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//	// Ĭ�ϰ���С�ڱȽϣ��ų������������
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//	// �����Ҫ������Ҫ�ı�Ԫ�صıȽϹ���
//	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//	return 0;
//}

struct Goods
{
	string _name; // ����
	double _price; // �۸�
	int _evaluate; // ����
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};
struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};
struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};

int main()
{
	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
	[] {};

	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint
	int a = 3, b = 4;
	[=] { return a + 3; };

	// ʡ���˷���ֵ���ͣ��޷���ֵ����
	auto fun1 = [&](int c) { b = a + c; };
	fun1(10);
	cout << a << " " << b << endl;

	// �����ֶ������Ƶ�lambda����
	auto fun2 = [=, &b](int c) ->int { return b += a + c; };
	cout << fun2(10) << endl;

	// ���Ʋ�׽x
	int x = 10;
	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
	cout << add_x(10) << endl;

	return 0;
}

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 },
//		{ "����", 2.2, 3 }, { "����", 1.5, 4 } };
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate; });
//
//	return 0;
//}


//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 },
//		{ "����", 2.2, 3 }, { "����", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//}