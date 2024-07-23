#include "DLNode.h"

#pragma once
class DList
{
protected:
	DLNode* head;
public:
	DList() { head = nullptr; };
	~DList();
	bool isEmpty() { return head == nullptr; }
	void Print();

	void AddToHead(int el);
	void AddToTail(int el);
	void AddSorted(int el);
	int DeleteFromHead();
	int DeleteFromTail();
};

