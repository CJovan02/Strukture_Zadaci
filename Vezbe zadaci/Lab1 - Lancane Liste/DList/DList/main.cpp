#include "DList.h"
#include "DLNode.h"
#include <iostream>
using namespace std;

void main()
{
	DList list;
	list.AddSorted(2);
	list.Print();
	list.AddSorted(4);
	list.Print();
	list.AddSorted(3);
	list.Print();
	list.AddSorted(4);
	list.Print();
	list.AddSorted(1);

	list.Print();
}