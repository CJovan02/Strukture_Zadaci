#pragma once
#include <iostream>
using namespace std;
class Radnik
{
private:
	char* ime, * jmbg;
public:
	Radnik();
	Radnik(char* j, char* i);
	~Radnik();
	char* getIme() { return ime; }
	char* getJmbg() { return jmbg; }
	friend ostream& operator<<(ostream& os, const Radnik& obj);
	Radnik& operator=(const Radnik& obj);
	bool operator==(const Radnik& obj);
	Radnik(const Radnik& obj);
	void print();
};