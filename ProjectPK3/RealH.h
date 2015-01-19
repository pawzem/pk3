#pragma once
#include "stdafx.h"
#include "ResourceD.h"
#include "DateD.h"
class Real : public Resource
{
private:
	Date date;
public:
	Real(string, string, string, string, string);
	Date getDate();
	void setDate(Date);
	void openLocation();
};
