#include "LLNode.h"
#include <iostream>
using namespace std;

LLNode::LLNode() 
{
	next = nullptr;
}
LLNode::LLNode(int info)
{
	this->info = info;
	this->next = nullptr;
}
LLNode::LLNode(int info, LLNode* next)
{
	this->info = info;
	this->next = next;
}

LLNode::~LLNode() {}

int LLNode::print()
{
	return info;
}
bool LLNode::isEqual(int el)
{
	return el == info;
}