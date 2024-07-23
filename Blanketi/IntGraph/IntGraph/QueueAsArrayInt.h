#pragma once

#include "LinkedNode.h"

class QueueAsArrayLinkedNodeInt
{
protected:
	LinkedNode** arr;	// polje elemenata
	long size;			// velidina polja
	long head;			// indeks pocetnog elementa
	long tail;			// indeks krajnjeg elementa
	long numOfElements;	// broj elemenata u redu

public:
	QueueAsArrayLinkedNodeInt(long nsize);
	~QueueAsArrayLinkedNodeInt() { delete[] arr; }

	bool isEmpty() const { return (numOfElements == 0); }
	long numberOfElements() const { return numOfElements; }

	LinkedNode* getHead() const;
	void enqueue(LinkedNode* object);
	LinkedNode* dequeue();
};


