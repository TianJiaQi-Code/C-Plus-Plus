#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
public:
	// 全缺省的构造函数
	Date(int year = 1, int month = 1, int day = 1);

	void Print();
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);

	// ==运算符重载
	bool operator==(const Date& y);
	// !=运算符重载
	bool operator!=(const Date& y);
	// >运算符重载
	bool operator>(const Date& y);
	// >运算符重载
	bool operator<(const Date& y);
	// >=运算符重载
	bool operator>=(const Date& y);
	// <=运算符重载
	bool operator<=(const Date& y);

	// 日期-日期 返回天数
	int operator-(const Date& d);
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 日期-天数
	Date operator-(int day);

	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);

	// 前置--
	Date& operator--();
	// 后置--
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
};