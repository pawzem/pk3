#pragma once
#include "CascadeH.h"
#include "stdafx.h"


Cascade::Cascade(string login, string password){
	if ((login == this->alogin) && (password == this->apassword)){
		this->level = this->alevel;
	}
	else if ((login == this->ulogin) && (password == this->upassword)){
		this->level = this->ulevel;
	}
	else{
		this->level = this->dlevel;
	}
}

void Cascade::login(string login, string password){
	if ((login == this->alogin) && (password == this->apassword)){
		this->level = this->alevel;
	}
	else if ((login == this->ulogin) && (password == this->upassword)){
		this->level = this->ulevel;
	}
	else{
		this->level = this->dlevel;
	}
}

int Cascade::getLevel(){
	return this->level;
}

void Cascade::addResource(Resource* book){
	if (level <= this->ulevel)(this->lista).pushBack(book);
}

bool Cascade::borrow(string isbn){
	if (this->level >= this->ulevel)return false;
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		if (((*curr).getId() == isbn) && (*curr).isAvilible()){
			(*curr).changeStatus();
			(this->lista).resetIterator();
			return true;
		}
		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
	return false;
}

bool Cascade::unBorrow(string isbn){
	if (this->level >= this->ulevel)return false;
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		if (((*curr).getId() == isbn) && !(*curr).isAvilible()){
			(*curr).changeStatus();
			(this->lista).resetIterator();
			return true;
		}
		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
	return false;
}

void Cascade::showResources(){
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		std::cout << (*curr).getAuthor() << endl;
		std::cout << (*curr).getId() << endl;
		std::cout << (*curr).getTitle() << endl;
		std::cout << (*curr).isAvilible() << endl;
		std::cout << endl;

		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
}


void Cascade::showResource(string isbn){
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		if ((*curr).getId() == isbn){
			std::cout << (*curr).getId() << endl;
			std::cout << (*curr).getAuthor() << endl;
			std::cout << (*curr).getTitle() << endl;
			std::cout << (*curr).isAvilible() << endl;
			std::cout << endl;
		}

		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
}

Cascade::~Cascade(){
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		delete curr;
		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
}

bool Cascade::save(string file){
	std::fstream plik;
	plik.open(file, std::ios::in | std::ios::out | ios::trunc);
	if (plik.is_open() == true)
	{
		(this->lista).resetIterator();
		int s = (this->lista).getSize();
		plik << s << endl;
		for (int i = 0; i < s; ++i){
			Resource* curr = (this->lista).getIterator();

			plik << (*curr).getId() << endl;
			plik << (*curr).getAuthor() << endl;
			plik << (*curr).getTitle() << endl;
			plik << (*curr).getPosition() << endl;
			plik << (*curr).getSpec() << endl;


			if (i < s - 1)(this->lista).incIterator();
		}
		(this->lista).resetIterator();



		plik.close();
		return true;
	}
	else return false;

}

bool Cascade::init(string file){
	std::ifstream plik;
	plik.open(file);
	if (plik.is_open() == true)
	{

		string id;
		string sp, ti, au, lo;
		int s;
		plik >> s;
		for (int i = 0; i < s; i++){
			plik >> id;
			plik >> au;
			plik >> ti;
			plik >> lo;
			plik >> sp;
			Real* pom2 = new Real(id, sp, ti, au, lo);
			this->addResource(pom2);
		}



		plik.close();
		return true;
	}
	else return false;

}