#include "string.h"

namespace tjq
{
	void TestString1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2(s1);
		cout << s2.c_str() << endl;

		string s3 = "hello string";
		cout << s3.c_str() << endl;
		cout << s3.size() << endl;
	}

	void TestString2()
	{
		string s1("hello string");
		cout << s1.c_str() << endl;
		cout << s1[2] << endl;
		s1[5] = '-';
		cout << s1.c_str() << endl;

		const string s2("hello world");
		cout << s2[1] << endl;
		// s2[5] = '+';	// error C3892：不能给常量赋值
	}

	void TestString3()
	{
		string s1("hello string");
		cout << s1 << endl;

		s1.push_back('x');
		cout << s1 << endl;

		s1.append(" xxx");
		cout << s1 << endl;

		s1 += 'y';
		cout << s1 << endl;

		s1 += " yyy";
		cout << s1 << endl;
	}

	void TestString4()
	{
		string s1("hello string");
		cout << s1 << endl;

		s1.insert(0, 'x');
		cout << s1 << endl;

		s1.insert(0, "yyy");
		cout << s1 << endl;

		s1.erase(1, 2);
		cout << s1 << endl;

		s1.erase(1, -1);
		cout << s1 << endl;

		string s2("hehe");
		s1.swap(s2);
		cout << s1 << endl;
		cout << s2 << endl;
	}

	void TestString5()
	{
		string s1("hello string");
		cout << s1 << endl;
		cout << s1.find('s', 0) << endl;
		cout << s1.find("rin", 1) << endl;
		cout << s1.find("rins", 1) << endl;

		string s2(s1.substr(1, 4));
		cout << s2 << endl;

		string s3 = "";
		cout << s3 << endl;
		cin >> s3;
		cout << s3 << endl;

		//cout << s3._capacity << ' ' << s3._size << endl;
		//s3.clear();
		//cout << s3._capacity << ' ' << s3._size << endl;
	}
}

int main()
{
	//tjq::TestString1();
	//tjq::TestString2();
	//tjq::TestString3();
	//tjq::TestString4();
	//tjq::TestString5();
	return 0;
}