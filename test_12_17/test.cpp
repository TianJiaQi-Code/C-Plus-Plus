#include <iostream>
using namespace std;

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// ������Ҫfree(p2)��
//	free(p3);
//}

//void Test()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10);
//	// ��̬����10��int���͵Ŀռ�
//	int* ptr6 = new int[3];
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
int main()
{
	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;
	// ���������Ǽ�����һ����
	int* p3 = (int*)malloc(sizeof(int)); // C
	int* p4 = new int;
	free(p3);
	delete p4;
	A* p5 = (A*)malloc(sizeof(A) * 10);
	A* p6 = new A[10];
	free(p5);
	delete[] p6;
	return 0;
}