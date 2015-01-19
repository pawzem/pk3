#pragma once
#include "stdafx.h"
#include "DateD.h"
class Resource
{
private:
protected:
	Resource(){};
	string id;
	string specification, title, author, localisation;
	Date returns;
	bool avilible;
public:
	Resource(string, string, string, string, string);
	string getId();
	string getSpec();
	string getTitle();
	string getAuthor();
	string getPosition();


	void setId(string);
	void setSpec(string);
	void setTitle(string);
	void setAuthor(string);
	void setPosition(string);
	//void setReturnDate(string);

	bool isAvilible();
	bool changeStatus();

	virtual void openLocation() = 0;


};