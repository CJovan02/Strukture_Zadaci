#include "HashObject.h"
#include <iostream>
using namespace std;

HashObject::HashObject(char* k, char* v)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
	record = new char[strlen(v) + 1];
	strcpy(record, v);
}

HashObject::HashObject(const HashObject& obj)
{
	key = new char[strlen(obj.key) + 1];
	strcpy(key, obj.key);
	record = new char[strlen(obj.record) + 1];
	strcpy(record, obj.record);
}

HashObject::~HashObject()
{
	if (key)
		delete[] key;
	if (record)
		delete[] record;
}

HashObject& HashObject::operator=(const HashObject& obj)
{
	if (this != &obj)
	{
		if (key)
			delete key;
		key = new char[strlen(obj.key) + 1];
		strcpy(key, obj.key);

		if (record)
			delete record;
		record = new char[strlen(obj.record) + 1];
		strcpy(record, obj.record);
	}
	return *this;
}


bool HashObject::operator==(const HashObject& obj)
{
	return (strcmp(key, obj.key) == 0) and (strcmp(record, obj.record) == 0);
}

void HashObject::deleteRecord()
{
	if (record)
	{
		delete record;
		record = NULL;
	}
}

void HashObject::print()
{
	if (key != NULL)
		cout << key;
	if(record != NULL)
		cout << "|" << record;
}