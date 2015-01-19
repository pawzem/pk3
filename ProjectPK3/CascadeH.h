#pragma once
#include "stdafx.h"
#include "ListD.h"
#include "ResourceD.h"
#include "RealD.h"
class Cascade//klasa do realizacji wzorca kaskada
{
private:
	const string ulogin = "user";//dane uzytkownikow
	const string upassword = "password";//
	const string alogin = "admin";
	const string apassword = "admin1234";

	const int alevel = 0;//poziomy uprawnien
	const int ulevel = 1;
	const int dlevel = 2;

	int level;

	List<Resource*> lista;//lista ksi¹¿ek

public:
	Cascade(string, string);
	~Cascade();
	void login(string, string);//zaloguj
	int getLevel();//pobierz poziom uprawnieñ
	void addResource(Resource*);//dodaj ksi¹¿ke
	bool borrow(string);//po¿ycz
	bool unBorrow(string);//oddaj
	void showResources();//poka¿ wszystkie ksi¹¿ki
	void showResource(string);//poka¿ jedn¹

	bool init(string);//zainicjalizuj listê
	bool save(string);//zapisz bibliotekê
};