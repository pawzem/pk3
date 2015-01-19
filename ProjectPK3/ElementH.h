#pragma once
#include "stdafx.h"
template<class T>
class Element//klasa do trzymania elementów w liœcie
{
private:
	T object;
	Element<T>* next;//nastêpny element
public:
	Element(T&);//konstruktor od elementu przechowanego
	void setNext(Element*);//setery i getery
	Element<T>* getNext();
	T getObject();
	void setObject(T&);

};