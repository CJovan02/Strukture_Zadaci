#include "DList.h"



DList::DList()
{
	head = NULL;
}


DList::~DList()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}

DListNode* DList::findNodePtr(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode *ret = head;
	while (ret != NULL && ret->info != el)
	{
		ret = ret->next;
	}
	return ret;
}

int DList::getHeadEl()
{
	if (isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int DList::getNextEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("Node doesn't exist");
	if (tmp->next == NULL)
		throw new exception("Element doesn't have next node");
	return tmp->next->info;
}

int DList::getPreviousEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("Node doesn't exist");
	if (tmp->prev == NULL)
		throw new exception("Element doesn't have previous node");
	return tmp->prev->info;
}

bool DList::isInList(int el)
{
	if (isEmpty())
		return false;
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		return false;
	else
		return true;
}

void DList::deleteEl(int el)
{
	if (!isEmpty())
		if (head->isEqual(el))
		{
			DListNode *tmp = head;
			head = head->next;
			head->prev = NULL;
			delete tmp;
		}
		else
		{
			DListNode *tmp;
			for (tmp = head->next; tmp != NULL && !(tmp->isEqual(el)); tmp = tmp->next);
			if (tmp != NULL)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
			}
		}
}

void DList::addToHead(int el)
{
	head = new DListNode(el, NULL, head);
	if(head->next!=NULL)
		head->next->prev = head;
}

void DList::addToTail(int el)
{
	if (!isEmpty())
	{
		DListNode* tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new DListNode(el, tmp, NULL);
	}
	else
		addToHead(el);
}

int DList::deleteFromHead()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	DListNode *tmp = head;
	head = head->next;
	if(head!=NULL)
		head->prev = NULL;
	delete tmp;
	return el;
}

int DList::deleteFromTail()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		return deleteFromHead();
	}
	else
	{
		DListNode *tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		el = tmp->info;
		tmp->prev->next = NULL;
		delete tmp;
	}
	return el;
}

void DList::printAll()
{
	DListNode *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->print() << " ";
		tmp = tmp->next;
	}
	cout << endl;
}


/* ----------------- zadaci ---------------- */

//2021 kol 1
void DList::exchange(int a, int b)
{
	/* zamenjuje mesta prelancavanjem cvorova
	ciji su info delovi prosledjeni kao argumenti funkcije. 
	Ukoliko ne postoji jedan od cvorovo ili ob cvora u listi, 
	ne vrsiti prelancavanje. */

	DListNode* currNode = head;
	DListNode* nodeB = NULL;
	DListNode* nodeA = NULL;
	while (currNode != NULL)
	{
		if (currNode->info == a)
			nodeA = currNode;
		if (currNode->info == b)
			nodeB = currNode;
		currNode = currNode->next;
	}

	if (nodeA == NULL || nodeB == NULL)
		return;

	if (nodeB->next == nodeA)
	{
		DListNode* pom = nodeA;
		nodeA = nodeB;
		nodeB = pom;
	}

	DListNode* prevA = nodeA->prev;
	DListNode* prevB = nodeB->prev;
	DListNode* nextA = nodeA->next;
	DListNode* nextB = nodeB->next;

	if (nodeA->next == nodeB)
	{
		//Swamp the prev pointers
		nodeA->prev = nodeB;
		nodeB->prev = prevA;

		//Swap next
		nodeA->next = nextB;
		nodeB->next = nodeA;

		prevA->next = nodeB;
		nextB->prev = nodeA;

		return;
	}
	

	// Swap the prev pointers
	nodeA->prev = nodeB->prev;
	nodeB->prev = prevA;

	// Swap the next pointers
	nodeA->next = nodeB->next;
	nodeB->next = nextA;

	//Swap next of prev pointers
	prevA->next = nodeB;
	prevB->next = nodeA;

	//Swap prev of next pointers
	nextA->prev = nodeB;
	nextB->prev = nodeA;
}

//2019 kol 1
void DList::transpose(int el)
{
	//zadatom elementu smesta za jedno mesto prema glavi perlancavanjem
	if (head == NULL)
		throw new exception("Lista je prazna");
	
	if (head->next == NULL)
		throw new exception("Lista ima samo jedan element");

	if (head->info == el)
		return;
	
	if (head->next->info == el)
	{
		DListNode* nodeB = head->next;
		DListNode* nodeA = head;
		DListNode* nextB = nodeB->next;
		
		nodeB->next = nodeA;
		
		nodeA->prev = nodeB;
		nodeA->next = nextB;

		nextB->prev = nodeA;

		head = nodeB;

		return;
	}

	DListNode* nodeB = head;
	while (nodeB != NULL && nodeB->info != el)
		nodeB = nodeB->next;

	if (nodeB->info == el)
	{
		DListNode* nodeA = nodeB->prev;

		DListNode* prevA = nodeA->prev;
		DListNode* nextB = nodeB->next;

		//zamena next od a i b
		nodeA->next = nodeB->next;
		nodeB->next = nodeA;

		//zamena prev od a i b
		nodeA->prev = nodeB;
		nodeB->prev = nodeA->prev;

		//zamena next od prevA
		prevA->next = nodeB;

		//zamena prev od nextB
		if (nextB != NULL)
			nextB->prev = nodeA;
	}
	
}