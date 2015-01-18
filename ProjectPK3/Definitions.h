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
	pom.setDay(pom.getDay()-d.getDay());
	pom.setYear(pom.getYear() - d.getYear());
	pom.setMonth(pom.getMonth() - d.getMonth());

	return pom;
}

Date Date::operator-(Date& x)
{
	return this->diff(x);
}

Date Date::operator-(int x)
{
	Date pom(*this);
	pom.setDay(pom.getDay() - x);
	pom.setYear(pom.getYear() - x);
	pom.setMonth(pom.getMonth() - x);

	return pom;
}

Date Date::operator+(int x)
{
	Date pom(*this);
	pom.setDay(pom.getDay() + x);
	pom.setYear(pom.getYear() + x);
	pom.setMonth(pom.getMonth() + x);

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


Resource::Resource(int i, string spe, string tit, string aut, string local) :
id(i), specification(spe), title(tit), author(aut), localisation(local), avilible(true)
{

}


int Resource::getId(){
	return this->id;
}
string Resource::getSpec(){
	return this->specification;

}
string Resource::getTitle(){
	return this->title;
}
string Resource::getAuthor(){
	return this->author;
}
string Resource::getPosition(){
	return this->localisation;
}


void Resource::setId(int dat){
	this->id = dat;
}
void Resource::setSpec(string dat){
	this->specification = dat;
}
void Resource::setTitle(string dat){
	this->title = dat;
}
void Resource::setAuthor(string dat){
	this->author = dat;
}
void Resource::setPosition(string dat){
	this->localisation = dat;
}
/*void Resource::setReturnDate(){

}*/

bool Resource::isAvilible(){
	return this->avilible;
}

bool Resource::changeStatus(){
	this->avilible = !(this->avilible);
	return this->avilible;
}






void Digital::openLocation(){
	std::cout << this->getPosition();
}

Digital::Digital(int i, string spe, string tit, string aut, string local) 
{
	this -> id = i;
	this->specification = spe;
	this->title = tit;
	this->author = aut;
	this->localisation = local;
	this->avilible = true;
}


Real::Real(int i, string spe, string tit, string aut, string local) 
{
	this->id = i;
	this->specification = spe;
	this->title = tit;
	this->author = aut;
	this->localisation = local;
	this->avilible = true;
}

Date Real::getDate(){
	return this->date;
}


void Real::setDate(Date dat){
	this->date = dat;
}

void Real::openLocation(){
	std::cout << this->getPosition();
}


Cascade::Cascade(string login, string password){
	if ((login == this->alogin) && (password == this->apassword)){
		this->level = this->alevel;
	}
	else if ((login == this->ulogin) && (password == this->upassword)){
		this->level = this->ulevel;
	}
	else{
		this->level = this->dlevel;
	}
}

void Cascade::login(string login, string password){
	if ((login == this->alogin) && (password == this->apassword)){
		this->level = this->alevel;
	}
	else if ((login == this->ulogin) && (password == this->upassword)){
		this->level = this->ulevel;
	}
	else{
		this->level = this->dlevel;
	}
}

int Cascade::getLevel(){
	return this->level;
}

void Cascade::addResource(Resource* book){
	if(level <= this->ulevel)(this->lista).pushBack(book);
}

bool Cascade::borrow(int isbn){
	if (this->level >= this->ulevel)return false;
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		if ( ((*curr).getId() == isbn) && (*curr).isAvilible() ){
			(*curr).changeStatus();
			(this->lista).resetIterator();
			return true;
		}
		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
	return false;
}

bool Cascade::unBorrow(int isbn){
	if (this->level >= this->ulevel)return false;
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		if (((*curr).getId() == isbn) && !(*curr).isAvilible()){
			(*curr).changeStatus();
			(this->lista).resetIterator();
			return true;
		}
		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
	return false;
}

void Cascade::showResources(){
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		std::cout << (*curr).getAuthor() << endl;
		std::cout << (*curr).getId() << endl;
		std::cout << (*curr).getTitle() << endl;
		std::cout << (*curr).isAvilible() << endl;
		std::cout << endl;

		if(i < s-1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
}


void Cascade::showResource(int isbn){
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		if ((*curr).getId() == isbn){
			std::cout << (*curr).getId() << endl;
			std::cout << (*curr).getAuthor() << endl;
			std::cout << (*curr).getTitle() << endl;
			std::cout << (*curr).isAvilible() << endl;
			std::cout << endl;
		}

		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
}

 Cascade::~Cascade(){
	(this->lista).resetIterator();
	int s = (this->lista).getSize();
	for (int i = 0; i < s; ++i){
		Resource* curr = (this->lista).getIterator();
		delete curr;
		if (i < s - 1)(this->lista).incIterator();
	}
	(this->lista).resetIterator();
}

 bool Cascade::save(string file){
	 std::fstream plik;
	 plik.open(file, std::ios::in | std::ios::out | ios::trunc);
	 if (plik.is_open() == true)
	 {
		 (this->lista).resetIterator();
		 int s = (this->lista).getSize();
		 plik << s << endl;
		 for (int i = 0; i < s; ++i){
			Resource* curr = (this->lista).getIterator();

			plik << (*curr).getId() << endl;
			plik << (*curr).getAuthor() << endl;
			plik << (*curr).getTitle() << endl;
			plik << (*curr).getPosition() << endl;
			plik << (*curr).getSpec() << endl;


			 if (i < s - 1)(this->lista).incIterator();
		 }
		 (this->lista).resetIterator();


		
		 plik.close();
		return true;
	 }
	 else return false;
	 
 }

 bool Cascade::init(string file){
	 std::ifstream plik;
	 plik.open(file);
	 if (plik.is_open() == true)
	 {

		 int id;
		 string sp, ti, au, lo;
		 int s;
		 plik >> s;
		 for (int i = 0; i < s; i++){			 
			 plik >> id;
			 plik >> au;
			 plik >> ti;
			 plik >> lo;
			 plik >> sp;
			 Real* pom2 = new Real(id,sp, ti, au,lo);
			 this->addResource(pom2);
		 }



		 plik.close();
		 return true;
	 }
	 else return false;

 }

