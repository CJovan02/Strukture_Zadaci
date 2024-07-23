#include "ChainedScatterTable.h"

ChainedScatterTable::ChainedScatterTable(unsigned int length)
{
	m = length;
	count = 0;
	lrmp = m;
	array = new ChainedScatterObject[2*m];
	for (int i = m; i < 2 * m - 1; i++)
	{
		array[i].next = i + 1;
	}
	array[2 * m - 1].next = 0;
}


ChainedScatterTable::~ChainedScatterTable()
{
	delete[] array;
}

void ChainedScatterTable::insert(ChainedScatterObject obj)
{
	if (count == m)
		throw new exception("Tablica je puna!");
	unsigned int probe = h(obj.getKey());
	if (array[probe].status == 2)
	{
		if (strcmp(obj.getKey(), array[probe].getKey()) == 0)
		{
			cout << "Vec postoji element sa istim kljucem" << endl;
			return;
		}
		while (array[probe].status == 2 && array[probe].next != -1 && array[probe].next != 0)
		{
			probe = array[probe].next;
			if (strcmp(obj.getKey(), array[probe].getKey()) == 0)
			{
				cout << "Vec postoji element sa istim kljucem" << endl;
				return;
			}
		}

		if (array[probe].next == 0)
			throw new exception("Izdvojeni prostor za sinonime je pun!");
		array[probe].next = lrmp;
		probe = lrmp;
		lrmp = array[probe].next;
	}
	array[probe] = obj;
	array[probe].status = 2; // zauzet
	array[probe].next = -1;
	count++;
}


//TODO: proverava da li je student vec upisan u hash tablicu
bool ChainedScatterTable::checkIfInTable(ChainedScatterObject obj)
{
	unsigned int hash = h(obj.getKey());
	unsigned int probe = hash;

	if (array[probe].status == 2)
	{
		while (array[probe].status == 2 && array[probe].next != 0 && array[probe].next != -1)
		{
			if (strcmp(obj.getKey(), array[probe].getKey()) == 0)
				return true;
			probe = array[probe].next;
		}
	}
	return false;
}

void ChainedScatterTable::print()
{
	for (unsigned int i = 0; i < 2 * m; i++)
	{
		if (i == m)
			cout << "---------------------------------------" <<endl;
		cout << i << " ";
		array[i].print();
	}
}

ChainedScatterObject ChainedScatterTable::find(char* key)
{
	unsigned int probe = h(key);
	while (probe != -1)
	{
		if (!array[probe].isEqualKey(key))
			probe = array[probe].next;
		else
			return array[probe];
	}
	return ChainedScatterObject();
}

