#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* key;
	unsigned int oznaka;
public:
	HashObject();
	HashObject(char* k, unsigned int v);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	char* getKey() { return key; }
	unsigned int getOznaka() { return oznaka; }
	bool isEqualKey(char* k) { return strcmp(key,k)==0; }
	void print();
};