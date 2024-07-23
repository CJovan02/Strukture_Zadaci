#include "LLNode.h"

#pragma once
class LList
{
protected:
	LLNode* head, * tail;
public:
	LList();
	~LList();

	void AddToHead(int el);
	void AddToTail(int el);
	int DeleteFromHead();
	int DeleteFromTail();
	LLNode* FindNodePtr(int el);
	LLNode* GetHead();
	LLNode* GetNext(LLNode* ptr);

	bool IsEmpty();

	void Print();
};

