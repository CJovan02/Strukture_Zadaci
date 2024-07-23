#pragma once
#include "ScatterObject.h"
class ChainedScatterObject :
	public ScatterObject
{
public:
	unsigned int next;
public:
	ChainedScatterObject() : ScatterObject() { next = -1; }
	ChainedScatterObject(char* k, char* ime, char* prezime, float prosek) : ScatterObject(k, ime, prezime, prosek) { next = -1; }
	ChainedScatterObject(char* k, char* ime, char* prezime, float prosek, unsigned int n) : ScatterObject(k, ime, prezime, prosek) { next = n; }
	ChainedScatterObject(ChainedScatterObject const& obj);
	ChainedScatterObject& operator = (ChainedScatterObject const& obj);
	void print();
};

