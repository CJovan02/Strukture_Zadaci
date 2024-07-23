#include "LList.h"
#include "LListNode.h"
#include <iostream>

using namespace std;

void main()
{
	LList lista;
	LList* rez = new LList();

	lista.addToTail(1);
	lista.addToTail(4);
	lista.addToTail(2);
	lista.addToTail(3);
	lista.addToTail(4);
	lista.addToTail(6);
	lista.addToTail(6);
	lista.addToTail(8);
	lista.addToTail(4);
	lista.addToTail(8);
	lista.addToTail(8);
	lista.addToTail(1);
	
	cout << "Lista pre promene: " << endl;
	lista.printAll();

	cout << "Lista nakon promene: " << endl;
	rez = lista.SplitOrMove3();
	lista.printAll();
	cout << endl;
	rez->printAll();

	delete rez;
}