#pragma once
#include"ResourceH.h"
#include "stdafx.h"

Resource::Resource(string i, string spe, string tit, string aut, string local) :
id(i), specification(spe), title(tit), author(aut), localisation(local), avilible(true)
{

}


string Resource::getId(){
	return this->id;
}
string Resource::getSpec(){
	return this->specification;

}
string Resource::getTitle(){
	return this->title;
}
string Resource::getAuthor(){
	return this->author;
}
string Resource::getPosition(){
	return this->localisation;
}


void Resource::setId(string dat){
	this->id = dat;
}
void Resource::setSpec(string dat){
	this->specification = dat;
}
void Resource::setTitle(string dat){
	this->title = dat;
}
void Resource::setAuthor(string dat){
	this->author = dat;
}
void Resource::setPosition(string dat){
	this->localisation = dat;
}
/*void Resource::setReturnDate(){

}*/

bool Resource::isAvilible(){
	return this->avilible;
}

bool Resource::changeStatus(){
	this->avilible = !(this->avilible);
	return this->avilible;
}

