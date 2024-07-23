#include "Radnik.h"
#include <iostream>
using namespace std;

Radnik::Radnik()
{
	jmbg = NULL;
	ime = NULL;
}
Radnik::Radnik(char* j, char* i)
{
	jmbg = new char[strlen(j) + 1];
	strcpy(jmbg, j);
	ime = new char[strlen(i) + 1];
	strcpy(ime, i);
}
Radnik::~Radnik()
{
	if (ime)
		delete[] ime;
	if (jmbg)
		delete[] jmbg;
}

ostream& operator<<(ostream& os, const Radnik& obj)
{
	if (obj.jmbg != NULL)
		os << obj.jmbg;
	if (obj.ime != NULL)
		os << "|" << obj.ime;

	return os;
}

Radnik::Radnik(const Radnik& obj)
{
	jmbg = new char[strlen(obj.jmbg) + 1];
	strcpy(jmbg, obj.jmbg);

	ime = new char[strlen(obj.ime) + 1];
	strcpy(ime, obj.ime);
}

Radnik& Radnik::operator=(const Radnik& obj)
{
	if (this != &obj)
	{
		if (jmbg)
			delete jmbg;
		jmbg = new char[strlen(obj.jmbg) + 1];
		strcpy(jmbg, obj.jmbg);

		if (ime)
			delete ime;
		ime = new char[strlen(obj.ime) + 1];
		strcpy(ime, obj.ime);
	}
	return *this;
}

bool Radnik::operator==(const Radnik& obj)
{
	return (strcmp(jmbg, obj.jmbg) == 0 && strcmp(ime, obj.ime) == 0);
}

void Radnik::print()
{
	if (jmbg != NULL)
		cout <<  jmbg;
	if (ime != NULL)
		cout << "|"<< ime;
}