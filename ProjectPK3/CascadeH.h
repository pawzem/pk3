#pragma once
#include "stdafx.h"
#include "ListD.h"
#include "ResourceD.h"
#include "RealD.h"
class Cascade
{
private:
	const string ulogin = "user";
	const string upassword = "password";
	const string alogin = "admin";
	const string apassword = "admin1234";

	const int alevel = 0;
	const int ulevel = 1;
	const int dlevel = 2;

	int level;

	List<Resource*> lista;

public:
	Cascade(string, string);
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