#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
// 测试string容量相关的接口
// size/clear/resize
void Teststring1()
{
	// 注意：string类对象支持直接用cin和cout进行输入和输出
	string s("hello, string!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl << endl;

	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
	// “aaaaaaaaaa”
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	// "aaaaaaaaaa\0\0\0\0\0"
	// 注意此时s中有效字符个数已经增加到15个
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl << endl;

	// 将s中有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

//====================================================================================
void Teststring2()
{
	string s;
	// 测试reserve是否会改变string中有效元素个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

// string的遍历
// begin()+end()   for+[]  范围for
// 注意：string遍历时使用最多的还是for+下标 或者 范围for(C++11后才支持)
// begin()+end()大多数使用在需要使用STL提供的算法操作string时，比如：采用reverse逆置string
void Teststring3()
{
	string s1("hello string");
	const string s2("Hello string");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;

	// s2[0] = 'h';   代码编译失败，因为const类型对象不能修改
}

void Teststring4()
{
	string s("hello string");
	// 3种遍历方式：
	// 需要注意的以下三种方式除了遍历string对象，还可以遍历时修改string中的字符，
	// 另外以下三种方式对于string而言，第一种使用最多
	// 1. for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;

	// 2.迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	// string::reverse_iterator rit = s.rbegin();
	// C++11之后，直接使用auto定义迭代器，让编译器推导迭代器的类型
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;

	// 3.范围for
	for (auto ch : s)
		cout << ch;
	cout << endl;
}

//////////////////////////////////////////////////////////////
// 测试string：
// 1. 插入(拼接)方式：push_back  append  operator+= 
// 2. 正向和反向查找：find() + rfind()
// 3. 截取子串：substr()
// 4. 删除：erase
void Teststring5()
{
	string str;
	str.push_back(' ');				// 在str后插入空格
	str.append("hello");			// 在str后追加一个字符串"hello"
	str += 's';						// 在str后追加一个字符's'   
	str += "tring";					// 在str后追加一个字符串"tring"
	cout << str << endl;
	cout << str.c_str() << endl;	// 以C语言的方式打印字符串
	cout << endl;

	// 获取file的后缀
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;
	cout << endl;

	// npos是string里面的一个静态成员变量
	// static const size_t npos = -1;

	// 取出url中的域名
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	// 删除url的协议前缀
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}

int main()
{
	Teststring5();
	return 0;
}

// 利用reserve提高插入数据的效率，避免增容带来的开销
//====================================================================================

//void Teststring()
//{
//	string s1;				// 构造空的string类对象s1
//	string s2("hello bit"); // 用C格式字符串构造string类对象s2
//	string s3(s2);			// 拷贝构造s3
//}

union _Bxty
{ // storage for small buffer or pointer to larger one
	value_type _Buf[_BUF_SIZE];
	pointer _Ptr;
	char _Alias[_BUF_SIZE]; // to permit aliasing
} _Bx;

struct _Rep_base
{
	size_type _M_length;
	size_type _M_capacity;
	_Atomic_word _M_refcount;
};