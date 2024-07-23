#include <iostream>
#pragma once
class HashObject
{
private:
	char* key;
	char* record;
public:
	HashObject() { key = NULL; record = NULL; };
	HashObject(char* k, char* v);
	HashObject(const HashObject& obj);
	~HashObject();
	HashObject& operator=(const HashObject& obj);
	bool operator==(const HashObject& obj);
	void deleteRecord();
	char* getKey() { return key; };
	char* getRecord() { return record; };
	bool isEqualKey(char* k) { return strcmp(key, k) == 0; };
	void print();
};

