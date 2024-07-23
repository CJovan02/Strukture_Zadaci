#pragma once

#include "LinkedNode.h"

class StackAsArrayLinkedNodeInt
{
protected:
	LinkedNode** arr; 	// polje elemenata
	long size;	// velicina polja
	long top;	// indeks vrsnog elementa

public:
	StackAsArrayLinkedNodeInt(long nsize);
	~StackAsArrayLinkedNodeInt() { delete[] arr; };

	bool isEmpty() const { return (top == -1); };
	long numberOfElements() const { return (top + 1); };

	LinkedNode* getTop() const;
	void push(LinkedNode* object);
	LinkedNode* pop();
};


