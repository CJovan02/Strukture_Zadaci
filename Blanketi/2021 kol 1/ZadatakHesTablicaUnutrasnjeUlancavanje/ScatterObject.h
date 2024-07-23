#pragma once
#include "HashObject.h"
#include "Radnik.h"
class ScatterObject :
	public HashObject
{
	
public:
	int status; //0-slobodan, 1-obrisan, 2-zauzet
	ScatterObject();
	ScatterObject(char* k, char* v);
	ScatterObject(ScatterObject const& obj);
	ScatterObject& operator = (ScatterObject const& obj);
};

