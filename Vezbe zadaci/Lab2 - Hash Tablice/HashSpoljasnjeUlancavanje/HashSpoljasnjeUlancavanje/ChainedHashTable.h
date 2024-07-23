#pragma once
#include "HashTable.h"
#include "HashObject.h"
#include "LList.h"
#include <iostream>
class ChainedHashTable : public HashTable
{
private:
	LList* array;
public:
	ChainedHashTable(unsigned int len);
	~ChainedHashTable();
	void insert(HashObject obj);
	void withdraw(HashObject obj);
	void withdraw(char* key);
	HashObject find(char* key);
	void print();
};

