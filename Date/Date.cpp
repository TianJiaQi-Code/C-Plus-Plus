#include "Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (_year < 1 ||
		_month < 1 || _month > 12 ||
		_day < 1 || _day > GetMonthDay(_year, _month))
	{
		Print();
		cout << "日期非法" << endl;
	}
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

bool Date::operator==(const Date& y)
{
	return _year == y._year
		&& _month == y._month
		&& _day == y._day;
}

bool Date::operator!=(const Date& y)
{
	return !(*this == y);
}

bool Date::operator>(const Date& y)
{
	if (_year > y._year)
	{
		return true;
	}
	else if (_year == y._year && _month > y._month)
	{
		return true;
	}
	else if (_year == y._year && _month == y._month && _day > y._day)
	{
		return true;
	}

	return false;
}

bool Date::operator>=(const Date& y)
{
	return *this > y || *this == y;
}

bool Date::operator<(const Date& y)
{
	return !(*this >= y);
}

bool Date::operator<=(const Date& y)
{
	return !(*this > y);
}

int Date::GetMonthDay(int year, int month)
{
	assert(year >= 1 && month >= 1 && month <= 12);

	int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;

	return monthArray[month];
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);

		++_month;

		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;

	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}

	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;

	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;

	return tmp;
}

int Date::operator-(const Date& d)
{
	// 假设左大右小
	int flag = 1;
	Date max = *this;
	Date min = d;

	// 假设错了，左小右大
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}