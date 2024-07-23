#pragma once

#include "LinkedEdgeInt.h"

class LinkedNodeInt
{
public:
	int node; //info deo
	LinkedEdgeInt* adj; //sused
	LinkedNodeInt* next; //koji je sledeci
	int status; //(ne)obradjen/smesten

	LinkedNodeInt();
	LinkedNodeInt(int nodeN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN, int statusN);

	void visit();
};
