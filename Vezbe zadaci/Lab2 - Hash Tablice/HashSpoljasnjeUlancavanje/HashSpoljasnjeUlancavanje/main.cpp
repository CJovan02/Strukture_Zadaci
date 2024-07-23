#pragma once
#include"ChainedHashTable.h"

void main()
{
	ChainedHashTable tablica(20);
	HashObject o((char*)"int", (char*)"int");
	tablica.insert(o);
	HashObject o1((char*)"int", (char*)"int");
	HashObject o2((char*)"long int", (char*)"long int");
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.print();
}