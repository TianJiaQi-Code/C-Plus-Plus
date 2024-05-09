#include <iostream>
using namespace std;

// ʹ��RAII˼����Ƶ�SmartPtr��
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}
	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}
private:
	T* _ptr;
};
int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("��0����");
	return a / b;
}
void Func()
{
	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2(new int);
	cout << div() << endl;
}
int main()
{
	try {
		Func();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//	return a / b;
//}
//void Func()
//{
//	 1�����p1����new ���쳣����Σ�
//	 2�����p2����new ���쳣����Σ�
//	 3�����div���������ֻ����쳣����Σ�
//	int* p1 = new int;
//	int* p2 = new int;
//	cout << div() << endl;
//	delete p1;
//	delete p2;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
//
//void MemoryLeaks()
//{
//	 1.�ڴ������������ͷ�
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	 2.�쳣��ȫ����
//	int* p3 = new int[10];
//	Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.
//	delete[] p3;
//}