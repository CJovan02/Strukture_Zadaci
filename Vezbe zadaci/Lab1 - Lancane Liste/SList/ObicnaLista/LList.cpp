#include "LList.h"
#include "LLNode.h"
#include <iostream>
using namespace std;

LList::LList()
{
	head = nullptr;
}

LList::~LList()
{
	while (!IsEmpty())
	{
		int tmp = DeleteFromHead();
	}
}

void LList::AddToHead(int el)
{
	/*LLNode* newNode = new LLNode(el);
	newNode->next = head;
	head = newNode;*/

	head = new LLNode(el, head);
}

void LList::AddToTail(int el)
{
	if (!IsEmpty())
	{
		LLNode* currNode = head;
		while (currNode->next != nullptr)
			currNode = currNode->next;
		currNode->next = new LLNode(el);
	}
	else
		AddToHead(el);
}

int LList::DeleteFromHead()
{
	if (IsEmpty())
		throw new exception("List is empty");

	int el = head->info;

	LLNode* tmp = head;
	head = head->next;
	delete tmp;

	return el;
}

int LList::DeleteFromTail()
{
	if (IsEmpty())
		throw new exception("List is empty");

	int el;
	if (head->next == nullptr)
	{
		el = head->info;
		delete head;
		head = nullptr;
	}
	else
	{
		LLNode* currNode = head;
		LLNode* prevNode = head;
		while (currNode->next != nullptr)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		el = currNode->info;
		delete currNode;
		prevNode->next = nullptr;
	}

	return el;
}

bool LList::IsEmpty()
{
	return head == nullptr;
}

void LList::Print()
{
	LLNode* currNode = head;
	while (currNode != nullptr)
	{
		cout << currNode->info << " ";
		currNode = currNode->next;
	}
	cout << endl;
}

LLNode* LList::FindNodePtr(int el)
{
	if (IsEmpty())
		throw new exception("List is empty");

	LLNode* currNode = head;
	while (currNode != nullptr and currNode->info != el)
		currNode = currNode->next;
	return currNode;
}
LLNode* LList::GetHead()
{
	if (IsEmpty())
		throw new exception("List is empty");
	return head;
}
LLNode* LList::GetNext(LLNode* ptr)
{
	if (IsEmpty())
		throw new exception("List is empty");
	
	return ptr->next;
}
