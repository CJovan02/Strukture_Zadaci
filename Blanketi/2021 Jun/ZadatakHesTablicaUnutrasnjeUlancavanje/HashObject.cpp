#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	key = NULL;
	marka = NULL;
	model = NULL;
	godiste = NULL;
	redniBr = NULL;
	status = -1;
}

HashObject::HashObject(char* ma, char* mo, char* g, char* r, int s)
{
	marka = new char[strlen(ma) + 1];
	strcpy(marka, ma);

	model = new char[strlen(mo) + 1];
	strcpy(model, mo);

	godiste = new char[strlen(g) + 1];
	strcpy(godiste, g);

	redniBr = new char[strlen(r) + 1];
	strcpy(redniBr, r);

	status = s;

	key = new char[10];

	key[0] = marka[0];
	key[1] = model[0];

	key[2] = godiste[0];
	key[3] = godiste[1];
	key[4] = godiste[2];
	key[5] = godiste[3];

	key[6] = redniBr[0];
	key[7] = redniBr[1];
	key[8] = redniBr[2];
	key[9] =  '\0';
}

HashObject::~HashObject()
{
	if (key)
		delete[] key;
	if (marka)
		delete[] marka;
	if (model)
		delete[] model;
	if (godiste)
		delete[] godiste;
	if (redniBr)
		delete[] redniBr;
}

HashObject::HashObject(HashObject const& obj)
{
	key = strcpy(new char[strlen(obj.key) + 1], obj.key);
	model = strcpy(new char[strlen(obj.model) + 1], obj.model);
	marka = strcpy(new char[strlen(obj.marka) + 1], obj.marka);

	godiste = strcpy(new char[strlen(obj.godiste) + 1], obj.godiste);
	redniBr = strcpy(new char[strlen(obj.redniBr) + 1], obj.redniBr);
	status = obj.status;
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (key)
			delete key;
		key = new char[strlen(obj.key) + 1];
		strcpy(key, obj.key);

		if (model)
			delete model;
		model = new char[strlen(obj.model) + 1];
		strcpy(model, obj.model);

		if (marka)
			delete marka;
		marka = new char[strlen(obj.marka) + 1];
		strcpy(marka, obj.marka);

		if (godiste)
			delete godiste;
		godiste = strcpy(new char[strlen(obj.godiste) + 1], obj.godiste);

		if (redniBr)
			delete redniBr;
		redniBr = strcpy(new char[strlen(obj.redniBr) + 1], obj.redniBr);

		status = obj.status;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->key, obj.key) == 0) && 
		(strcmp(this->model, obj.model) == 0) &&
		(strcmp(this->marka, obj.marka) == 0) &&
		(strcmp(this->godiste, obj.godiste) == 0) &&
		(strcmp(this->redniBr, obj.redniBr) == 0) &&
		status == obj.status;
}

void HashObject::deleteRecord() {
	if (model) 
	{ 
		delete model; 
		model = NULL; 
	}
	if (marka)
	{
		delete marka;
		marka = NULL;
	}
	if (godiste)
	{
		delete godiste;
		godiste = NULL;
	}
	if (redniBr)
	{
		delete redniBr;
		redniBr = NULL;
	}
	
	status = NULL;
}

void HashObject::print()
{
	if(key!=NULL)
	{ 
		cout << key;
	}
	if (model != NULL)
	{
		cout << "|" << model;
	}
	if (marka != NULL)
	{
		cout << "|" << marka;
	}
	if (godiste != NULL)
	{
		cout << "|" << godiste;
	}
	if (redniBr != NULL)
	{
		cout << "|" << redniBr;
	}
	if (status != -1)
	{
		if(status == 1)
			cout << "|" << "Zauzet";
		else if(status == 0)
			cout << "|" << "Nije Zauzet";
	}
	cout << endl;
}