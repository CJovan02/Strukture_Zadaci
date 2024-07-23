#pragma once
#include "Edge.h"
#include "LinkedNode.h"
#include <queue>
#include <vector>
#include <functional>

class GraphAsLists
{
protected:
	LinkedNode* start; //head za ll. cvorova
	int nodeNum; //broj cvorova

public:
	GraphAsLists();
	~GraphAsLists();

	void insertNode(int pod);
	bool insertEdge(int a, int b, double w = 0);

	LinkedNode* findNode(int pod);
	Edge* findEdge(int a, int b);

	bool deleteNode(int pod);
	bool deleteEdge(int a, int b);

	void print();

	void SetStatusForAllNodes(int status);

	long breadthFirstTraversal(int data);
	
	long depthFirstTraversalIterative(int data);
	long dfs(int first);
	long dfs(LinkedNode* ptr);
	
	long topologicalOrderTravrsal();

	// ---------------------------------------------------------------------------
	// -------------------------- priprema za lab vezbu --------------------------
	// ---------------------------------------------------------------------------
	long findPath(int first, int last, int* arPath, int* lPath);
	long findPath(LinkedNode* ptr, LinkedNode* pEnd, int* arPath, int* lPath);

	//detekcija ciklusa - topolosko (za orjentisane grafove), bfs (radi samo za neorjentisane), dfs (mora rekurzivno)
	bool isCycleTopological();

	bool isCycleBfs();
	bool isCycleDfs();
	bool isCycleDfs(LinkedNode* ptr);

	//prikaz jednog ciklusa
	bool printCycle();
	bool printCycle(LinkedNode* ptr, vector<LinkedNode*>& cycle);


	//najkraci put Dijkstra
	long shortestPathDijkstra(int data);

	//najkraci put izmedju 2 cvora
	long shortestPath(int a, int b);

	//1. zad
	LinkedNode* maxInDeg();
	LinkedNode* maxInDeg2(); //gluplji nacin

	//2. zad
	LinkedNode* maxOutDeg();
	LinkedNode* maxOutDeg2(); //gluplji nacin

	//3. zad
	int countZeroIn();
	int countZeroIn2();

	//4. zad
	int countZeroOut();
	int countZeroOut2();

	//5.zad
	bool stronglyConnected();

	//6. zad
	int** adjescentMatrix();

	// ----------------------------------------------------------------------------
	// --------------------------------- blanketi ---------------------------------
	// ----------------------------------------------------------------------------

	//oktobar2 2022
	bool pathExists(LinkedNode* a, LinkedNode* b, LinkedNode* c, LinkedNode* d);

	//jun2 2022
	int reachableInNHoops(LinkedNode* a, int n);

	//septembar 2020
	void makeUndirected();
	bool isWeaklyConnected();

	//oktobar 2021
	bool canReachMoreWithUndirected(LinkedNode* a);
};
