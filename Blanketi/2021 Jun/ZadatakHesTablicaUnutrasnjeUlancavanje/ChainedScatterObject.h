#pragma once
#include "ScatterObject.h"
class ChainedScatterObject :
	public ScatterObject
{
public:
	unsigned int next;
public:
	ChainedScatterObject() : ScatterObject() { next = -1; }
	ChainedScatterObject(char* ma, char* mo, char* g, char* r, int s) : ScatterObject(ma, mo, g, r, s) { next = -1; }
	ChainedScatterObject(char* ma, char* mo, char* g, char* r, int s, unsigned int n) : ScatterObject(ma, mo, g, r, s) { next = n; }
	ChainedScatterObject(ChainedScatterObject const& obj);
	ChainedScatterObject& operator = (ChainedScatterObject const& obj);
	void print();
};

