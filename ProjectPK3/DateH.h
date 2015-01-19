#pragma once
#include "stdafx.h"
class Date
{
private:
	int year, month, day;
public:
	Date();
	Date(int, int, int);
	Date diff(Date&);
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	Date operator- (Date&);
	Date operator- (int);
	Date operator+ (int);
};