#include <iostream>
using namespace std;

#include "SmartPtr.h"

//int main()
//{
//	tjq::unique_ptr<int> sp1(new int);
//	tjq::unique_ptr<int> sp2(sp1);
//
//	std::unique_ptr<int> sp1(new int);
//	std::unique_ptr<int> sp2(sp1);
//
//	return 0;
//}

//int main()
//{
//	std::auto_ptr<int> sp1(new int);
//	std::auto_ptr<int> sp2(sp1); // 管理权转移
//
//	// sp1悬空
//	*sp2 = 10;
//	cout << *sp2 << endl;
//	cout << *sp1 << endl;
//	return 0;
//}