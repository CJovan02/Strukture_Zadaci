#include "Graph.h"
#include <iostream>
using namespace std;

void main()
{
	Graph g(10);
	g.dodajCvor(1);
	g.dodajCvor(2);
	g.dodajCvor(3);
	g.dodajCvor(4);
	g.dodajCvor(5);
	g.dodajVezu(1, 2);
	g.dodajVezu(1, 3);
	g.dodajVezu(2, 4);
	g.dodajVezu(2, 5);
	g.dodajVezu(3, 5);
	g.dodajVezu(4, 5);
	g.dodajVezu(4, 3);
	g.print();
	cout << g.isStronglyConnected();
}