#pragma once
class LListNode
{
public:
	LListNode* next;
	int info;
public:
	LListNode();
	LListNode(int i);
	LListNode(int i, LListNode* n);
	int print();
	bool isEqual(int el);
	~LListNode();
};

