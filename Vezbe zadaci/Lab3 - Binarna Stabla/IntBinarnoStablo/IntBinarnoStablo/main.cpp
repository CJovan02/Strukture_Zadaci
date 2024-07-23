#include "BSTreeInt.h"
#include <iostream>
using namespace std;

void main()
{
	BSTreeInt* stablo = new BSTreeInt();

	/*stablo->insert(0);
	stablo->insert(7);
	stablo->insert(4);
	stablo->insert(9);
	stablo->insert(2);
	stablo->insert(6);
	stablo->insert(1);
	stablo->insert(5);*/

	stablo->insert(0);
	stablo->insert(7);
	stablo->insert(4);
	stablo->insert(5);
	stablo->insert(0);
	stablo->insert(4);
	stablo->insert(5);
	stablo->insert(7);

	stablo->breadthFirstSearch();
	cout << stablo->distinct();

	delete stablo;

	/*BSTreeInt* a = new BSTreeInt();
	BSTreeInt* b = new BSTreeInt();
	BSTreeInt* c = new BSTreeInt();
	
	a->insert(0);
	a->insert(7);
	a->insert(4);
	a->insert(2);
	a->insert(10);
	a->insert(11);

	b->insert(1);
	b->insert(6);
	b->insert(5);
	b->insert(9);

	a->spojiStabla(b, c);
	c->breadthFirstSearch();*/
}