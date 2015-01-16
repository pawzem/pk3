// ProjectPK3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Definitions.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 5;
	Element<int> x(a);
	cout << x.getObject() << endl;

	/*List<int>* lista = new List<int>();
	(*lista).pushBack(a);
	(*lista).pushBack(a);
	(*lista).pushBack(a);
	(*lista).pushBack(a);
	(*lista).pullBack();
	(*lista).pullBack();
	cout << (*lista).getSize() << endl;
	delete lista;*/
	List<int> lista;
	lista.pushBack(a);
	a--;
	cout << lista.getIterator() << endl;
	//lista.incIterator();
	lista.pushBack(a);
	lista.incIterator();
	cout << lista.getIterator() << endl;
	a--;
	lista.pushBack(a);
	lista.incIterator();
	lista.pullBack();
	cout << lista.getIterator() << endl;
	a--;
	char k;
	cin >> k;


	return 0;
}

