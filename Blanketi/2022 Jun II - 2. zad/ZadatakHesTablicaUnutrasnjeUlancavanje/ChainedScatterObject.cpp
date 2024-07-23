#include "ChainedScatterObject.h"


ChainedScatterObject::ChainedScatterObject(ChainedScatterObject const& obj): ScatterObject(obj)
{
	next = obj.next;
}

ChainedScatterObject& ChainedScatterObject::operator = (ChainedScatterObject const& obj)
{
	if (this != &obj)
	{
		(ScatterObject&)(*this) = obj;
		next = obj.next;
	}
	return *this;
}

void ChainedScatterObject::print()
{
	if (getKey() != NULL)
	{
		cout << getKey();
	}
	if (getIme() != NULL)
	{
		cout << "|" << getIme();
	}
	if (getPrezime() != NULL)
	{
		cout << "|" << getPrezime();
	}
	if (getProsek() != 0)
	{
		cout << "|" << getProsek();
	}
	cout << "|" << next << endl;
}