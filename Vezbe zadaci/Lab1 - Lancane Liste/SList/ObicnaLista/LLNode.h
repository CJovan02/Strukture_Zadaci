#pragma once
class LLNode
{
public:
	int info;
	LLNode* next;

	LLNode();
	LLNode(int info);
	LLNode(int info, LLNode* next);

	~LLNode();

	int print();
	bool isEqual(int el);
};