#pragma once
#include "stdafx.h"
#include "ResourceD.h"
#include "DateD.h"
class Real : public Resource//klasa reprezentuj¹ca fizyczne ksi¹¿ki
{
private:
	Date date;
public:
	Real(string, string, string, string, string);//inicjalizacja parametrów
	Date getDate();
	void setDate(Date);
	void openLocation();//wyœwietl lokacjê
};
