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
		throw new exception("Tablica je puna");

	unsigned int index = h(obj.getKey());

	if (array[index].status == 2)  //zauzet
	{
		while (array[index].status == 2 && array[index].next != -1 && array[index].next != 0)
		{
			index = array[index].next;
		}
		
		if (array[index].next == 0)
			throw new exception("Prostor za sinomime je pun");

		array[index].next = lrmp;
		index = lrmp;
		lrmp = array[index].next;
	}

	array[index] = obj;
	array[index].status = 2; //zauzet
	array[index].next = -1;
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

void ChainedScatterTable::updateStatus(int s, char* key)
{
	if (s == 1)
	{
		unsigned int probe = h(key);
		while (probe != -1)
		{
			if (!array[probe].isEqualKey(key))
				probe = array[probe].next;
			else
				break;
		}

		array[probe].setStatus(1);

		if(probe != h(key))
		{
			unsigned int tmp = h(key);
			ChainedScatterObject tmpObj = array[tmp];
			array[tmp] = array[probe];
			array[probe] = tmpObj;
		}
	}
	else if (s == 0)
	{
		unsigned int probe = h(key);
		while (probe != -1)
		{
			if (!array[probe].isEqualKey(key))
				probe = array[probe].next;
			else
				break;
		}

		array[probe].setStatus(0);
	}
}