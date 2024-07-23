#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(5);
	ChainedScatterObject o((char*)"7", (char*)"Jovan", (char*)"Cvetkovic", 7.0);
	tablica.insert(o);

	ChainedScatterObject o2((char*)"555445777", (char*)"Jovan", (char*)"Cvetkovic", 8.0);
	ChainedScatterObject o3((char*)"A", (char*)"Jovan", (char*)"Cvetkovic", 8.0);
	ChainedScatterObject o4((char*)"K", (char*)"Jovan", (char*)"Cvetkovic", 8.0);
	tablica.insert(o2);
	tablica.insert(o3);
	tablica.insert(o4);
	tablica.insert(o4);

	tablica.print();

	if (tablica.checkIfInTable(o4))
		cout << "Upisan je u tablicu" << endl;
	else
		cout << "Nije upisan u tablicu" << endl;
}