#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;


//// 为了和标准库区分，此处使用String
//class String
//{
//public:
//	//String()
//	//	:_str(new char[1])
//	//{
//	//	*_str = '\0';
//	//}
//	
//	//String(const char* str = "\0")	// 错误示范
//	//String(const char* str = nullptr)	// 错误示范
//
//	String(const char* str = "")
//	{
//		// 构造String类对象时，如果传递nullptr指针，可以认为程序非
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//
//// 测试
//void TestString()
//{
//	String s1("hello bit!!!");
//	String s2(s1);
//}

//class String
//{
//public:
//	String(const char* str = "")
//	{
//		// 构造String类对象时，如果传递nullptr指针，可以认为程序非
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	String(const String& s)
//		: _str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			char* pStr = new char[strlen(s._str) + 1];
//			strcpy(pStr, s._str);
//			delete[] _str;
//			_str = pStr;
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp._str);
	}
	// 对比下和上面的赋值那个实现比较好？
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		String strTmp(s);
	//		swap(_str, strTmp._str);
	//	}
	//	return *this;
	//}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

int main()
{
	//TestString();
	return 0;
}