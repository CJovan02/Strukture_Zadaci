#include "DLNode.h"

DLNode::DLNode()
{
	prev = nullptr;
	next = nullptr;
}

DLNode::DLNode(int el)
{
	info = el;
	next = nullptr;
	prev = nullptr;
}
DLNode::DLNode(int el, DLNode* prev, DLNode* next)
{
	info = el;
	this->next = next;
	this->prev = prev;
}