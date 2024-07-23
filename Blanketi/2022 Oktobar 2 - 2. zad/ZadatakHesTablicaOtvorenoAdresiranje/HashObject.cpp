#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	key = NULL;
	oznaka = 0;
}

HashObject::HashObject(char* k, unsigned int v)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
	oznaka = v;
}

HashObject::~HashObject()
{
	if (key)
		delete[] key;
}

HashObject::HashObject(HashObject const& obj)
{
	key = strcpy(new char[strlen(obj.key) + 1], obj.key);
	oznaka = obj.oznaka;
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (key)
			delete key;
		key = new char[strlen(obj.key) + 1];
		strcpy(key, obj.key);

		oznaka = obj.oznaka;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->key, obj.key) == 0) && (oznaka == obj.oznaka);
}

void HashObject::deleteRecord() {
	if (oznaka != 0) { oznaka = 0; } 
}

void HashObject::print()
{
	if(key!=NULL)
	{ 
		cout << key;
	}
	if (oznaka != 0)
	{
		cout << "|" << oznaka;
	}
	cout << endl;
}