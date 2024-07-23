#pragma once
#include "ScatterObject.h"
class ChainedScatterObject :
	public ScatterObject
{
public:
	unsigned int next;
public:
	ChainedScatterObject() : ScatterObject() { next = -1; }
	ChainedScatterObject(char *k): ScatterObject(k) { next = -1; }
	ChainedScatterObject(char *k, unsigned int n) : ScatterObject(k) { next = n; }
	ChainedScatterObject(ChainedScatterObject const& obj);
	ChainedScatterObject& operator = (ChainedScatterObject const& obj);
	void print();
};

