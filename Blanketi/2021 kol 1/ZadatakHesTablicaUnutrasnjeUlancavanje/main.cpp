#include "ChainedScatterTable.h"
#include "Radnik.h"

void main()
{
	ChainedScatterTable tablica(10);

	ChainedScatterObject o((char*)"123456789", (char*)"Jovan");
	ChainedScatterObject o1((char*)"2706985730058", (char*)"Jovan1");
	ChainedScatterObject o2((char*)"2907982750051", (char*)"Jovan2");

	tablica.insert(o);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);

	tablica.print();
}