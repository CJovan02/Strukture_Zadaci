#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* key;
public:
	HashObject();
	HashObject(char* k);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	char* getKey() { return key; }
	bool isEqualKey(char* k) { return strcmp(key,k)==0; }
	void print();
};