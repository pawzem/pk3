#include<iostream>
using namespace std;

class Date
{
private:
	int year, month, day;
public:
	Date();
	Date(int, int, int);
	Date diff(Date&);
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	Date operator- (Date&);
	Date operator- (int);
};



class AList
{
private:
protected:
	unsigned int size;
public:
	virtual bool empty() = 0;
};


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
	void pushBack(T&);
	void pullBack();
	T getIterator();
	T incIterator();
	void resetIterator();
};