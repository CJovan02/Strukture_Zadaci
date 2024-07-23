#include "LinkedNode.h"
#include <iostream>
using namespace std;

LinkedNode::LinkedNode()
{
	next = NULL;
	adj = NULL;
}

LinkedNode::LinkedNode(int nodeN)
{
	node = nodeN;
	next = NULL;
	adj = NULL;
}

LinkedNode::LinkedNode(int nodeN, LinkedNode* nextN, Edge* adjN)
{
	node = nodeN;
	next = nextN;
	adj = adjN;
}

LinkedNode::LinkedNode(int nodeN, LinkedNode* nextN, Edge* adjN, int statusN)
{
	node = nodeN;
	next = nextN;
	adj = adjN;
	status = statusN;
}

void LinkedNode::visit()
{
	cout << node << " ";
}