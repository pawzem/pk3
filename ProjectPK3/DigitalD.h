#pragma once
#include "DigitalH.h"
#include "ResourceD.h"
#include "DateD.h"

void Digital::openLocation(){
	std::cout << this->getPosition();
}

Digital::Digital(string i, string spe, string tit, string aut, string local)
{
	this->id = i;
	this->specification = spe;
	this->title = tit;
	this->author = aut;
	this->localisation = local;
	this->avilible = true;
}

