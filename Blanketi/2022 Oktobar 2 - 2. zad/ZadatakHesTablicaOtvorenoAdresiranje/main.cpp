#include"OpenScatterTable.h"

void main()
{
	OpenScatterTable tablica(10);
	ScatterObject o((char*)"20.11.2022 11.32.01", 654);
	tablica.insert(o);
	ScatterObject o1((char*)"11.01.2022 10.02.11", 123);
	ScatterObject o2((char*)"20.11.2022 11.32.01", 654);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.print();
}