#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	key = NULL;
}

HashObject::HashObject(char* k)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
}

HashObject::~HashObject()
{
	if (key)
		delete[] key;
}

HashObject::HashObject(HashObject const& obj)
{
	key = new char[strlen(obj.key) + 1];
	strcpy(key, obj.key);
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (key)
			delete key;
		key = new char[strlen(obj.key) + 1];
		strcpy(key, obj.key);
	}

	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(key, obj.key) == 0);
}

void HashObject::print()
{
	if (key != NULL)
		cout << key;
}