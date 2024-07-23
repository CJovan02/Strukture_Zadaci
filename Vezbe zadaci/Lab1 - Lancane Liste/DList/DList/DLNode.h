#pragma once
class DLNode
{
public:
	int info;
	DLNode* next, * prev;

	DLNode();
	DLNode(int el);
	DLNode(int el, DLNode* prev, DLNode* next);
};

