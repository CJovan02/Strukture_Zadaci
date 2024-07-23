#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* key;
	char* marka, * model;
	char* godiste, * redniBr;
	int status;
public:
	HashObject();
	HashObject(char* ma, char* mo, char* g, char* r, int s);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	char* getKey() { return key; }
	char* getMarka() { return marka; }
	char* getModel() { return model; }
	char* getGodiste() { return godiste; }
	char* getRedniBr() { return redniBr; }
	int getStatus() { return status; }
	void setStatus(int s) { status = s; }
	bool isEqualKey(char* k) { return strcmp(key,k)==0; }
	void print();
};