#pragma once
#include "stdafx.h"
template<class T>
class Element//klasa do trzymania element�w w li�cie
{
private:
	T object;
	Element<T>* next;//nast�pny element
public:
	Element(T&);//konstruktor od elementu przechowanego
	void setNext(Element*);//setery i getery
	Element<T>* getNext();
	T getObject();
	void setObject(T&);

};