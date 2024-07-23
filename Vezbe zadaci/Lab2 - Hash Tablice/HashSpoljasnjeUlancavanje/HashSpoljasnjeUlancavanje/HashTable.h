#pragma once
#include <iostream>
class HashTable
{
protected:
	unsigned int m;
	unsigned int count;
protected:
	unsigned int h(char* key);
	unsigned int f(char* key);
	unsigned int g(unsigned int key);
public:
	unsigned int getLength() { return m; };
};

