#pragma once
#include "Edge.h"
#include <iostream>
using namespace std;
class Edge;

class LinkedNode
{
public:
	int node; // info
	LinkedNode* next; // sledeci cvor
	Edge* adj; //niz susednih grana
	int status; //da li je obradjen ili ne

public:
	LinkedNode()
	{
		next = NULL;
		adj = NULL;
	}

	LinkedNode(int nodeN)
	{
		node = nodeN;
		next = NULL;
		adj = NULL;
	}

	LinkedNode(int nodeN, Edge* adjN, LinkedNode* nextN)
	{
		node = nodeN;
		next = nextN;
		adj = adjN;
	}

	LinkedNode(int nodeN, Edge* adjN, LinkedNode* nextN, int statusN)
	{
		node = nodeN;
		next = nextN;
		adj = adjN;
		status = statusN;
	}

	void visit() { cout << node << " "; }

	//path
	LinkedNode* prev;

	//Dijkstra
	double distance;
};

