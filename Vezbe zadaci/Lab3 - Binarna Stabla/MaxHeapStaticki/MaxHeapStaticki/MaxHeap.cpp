#include "MaxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap(int length)
{
	this->length = length;
	count = 0;
	elements = new int[length + 1];	

	/*for (int i = 0; i < length + 1; i++)
		elements[i] = -1;*/
}
MaxHeap::~MaxHeap()
{
	if (elements != NULL)
		delete[] elements;
}

void MaxHeap::insert(int el)
{
	if (length == count + 1)
		throw new exception("Heap je pun");

	int i = ++count;
	while (i > 1 && elements[i/2] < el)
	{
		elements[i] = elements[i/2];
		i /= 2;
	}
	elements[i] = el;
}

void MaxHeap::print()
{
	for (int i = 1; i < count + 1; i++)
		cout << elements[i] << " ";
	cout << endl;
}

void MaxHeap::mergeHeaps(MaxHeap& b)
{
	for (int i = 1; i < b.count + 1; i++)
		this->insert(b.elements[i]);
}

void MaxHeap::transformIntoMin()
{
	int* pom = new int[length];
	int countPom = count;
	for (int i = 0; i < length; i++)
		pom[i] = elements[i];
	delete[] elements;

	elements = new int[length];
	/*for (int i = 0; i < length + 1; i++)
		elements[i] = -1;*/
	count = 0;

	for (int i = 1; i < countPom + 1; i++)
		insertIntoMin(pom[i]);

	delete[] pom;
}

void MaxHeap::insertIntoMin(int el)
{
	if (count == length + 1)
		throw new exception("Heap je pun");

	int i = ++count;
	while (i > 1 && elements[i / 2] > el)
	{
		elements[i] = elements[i / 2];
		i /= 2;
	}
	elements[i] = el;
}