#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
public:
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1, int month = 1, int day = 1);

	void Print();
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	// ==���������
	bool operator==(const Date& y);
	// !=���������
	bool operator!=(const Date& y);
	// >���������
	bool operator>(const Date& y);
	// >���������
	bool operator<(const Date& y);
	// >=���������
	bool operator>=(const Date& y);
	// <=���������
	bool operator<=(const Date& y);

	// ����-���� ��������
	int operator-(const Date& d);
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-=����
	Date& operator-=(int day);
	// ����-����
	Date operator-(int day);

	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);

	// ǰ��--
	Date& operator--();
	// ����--
	Date operator--(int);

private:
	int _year;
	int _month;
	int _day;
};