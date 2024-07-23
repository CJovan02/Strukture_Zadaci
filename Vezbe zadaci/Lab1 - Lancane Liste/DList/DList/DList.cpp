#include "DList.h"
#include "DLNode.h"
#include <iostream>
using namespace std;

DList::~DList()
{
	while (!isEmpty())
		int tmp = DeleteFromHead();
}

void DList::Print()
{
	if (isEmpty())
		throw new exception("List is empty");

	DLNode* currNode = head;
	while (currNode != nullptr)
	{
		cout << currNode->info << " ";
		currNode = currNode->next;
	}
	cout << endl;
}

void DList::AddToHead(int el)
{
	/*DLNode* newNode = new DLNode(el, nullptr, head);
	head->prev = newNode;
	head = newNode;*/

	head = new DLNode(el, nullptr, head);
	if (head->next != nullptr)
		head->next->prev = head;
}

void DList::AddToTail(int el)
{
	if (!isEmpty())
	{
		DLNode* currNode = head;
		while (currNode->next != nullptr)
			currNode = currNode->next;
		currNode->next = new DLNode(el, currNode, nullptr);
	}
	else
		AddToHead(el);
}

void DList::AddSorted(int el)
{
	if (!isEmpty())
	{
		if (head->next == nullptr)
		{
			if (head->info < el)
				AddToHead(el);
			else
				AddToTail(el);
		}
		else
		{
			DLNode* currNode = head;
			while (currNode->next != nullptr and currNode->info > el)
			{
				currNode = currNode->next;
			}

			if (currNode == head)
				AddToHead(el);
			else if (currNode->next == nullptr)
				AddToTail(el);
			else 
			{
				DLNode* newNode = new DLNode(el, currNode, currNode->next);
				currNode->next = newNode;
				newNode->next->prev = newNode;
			}
		}
	}
	else
		AddToHead(el);
}

int DList::DeleteFromHead()
{
	if (isEmpty())
		throw new exception("List is empty");

	int el = head->info;

	DLNode* temp = head;
	head = head->next;
	if(head != nullptr)
		head->prev = nullptr;
	delete temp;

	return el;
}

int DList::DeleteFromTail()
{
	if (isEmpty())
		throw new exception("List is empty");

	if (head->next == nullptr)
		DeleteFromHead();
	else
	{
		DLNode* currNode = head;
		while (currNode->next != nullptr)
			currNode = currNode->next;

		int el = currNode->info;

		currNode->prev->next = nullptr;
		delete currNode;
	return el;
	}

}