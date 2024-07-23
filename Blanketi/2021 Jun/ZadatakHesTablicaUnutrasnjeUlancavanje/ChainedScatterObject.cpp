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
	if (getMarka() != NULL)
	{
		cout << "|" << getMarka();
	}
	if (getModel() != NULL)
	{
		cout << "|" << getModel();
	}
	if (getGodiste() != NULL)
	{
		cout << "|" << getGodiste();
	}
	if (getRedniBr() != NULL)
		cout << "|" << getRedniBr();

	if (getStatus() != -1)
	{
		if (getStatus() == 1)
			cout << "|" << "Zauzet";
		else if(getStatus() == 0)
			cout << "|" << "Nije Zauzet";
	}

	cout << "|" << next << endl;
}