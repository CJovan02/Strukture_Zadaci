#include <iostream>
using namespace std;

#include "GraphInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt g;
	g.insertNode(1);
	g.insertNode(2);
	g.insertNode(3);
	g.insertNode(4);
	g.insertNode(5);
	g.insertNode(6);
	g.insertNode(7);

	g.insertEdge(7, 1);
	g.insertEdge(1, 5);
	g.insertEdge(2, 4);
	g.insertEdge(1, 3);
	g.insertEdge(5, 6);
	g.insertEdge(5, 1);
	g.insertEdge(4, 5);
	g.insertEdge(6, 7);
	g.insertEdge(4, 3);


	g.VratiMatSusedstva();
}

