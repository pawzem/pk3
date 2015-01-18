#ifndef PK3PROJECTH
#define PK3PROJECTH
#include<iostream>
#include<string>
#include<fstream>
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
	List(const List& );
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
	string id;
	string specification, title, author, localisation;
	Date returns;
	bool avilible;
public:
	Resource(string, string, string, string, string);
	string getId();
	string getSpec();
	string getTitle();
	string getAuthor();
	string getPosition();


	void setId(string);
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
	Digital(string, string, string, string, string);
	void openLocation();
};

class Real : public Resource
{
private:
	Date date;
public:
	Real(string, string, string, string, string);
	Date getDate();
	void setDate(Date);
	void openLocation();
};

class Cascade
{
private:
	const string ulogin = "user";
	const string upassword = "password";
	const string alogin = "admin";
	const string apassword = "admin1234";

	const int alevel=0;
	const int ulevel = 1;
	const int dlevel = 2;

	int level;

	List<Resource*> lista;

public:
	Cascade(string,string);
	~Cascade();
	void login(string, string);
	int getLevel();
	void addResource(Resource*);
	bool borrow(string);
	bool unBorrow(string);
	void showResources();
	void showResource(string);

	bool init(string);
	bool save(string);
};

#endif