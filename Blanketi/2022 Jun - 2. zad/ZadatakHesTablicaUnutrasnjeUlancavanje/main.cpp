#include"ChainedScatterTable.h"
#include "ChainedScatterObject.h"

void main()
{
	ChainedScatterTable tablica(5);
	ChainedScatterObject o1("19elfcspr001");
	ChainedScatterObject o2("19elfcspr002");
	ChainedScatterObject o3("19elfcspr003");

	tablica.insert(o1);
	tablica.insert(o2);
	tablica.insert(o3);
	tablica.insert(o3);
	tablica.insert(o3);

	tablica.print();
	//cout << endl << endl;

	//tablica.deleteObj(o3);
	////tablica.insert(o1);
	//tablica.print();
	//cout << endl << endl;
	ChainedScatterObject rez = tablica.find("19elfcspr003");
	rez.print();

}