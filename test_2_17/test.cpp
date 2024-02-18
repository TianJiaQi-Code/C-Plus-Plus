#include <iostream>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
///* 继承后父类的Person的成员（成员函数 + 成员变量）都会变成子类的一部分。这里体现出了
//Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可
//以看到变量的复用。调用Print可以看到成员函数的复用。 */
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//
//	return 0;
//}

// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化
class Person
{
public:
	void Print()
	{
		cout << _name << endl;
	}
protected:
	string _name; // 姓名
private:
	int _age; // 年龄
};
//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected:
	int _stunum; // 学号
};