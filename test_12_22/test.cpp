#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
// ����string������صĽӿ�
// size/clear/resize
void Teststring1()
{
	// ע�⣺string�����֧��ֱ����cin��cout������������
	string s("hello, string!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl << endl;

	// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
	// ��aaaaaaaaaa��
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	// "aaaaaaaaaa\0\0\0\0\0"
	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl << endl;

	// ��s����Ч�ַ�������С��5��
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

//====================================================================================
void Teststring2()
{
	string s;
	// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

// string�ı���
// begin()+end()   for+[]  ��Χfor
// ע�⣺string����ʱʹ�����Ļ���for+�±� ���� ��Χfor(C++11���֧��)
// begin()+end()�����ʹ������Ҫʹ��STL�ṩ���㷨����stringʱ�����磺����reverse����string
void Teststring3()
{
	string s1("hello string");
	const string s2("Hello string");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;

	// s2[0] = 'h';   �������ʧ�ܣ���Ϊconst���Ͷ������޸�
}

void Teststring4()
{
	string s("hello string");
	// 3�ֱ�����ʽ��
	// ��Ҫע����������ַ�ʽ���˱���string���󣬻����Ա���ʱ�޸�string�е��ַ���
	// �����������ַ�ʽ����string���ԣ���һ��ʹ�����
	// 1. for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;

	// 2.������
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	// string::reverse_iterator rit = s.rbegin();
	// C++11֮��ֱ��ʹ��auto������������ñ������Ƶ�������������
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;

	// 3.��Χfor
	for (auto ch : s)
		cout << ch;
	cout << endl;
}

//////////////////////////////////////////////////////////////
// ����string��
// 1. ����(ƴ��)��ʽ��push_back  append  operator+= 
// 2. ����ͷ�����ң�find() + rfind()
// 3. ��ȡ�Ӵ���substr()
// 4. ɾ����erase
void Teststring5()
{
	string str;
	str.push_back(' ');				// ��str�����ո�
	str.append("hello");			// ��str��׷��һ���ַ���"hello"
	str += 's';						// ��str��׷��һ���ַ�'s'   
	str += "tring";					// ��str��׷��һ���ַ���"tring"
	cout << str << endl;
	cout << str.c_str() << endl;	// ��C���Եķ�ʽ��ӡ�ַ���
	cout << endl;

	// ��ȡfile�ĺ�׺
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;
	cout << endl;

	// npos��string�����һ����̬��Ա����
	// static const size_t npos = -1;

	// ȡ��url�е�����
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

	// ɾ��url��Э��ǰ׺
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}

int main()
{
	Teststring5();
	return 0;
}

// ����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
//====================================================================================

//void Teststring()
//{
//	string s1;				// ����յ�string�����s1
//	string s2("hello bit"); // ��C��ʽ�ַ�������string�����s2
//	string s3(s2);			// ��������s3
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