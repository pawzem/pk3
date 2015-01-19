// ProjectPK3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CascadeD.h"
#include "RealD.h"
//#include "Definitions.h"

int main(int argc, char* argv[])
{
	if (argc !=2)return 0;
	string log, pas;
	cout << "Podaj login\n";
	cin >> log;

	cout << "Podaj has�o\n";
	cin >> pas;
	string file(argv[1]);

	Cascade libary(log,pas);
	
	libary.init(file);
	
	char what='0';

	while (what != 'q'){
		cout << "co chcesz zrobi�?\n 1 wy�wietl\n 2 wyporzycz\n 3 oddaj \n q koniec \n";
		if (libary.getLevel() == 0)cout << " 4 dodaj ksi��k� \n";
		cin >> what;
		if (what == '1'){
			libary.showResources();
		}
		else if (what == '2'){
			cout << "Podaj numer isbn\n";
				string n;
				cin >> n;
				if(libary.borrow(n))cout<<"wypo�yczono\n";
				else cout << "nie wypo�yczono\n";
		}
		else if (what == '3'){
			cout << "Podaj numer isbn\n";
			string n;
			cin >> n;
			if (libary.unBorrow(n))cout << "oddano\n";
			else cout << "nie oddano\n";
		}
		else if ( (what == '4') && (libary.getLevel() == 0) ){
			string id;
			string sp, ti, au, lo;
			cout << "podaj isbn";
			cin >> id;
			cout << "podaj autora";
			cin >> au;
			cout << "podaj tytu�";
			cin >> ti;
			cout << "podaj lokalizacj�";
			cin >> lo;
			cout << "podaj opis";
			cin >> sp;
			Real* pom2 = new Real(id, sp, ti, au, lo);
			libary.addResource(pom2);

		}
		else if (what == 'q'){
			cout << "Do widzenia";
		}
		else cout << "z�a komenda";

	}
		
		
		


	libary.save(file);
	return 0;
}

