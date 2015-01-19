#pragma once
#include "stdafx.h"
class Date
{
private:
	int year, month, day;
public:
	Date();//tak jak Date(0,0,0)
	Date(int, int, int);//ustawia dzien, miesiac rok
	Date diff(Date&);//roznica dar
	int getYear();//pobieranie parametru
	int getMonth();
	int getDay();
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	Date operator- (Date&);//jak diff
	Date operator- (int);//odejmuje sta³¹
	Date operator+ (int);//dodaje sta³¹
};