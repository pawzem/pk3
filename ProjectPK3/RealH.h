#pragma once
#include "stdafx.h"
#include "ResourceD.h"
#include "DateD.h"
class Real : public Resource//klasa reprezentuj�ca fizyczne ksi��ki
{
private:
	Date date;
public:
	Real(string, string, string, string, string);//inicjalizacja parametr�w
	Date getDate();
	void setDate(Date);
	void openLocation();//wy�wietl lokacj�
};
