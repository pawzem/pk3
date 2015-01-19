#pragma once
#include "RealH.h"
#include "stdafx.h"

Real::Real(string i, string spe, string tit, string aut, string local)
{
	this->id = i;
	this->specification = spe;
	this->title = tit;
	this->author = aut;
	this->localisation = local;
	this->avilible = true;
}

Date Real::getDate(){
	return this->date;
}


void Real::setDate(Date dat){
	this->date = dat;
}

void Real::openLocation(){
	std::cout << this->getPosition();
}
