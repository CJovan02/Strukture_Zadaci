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
	if (m == count)
		throw new exception("Tablica je puna");

	unsigned int index = h(obj.getKey());

	if (array[index].status == 2) //zauzet
	{
		while (array[index].status == 2 && array[index].next != 0 && array[index].next != -1)
			index = array[index].next;

		if (array[index].next == 0)
			throw new exception("Popunjen prostor za sinonime");

		array[index].next = lrmp;
		index = lrmp;
		lrmp = array[index].next;
	}

	array[index] = obj;
	array[index].status = 2; //zauzet
	array[index].next = -1;
	count++;
}

void ChainedScatterTable::deleteObj(ChainedScatterObject obj)
{
	unsigned int index = h(obj.getKey());

	if (array[index].status < 2)
		throw new exception("Element se ne nalazi u tablici");

	if (count == 0)
		throw new exception("Tablica je prazna");

	if (array[index].getKey() != obj.getKey())
	{
		while (array[index].status == 2 && array[index].next != 0 && array[index].next != -1)
			index = array[index].next;
	}

	array[index].status = 1;
	count--;
}

void ChainedScatterTable::print()
{
	for (unsigned int i = 0; i < 2 * m; i++)
	{
		if (i == m)
			cout << "---------------------------------------" << endl;
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

