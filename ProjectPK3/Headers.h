#include<iostream>
#include<string>
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
	Date operator+ (int);
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



class Resource
{
private:
protected:
	Resource(){};
	int id;
	string specification, title, author, localisation;
	Date returns;
	bool avilible;
public:
	Resource(int, string, string, string, string);
	int getId();
	string getSpec();
	string getTitle();
	string getAuthor();
	string getPosition();


	void setId(int);
	void setSpec(string);
	void setTitle(string);
	void setAuthor(string);
	void setPosition(string);
	//void setReturnDate(string);

	bool isAvilible();
	bool changeStatus();

	virtual void openLocation() = 0;


};


class Digital: public Resource
{
public:
	Digital(int, string, string, string, string);
	void openLocation();
};

class Real : public Resource
{
private:
	Date date;
public:
	Real(int, string, string, string, string);
	Date getDate();
	void setDate(Date);
	void openLocation();
};
