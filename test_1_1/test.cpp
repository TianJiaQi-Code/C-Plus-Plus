#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;


//// Ϊ�˺ͱ�׼�����֣��˴�ʹ��String
//class String
//{
//public:
//	//String()
//	//	:_str(new char[1])
//	//{
//	//	*_str = '\0';
//	//}
//	
//	//String(const char* str = "\0")	// ����ʾ��
//	//String(const char* str = nullptr)	// ����ʾ��
//
//	String(const char* str = "")
//	{
//		// ����String�����ʱ���������nullptrָ�룬������Ϊ�����
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
//// ����
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
//		// ����String�����ʱ���������nullptrָ�룬������Ϊ�����
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
	// �Ա��º�����ĸ�ֵ�Ǹ�ʵ�ֱȽϺã�
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