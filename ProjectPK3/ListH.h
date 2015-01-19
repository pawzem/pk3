#pragma once
#include "AListH.h"
#include "ElementD.h"
template<class T>
class List : public AList
{
private:
	Element<T> *begin,/* *end,*/ *iterator;

public:
	bool empty();
	unsigned int getSize();
	List();
	~List();
	List(const List&);
	void pushBack(T&);
	void pullBack();
	T getIterator();
	T incIterator();
	void resetIterator();
};