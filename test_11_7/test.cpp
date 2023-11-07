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
    int year, month, day;
    cin >> year >> month >> day;

    int days = day;
    for (int i = 1; i < month; i++)
    {
        days += GetMonthDay(year, month);
    }

    cout << days;
}