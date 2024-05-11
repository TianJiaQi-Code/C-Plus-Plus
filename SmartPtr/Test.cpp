#include <iostream>
using namespace std;

#include "SmartPtr.h"

int main()
{
	tjq::shared_ptr<int> sp1(new int);
	tjq::shared_ptr<int> sp2(sp1);
	tjq::shared_ptr<int> sp3(sp1);

	tjq::shared_ptr<int> sp4(new int);
	tjq::shared_ptr<int> sp5(sp4);

	//sp1 = sp1;
	//sp1 = sp2;

	//sp1 = sp4;
	//sp2 = sp4;
	//sp3 = sp4;

	*sp1 = 2;
	*sp2 = 3;

	return 0;
}

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