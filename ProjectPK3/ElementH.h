#pragma once
#include "stdafx.h"
template<class T>
class Element
{
private:
	T object;
	Element<T>* next;
public:
	Element(T&);
	void setNext(Element*);
	Element<T>* getNext();
	T getObject();
	void setObject(T&);

};