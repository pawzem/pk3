#pragma once
#include"ListH.h"
template<class T> bool List<T>::empty()
{
	return (this->size > 0);
}

template<class T> List<T>::List()
{
	this->begin = nullptr;
	//this->end = nullptr;
	this->iterator = nullptr;
	this->size = 0;
}

template<class T> List<T>::~List()
{
	Element<T>* pom = this->begin;
	Element<T>* nst;

	if (pom != nullptr)
	{
		while ((*pom).getNext() != nullptr)
		{
			nst = (*pom).getNext();
			delete pom;
			pom = nst;
		}
		delete pom;
	}


}

template<class T> List<T>::List(const List& lis)
{
	this->size = lis.getSize();
	Element<T>* act = lis->begin;
	while (act != nullptr){
		this->pushBack((*act).getObject());
		act = (*act).getNext();
	}
	this->resetIterator();
}



template<class T> void List<T>::pushBack(T& ele)
{
	Element<T>* act;
	try{
		act = new Element<T>(ele);
	}
	catch (exception& e){
		cout << e.what() << endl;
		return;
	}

	Element<T>* pom = this->begin;

	if (pom == nullptr)
	{
		this->begin = act;
		this->iterator = this->begin;
	}
	else
	{
		while ((*pom).getNext() != nullptr) pom = (*pom).getNext();

		(*pom).setNext(act);

	}
	this->size++;
}

template<class T> void List<T>::pullBack()
{

	Element<T>* pom = this->begin;
	Element<T>* prev = pom;

	if (pom != nullptr)
	{
		while ((*pom).getNext() != nullptr){
			prev = pom;
			pom = (*pom).getNext();
		}
		delete pom;
		(*prev).setNext(nullptr);
		this->size--;
		resetIterator();
	}
}

template<class T> unsigned int List<T>::getSize()
{
	return this->size;
}

template<class T> T List<T>::getIterator()
{
	return (*(this->iterator)).getObject();
}

template<class T> void List<T>::resetIterator()
{
	this->iterator = this->begin;
}


template<class T> T List<T>::incIterator()
{
	this->iterator = (*(this->iterator)).getNext();
	return (*(this->iterator)).getObject();
}
