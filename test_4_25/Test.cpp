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

		// 拷贝构造
		string(const string& s)
			: _str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
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

		// 移动构造
		string(string&& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动语义" << endl;
			swap(s);
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动语义" << endl;
			swap(s);
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
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
//	// 这里调用的是拷贝构造
//	lt.push_back(s1);
//
//	// 下面调用都是移动构造
//	lt.push_back("2222");
//	lt.push_back(std::move(s1));
//
//	return 0;
//}

//int main()
//{
//	tjq::string s1("hello world");
//	// 这里s1是左值，调用的是拷贝构造
//	tjq::string s2(s1);
//	// 这里我们把s1 move处理以后, 会被当成右值，调用移动构造
//	// 但是这里要注意，一般是不要这样用的，因为我们会发现s1的
//	// 资源被转移给了s3，s1被置空了。
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
//	// 在tjq::string to_string(int value)函数中可以看到，这里只能使用传值返回，
//	// 传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷贝构造)。
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
//	// func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
//	func1(s1);
//	func2(s1);
//
//	// string operator+=(char ch) 传值返回存在深拷贝
//	// string& operator+=(char ch) 传左值引用没有拷贝提高了效率
//	s1 += '!';
//
//	return 0;
//}

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
//// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
//// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
//// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发
//
//// std::forward<T>(t)在传参的过程中保持了t的原生类型属性。
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
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(std::move(b)); // const 右值
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
		newnode->_data = std::forward<T>(x); // 关键位置
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
		newnode->_data = x; // 关键位置
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

//// Args是一个模板参数包，args是一个函数形参参数包
//// 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
//template <class ...Args>
//void ShowList(Args... args)
//{}

//// 递归终止函数
//template <class T>
//void ShowList(const T& t)
//{
//	cout << t << endl;
//}
//// 展开函数
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
////展开函数
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
//	// emplace_back支持可变参数，拿到构建pair对象的参数后自己去创建对象
//	// 那么在这里我们可以看到除了用法上，和push_back没什么太大的区别
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
//	// 下面我们试一下带有拷贝构造和移动构造的tjq::string，再试试呢
//	// 我们会发现其实差别也不大，emplace_back是直接构造了，push_back
//	// 是先构造，再移动构造，其实也还好。
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
//	// 默认按照小于比较，排出来结果是升序
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//	// 如果需要降序，需要改变元素的比较规则
//	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//	return 0;
//}

struct Goods
{
	string _name; // 名字
	double _price; // 价格
	int _evaluate; // 评价
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
	// 最简单的lambda表达式, 该lambda表达式没有任何意义
	[] {};

	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
	int a = 3, b = 4;
	[=] { return a + 3; };

	// 省略了返回值类型，无返回值类型
	auto fun1 = [&](int c) { b = a + c; };
	fun1(10);
	cout << a << " " << b << endl;

	// 各部分都很完善的lambda函数
	auto fun2 = [=, &b](int c) ->int { return b += a + c; };
	cout << fun2(10) << endl;

	// 复制捕捉x
	int x = 10;
	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
	cout << add_x(10) << endl;

	return 0;
}

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 },
//		{ "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
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
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 },
//		{ "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//}