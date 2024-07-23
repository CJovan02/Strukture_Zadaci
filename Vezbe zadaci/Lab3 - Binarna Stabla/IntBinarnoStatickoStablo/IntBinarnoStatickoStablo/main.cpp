#include "StatickoStablo.h"
#include <iostream>
using namespace std;

void main()
{
	StatickoStablo stablo(10);
	StatickoStablo* stablo2 = new StatickoStablo(10);
	stablo.ubaci(0);
	stablo.ubaci(7);
	stablo.ubaci(4);
	stablo.ubaci(9);
	stablo.ubaci(2);
	stablo.ubaci(6);
	stablo.ubaci(1);
	stablo.ubaci(5);
	
	stablo.preorder();
	stablo.dupliraj(stablo2);
	stablo2->preorder();

	delete stablo2;
}