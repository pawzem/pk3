#pragma once
#include"DateH.h"
#include "stdafx.h"

Date::Date() :day(0), year(0), month(0)
{

}



Date::Date(int d, int m, int y) :day(d), year(y), month(m)
{

}

int Date::getDay()
{
	return this->day;
}

int Date::getMonth()
{
	return this->month;
}

int Date::getYear()
{
	return this->year;
}

void Date::setDay(int x)
{
	this->day = x;
}

void Date::setYear(int x)
{
	this->year = x;
}

void Date::setMonth(int x)
{
	this->month = x;
}

Date Date::diff(Date& d)
{
	Date pom(*this);
	pom.setDay(pom.getDay() - d.getDay());
	pom.setYear(pom.getYear() - d.getYear());
	pom.setMonth(pom.getMonth() - d.getMonth());

	return pom;
}

Date Date::operator-(Date& x)
{
	return this->diff(x);
}

Date Date::operator-(int x)
{
	Date pom(*this);
	pom.setDay(pom.getDay() - x);
	pom.setYear(pom.getYear() - x);
	pom.setMonth(pom.getMonth() - x);

	return pom;
}

Date Date::operator+(int x)
{
	Date pom(*this);
	pom.setDay(pom.getDay() + x);
	pom.setYear(pom.getYear() + x);
	pom.setMonth(pom.getMonth() + x);

	return pom;
}

