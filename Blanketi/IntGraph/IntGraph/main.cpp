#include "Edge.h"
#include "GraphAsLists.h"
#include "LinkedNode.h"
#include <iostream>
#include "StackAsArrayInt.h"
using namespace std;

void main()
{
	GraphAsLists g;
	//int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, gg = 7, h = 8;
	/*g.insertNode(1);
	g.insertNode(2);
	g.insertNode(3);
	g.insertNode(4);
	g.insertNode(5);
	g.insertEdge(1, 3);
	g.insertEdge(1, 2);
	g.insertEdge(2, 5);
	g.insertEdge(2, 4);
	g.insertEdge(3, 5);
	g.insertEdge(4, 5);
	g.insertEdge(4, 3);
	g.print();

	int* arPath = new int[100];
	int lPath = 0;
	g.findPath(5, 2, arPath, &lPath);

	for (int i = 0; i < lPath; i++)
		cout << arPath[i] << " ";
	cout << endl;*/

	g.insertNode(9);
	g.insertNode(8);
	g.insertNode(7);
	g.insertNode(6);
	g.insertNode(5);
	g.insertNode(4);
	g.insertNode(3);
	g.insertNode(2);
	g.insertNode(1);
	g.insertEdge(1, 4, 9);
	g.insertEdge(1, 3, 5);
	g.insertEdge(1, 2, 7);
	g.insertEdge(2, 6, 5);
	g.insertEdge(2, 5, 4);
	g.insertEdge(3, 6, 3);
	g.insertEdge(4, 7, 4);
	g.insertEdge(5, 9, 3);
	g.insertEdge(5, 8, 7);
	g.insertEdge(6, 5, 2);
	g.insertEdge(6, 9, 6);
	g.insertEdge(7, 9, 7);
	g.insertEdge(8, 9, 6);

	g.print();
	LinkedNode* a = g.findNode(9);
	cout << g.canReachMoreWithUndirected(a);



	/*g.insertNode(4);
	g.insertNode(3);
	g.insertNode(2);
	g.insertNode(1);
	g.insertEdge(1, 2);
	g.insertEdge(2, 3);
	g.insertEdge(3, 4);
	g.insertEdge(4, 2);
	g.print();
	
	cout << g.printCycle();*/
}