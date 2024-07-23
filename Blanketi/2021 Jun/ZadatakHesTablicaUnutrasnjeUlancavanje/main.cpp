#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(5);

	ChainedScatterObject o("Peugeot", "508", "2013", "003", 0);
	ChainedScatterObject o1("Merz", "A Klasa", "2018", "002", 0);
	ChainedScatterObject o2("Audi", "A3", "2013", "001", 0);

	tablica.insert(o);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.updateStatus(1, "AA2013001");

	tablica.print();
}