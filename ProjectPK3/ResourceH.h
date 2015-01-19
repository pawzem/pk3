#pragma once
#include "stdafx.h"
#include "DateD.h"
class Resource//reprezentuje obiekt trzymany w bibliotece
{
private:
protected:
	Resource(){};
	string id;
	string specification, title, author, localisation;
	Date returns;
	bool avilible;
public:
	Resource(string, string, string, string, string);//ustawiwa pola
	string getId();//setery i getery
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

	bool isAvilible();//czy da siê wypo¿yczyæ
	bool changeStatus();//wypo¿ycz/oddaj

	virtual void openLocation() = 0;


};