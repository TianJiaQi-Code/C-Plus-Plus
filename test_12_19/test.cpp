#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//#include <windows.h>
//
//int main()
//{
//	int input[100] = { 0 };
//	int i = 0;
//
//	int len = 0;
//	printf("Ҫ���ܵ��ַ����ж೤��");
//	scanf("%d", &len);
//
//	printf("\n�����룺");
//	for (i = 0; i < len / 2; i++)
//	{
//		scanf("%2xd", &input[i]);
//	}
//
//	printf("\n���ܽ����");
//	for (i = 0; i < len / 2; i++)
//	{
//		printf("%c", input[i]);
//		Sleep(1000);
//	}
//
//	return 0;
//}

//using namespace std;
//
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//......

//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//	Add(a1, d1);
//	*/
//	// ��ʱ�����ִ�����ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
//	Add(a, (int)d);
//	return 0;
//}

//int main(void)
//{
//	int a = 10;
//	double b = 20.0;
//	// ��ʽʵ����
//	Add<int>(a, b);
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}

//template<class T1, class T2, ..., class Tn>
//class ��ģ����
//{
//	// ���ڳ�Ա����
//};

// ��̬˳���
// ע�⣺Vector���Ǿ�����࣬�Ǳ��������ݱ�ʵ�������������ɾ������ģ��
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	// ʹ������������ʾ�������������������ⶨ�塣
	~Vector();
	void PushBack(const T& data);
	void PopBack();
	// ...
	size_t Size() { return _size; }
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>
Vector<T>::~Vector()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}

// Vector������Vector<int>��������
Vector<int> s1;
Vector<double> s2;