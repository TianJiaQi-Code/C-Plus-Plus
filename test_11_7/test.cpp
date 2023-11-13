// 计算日期到天数转换
//#include <iostream>
//using namespace std;
//
//int GetMonthDay(int year, int month)
//{
//    int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//        return 29;
//
//    return monthArray[month];
//}
//
//int main()
//{
//    int year, month, day;
//    cin >> year >> month >> day;
//
//    int days = day;
//    while (--month)
//    {
//        days += GetMonthDay(year, month);
//    }
//
//    cout << days;
//}

// 日期差值
//#include <iostream>
//using namespace std;
//
//bool isMax(int year1, int month1, int day1, int year2, int month2, int day2)
//{
//	if (year1 > year2)
//		return true;
//	else if (year1 == year2)
//	{
//		if (month1 > month2)
//			return true;
//		else if (month1 == month2)
//		{
//			if (day1 > day2)
//				return true;
//		}
//	}
//
//	return false;
//}
//
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int GetMonthDay(int year, int month)
//{
//	int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		return 29;
//	return monthArray[month];
//}
//
//int main()
//{
//	int year1, month1, day1;
//	int year2, month2, day2;
//	scanf("%4d%2d%2d", &year1, &month1, &day1);
//	scanf("%4d%2d%2d", &year2, &month2, &day2);
//
//	int count = 1;
//
//	// 找出较大的日期
//	if (!isMax(year1, month1, day1, year2, month2, day2))
//	{
//		Swap(year1, year2);
//		Swap(month1, month2);
//		Swap(day1, day2);
//	}
//
//	// 让小日期自增到大日期
//	while (year1 != year2 || month1 != month2 || day1 != day2)
//	{
//		++count;
//		++day2;
//
//		if (day2 > GetMonthDay(year2, month2))
//		{
//			day2 = 1;
//			month2++;
//			if (month2 > 12)
//			{
//				month2 = 1;
//				year2++;
//			}
//		}
//	}
//
//	cout << count << endl;
//	return 0;
//}

// 打印日期
#include <iostream>
using namespace std;

int GetMonthDay(int year, int month)
{
    int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        return 29;
    return monthArray[month];
}

int main()
{
    int m, n;
    cin >> m >> n;

    int month = 1;
    while (n > GetMonthDay(m, month))
    {
        n -= GetMonthDay(m, month);
        ++month;

        if (month > 12)
        {
            ++m;
            month = 1;
        }
    }

    printf("%4d-%02d-%02d", m, month, n);
}