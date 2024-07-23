#pragma once
#include "LListNode.h"
class LList
{
private:
	LListNode* head, * tail;
public:
	LList();
	~LList();
	bool isEmpty();
	void addToHead(int el);
	void addToTail(int el);
	int deleteFromHead();
	int deleteFromTail();
	LListNode* findNodePtr(int el);
	LListNode* getHead();
	LListNode* getNext(LListNode* ptr);
	int getHeadEl();
	int getNextEl(int el);
	void printAll();
	bool isInList(int el);
	void deleteEl(int el);
	LListNode* removeNodeFromHead();

	/* ------------------ zadaci ------------------ */

	//jun2 2022 - 1. zad
	LList* SplitOrMove();
	LList* SplitOrMove2();
	LList* SplitOrMove3();

	//Oktobar 2022 - 1. zad
	int MoveHigher(int value);

	//jun 2022 - 1. zad
	void GroupElements();
	void GroupElements2();

	void InsertSortedUp(int el);
	void InsertSortedDown(int el);

	//jun2 2021 - 1. zad
	void injectOrRemove(int br);

	//cs primer
	void fillInTheBlanks();
};

