#include"Headers.h" 

//Date

Date::Date() :day(0), year(0), month(0)
{
	
}



Date::Date(int d, int m, int y) :day(d), year(y), month(m)
{
	
}

int Date::getDay()
{
	return this->day;
}

int Date::getMonth()
{
	return this->month;
}

int Date::getYear()
{
	return this->year;
}

void Date::setDay(int x)
{
	this->day = x;
}

void Date::setYear(int x)
{
	this->year = x;
}

void Date::setMonth(int x)
{
	this->month = x;
}

Date Date::diff(Date& d)
{
	Date pom(*this);
	pom.setDay(pom.getDay-d.getDay);
	pom.setYear(pom.getYear - d.getYear);
	pom.setMonth(pom.getMonth - d.getMonth);

	return pom;
}

Date Date::operator-(Date& x)
{
	return this->diff(x);
}

Date Date::operator-(int x)
{
	Date pom(*this);
	pom.setDay(pom.getDay - x);
	pom.setYear(pom.getYear - x);
	pom.setMonth(pom.getMonth - x);

	return pom;
}


//Element

template<class T>  Element<T>::Element(T& obj){
	this->object = obj;
	this->next = nullptr;
};

template<class T> T Element<T>::getObject(){
	return  this->object;
};

template<class T> void Element<T>::setObject(T& obj){
	this->object = obj;
	return;
};

template<class T> Element<T>* Element<T>::getNext(){
	return  this->next;
};

template<class T> void Element<T>::setNext(Element<T> * ele){
	  this->next = ele;
	  return;
};


//list

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

template<class T> void List<T>::pushBack(T& ele)
{
	Element<T>* act = new Element<T>(ele);

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
