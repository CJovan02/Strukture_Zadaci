#include "LListNode.h"
#include <iostream>

using namespace std;

LListNode::LListNode()
{
	next = NULL;
}

LListNode::LListNode(int i)
{
	info = i;
	next = NULL;
}

LListNode::LListNode(int i, LListNode* n)
{
	info = i;
	next = n;
}

int LListNode::print()
{
	return info;
}
bool LListNode::isEqual(int el)
{
	return info == el;
}

LListNode::~LListNode() {}