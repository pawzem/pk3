#pragma once
#include "AListH.h"
#include "ElementD.h"
template<class T>
class List : public AList//klasa do reprezentacji listy jednkierunkowej
{
private:
	Element<T> *begin,/* *end,*/ *iterator;

public:
	bool empty();
	unsigned int getSize();
	List();//inicjalizuje pust�
	~List();//destruktor
	List(const List&);
	void pushBack(T&);
	void pullBack();
	T getIterator();
	T incIterator();
	void resetIterator();//ustawia iterator na pocz�tek
};