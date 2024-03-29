//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//	T1 first;
//	T2 second;
//	pair() : first(T1()), second(T2())
//	{}
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//};

//#include <iostream>
//using namespace std;
//
//#include <set>
//void TestSet()
//{
//	// ������array�е�Ԫ�ع���set
//	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
//	cout << s.size() << endl;
//	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	// ʹ�õ����������ӡset�е�Ԫ��
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	// set��ֵΪ3��Ԫ�س����˼���
//	cout << s.count(3) << endl;
//}
//
//int main()
//{
//	TestSet();
//	return 0;
//}

#include <iostream>
using namespace std;

//#include <string>
//#include <map>
//void TestMap()
//{
//	map<string, string> m;
//	// ��map�в���Ԫ�صķ�ʽ��
//	// ����ֵ��<"peach","����">����map�У���pairֱ���������ֵ��
//	m.insert(pair<string, string>("peach", "����"));
//	// ����ֵ��<"peach","����">����map�У���make_pair�����������ֵ��
//	m.insert(make_pair("banan", "�㽶"));
//	// ����operator[]��map�в���Ԫ��
//	/*
//	operator[]��ԭ���ǣ�
//	��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map��
//	���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ�����
//	���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ�����
//	operator[]�������insert����ֵ��ֵ���е�value����
//	*/
//	// ��<"apple", "">����map�У�����ɹ�������value�����ã�����ƻ������ֵ�������ý����
//	m["apple"] = "ƻ��";
//	// key������ʱ���쳣
//	//m.at("waterme") = "ˮ����";
//	cout << m.size() << endl;
//	// �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key���������
//	for (auto& e : m)
//		cout << e.first << "--->" << e.second << endl;
//	cout << endl;
//	// map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ��
//	auto ret = m.insert(make_pair("peach", "��ɫ"));
//	if (ret.second)
//		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
//	else
//		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->"
//		<< ret.first->second << " ����ʧ��" << endl;
//	// ɾ��keyΪ"apple"��Ԫ��
//	m.erase("apple");
//	if (1 == m.count("apple"))
//		cout << "apple����" << endl;
//	else
//		cout << "apple������" << endl;
//}

#include <set>
void TestSet()
{
	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7, 1, 1, 2, 2, 2 };
	// ע�⣺multiset�ڵײ�ʵ�ʴ洢����<int, int>�ļ�ֵ��
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
	return;
}

int main()
{
	TestSet();
	return 0;
}