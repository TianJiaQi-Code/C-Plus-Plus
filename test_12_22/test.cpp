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

int main()
{
	Teststring4();
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