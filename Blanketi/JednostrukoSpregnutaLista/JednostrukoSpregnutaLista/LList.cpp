#include "LList.h"
#include "LListNode.h"
#include <iostream>

using namespace std;


LList::LList()
{
	head = NULL;
}


LList::~LList()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}


bool LList::isEmpty()
{
	return head == NULL;
}

void LList::addToHead(int el)
{
	head = new LListNode(el, head);
}

void LList::addToTail(int el)
{
	if (!isEmpty())
	{
		LListNode* tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new LListNode(el);
	}
	else
		addToHead(el);
}

int LList::deleteFromHead()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	LListNode* tmp = head;
	head = head->next;
	delete tmp;
	return el;
}

int LList::deleteFromTail()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		el = head->info;
		delete head;
		head = NULL;
	}
	else
	{
		LListNode* prev = head;
		LListNode* tmp = head;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		el = tmp->info;
		delete tmp;
		prev->next = NULL;
	}
	return el;
}

LListNode* LList::findNodePtr(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	LListNode* ret = head;
	while (ret != NULL && ret->info != el)
	{
		ret = ret->next;
	}
	return ret;
}

LListNode* LList::getHead()
{
	return head;
}

LListNode* LList::getNext(LListNode* ptr)
{
	if (isEmpty())
		throw new exception("List is empty");
	return ptr->next;
}

int LList::getHeadEl()
{
	if (isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int LList::getNextEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	LListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("Node doesn't exist");
	if (tmp->next == NULL)
		throw new exception("Element doesn't have next node");
	return tmp->next->info;
}

void LList::printAll()
{
	LListNode* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->print() << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

bool LList::isInList(int el)
{
	if (isEmpty())
		return false;
	LListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		return false;
	else
		return true;
}

void LList::deleteEl(int el)
{
	if (!isEmpty())
		if (head->isEqual(el))
		{
			LListNode* tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			LListNode* pred, * tmp;
			for (pred = head, tmp = head->next; tmp != NULL && !(tmp->isEqual(el));
				pred = pred->next, tmp = tmp->next);
			if (tmp != NULL)
			{
				pred->next = tmp->next;
				delete tmp;
			}
		}
}

LListNode* LList::removeNodeFromHead()
{
	if (isEmpty())
		return NULL;
	LListNode* tmp = head;
	head = head->next;
	return tmp;
}



/* ------------------ zadaci ------------------ */

//jun2 2022 - 1. zad
LList* LList::SplitOrMove()
{
	/*Ukoliko je tekuci element u listi jedinstven, prelancava ga u novu listu. 
	Ukoliko tekuci element ima duplikat u listi, onda se samo duplikat prelancava u novu listu*/

	LList* rez = new LList();

	LListNode* currNode = head;
	LListNode* prevNode = head;
	int currEl = head->info;
	while (currNode != NULL)
	{
		LListNode* currNode2 = head;
		LListNode* prevNode2 = head;
		int currEl2 = head->info;
		bool jedinstven = true;
		while (currNode2 != NULL)
		{
			if (currEl == currEl2 and currNode != currNode2)
			{
				jedinstven = false;
				break;
			}

			prevNode2 = currNode2;
			currNode2 = currNode2->next;
			if (currNode2 != NULL)
				currEl2 = currNode2->info;
		}



		LListNode* tmp = NULL;
		if (!rez->isEmpty())
		{
			tmp = rez->head;
			while (tmp->next != NULL)
				tmp = tmp->next;
		}
		if (jedinstven)
		{

			LListNode* tmp2 = currNode->next;

			if (currNode == head)
			{
				currNode->next = NULL;
				if (tmp == NULL)
					rez->head = currNode;
				else
					tmp->next = currNode;

				currNode = tmp2;
				prevNode = tmp2;
				head = currNode;
				currEl = tmp2->info;
			}
			else
			{
				prevNode->next = currNode->next;
				currNode->next = NULL;
				if (tmp == NULL)
					rez->head = currNode;
				else
					tmp->next = currNode;

				currNode = tmp2;
				currEl = tmp2->info;
			}
		}
		else
		{
			prevNode2->next = currNode2->next;
			currNode2->next = NULL;
			if (tmp == NULL)
				rez->head = currNode2;
			else
				tmp->next = currNode2;

			prevNode = currNode;
			currNode = currNode->next;
			if(currNode != NULL)
				currEl = currNode->info;
		}
	}

	return rez;
}
LList* LList::SplitOrMove2()
{
	LList* rezultat = new LList();
	LListNode* pom1 = head;
	LListNode* pom2;
	LListNode* pom3 = NULL;
	LListNode* rezpom = rezultat->head;
	int brojac = 1;
	while (pom1 != NULL)
	{
		pom2 = pom1;
		while (pom2 != nullptr && brojac == 1) {
			pom3 = pom2;
			pom2 = pom2->next;
			if (pom2 != nullptr && pom2->info == pom1->info)
			{
				brojac++;
			}
		}
		if (brojac == 2)
		{
			if (rezpom == nullptr)
			{
				pom3->next = pom2->next;
				pom2->next = nullptr;
				rezpom = pom2;
				rezultat->head = rezpom;

			}
			else
			{
				pom3->next = pom2->next;
				pom2->next = nullptr;
				rezpom->next = pom2;
				rezpom = rezpom->next;

			}
		}
		brojac = 1;
		pom1 = pom1->next;
	}
	return rezultat;
}
LList* LList::SplitOrMove3()
{
	/*Ukoliko je tekuci element u listi jedinstven, prelancava ga u novu listu.
	Ukoliko tekuci element ima duplikat u listi, onda se samo duplikat prelancava u novu listu*/

	LList* rezultat = new LList();

	if (head == NULL)
		throw new exception("Lista je prazna");

	bool isUnique = true;
	LListNode* nodeA = head;
	LListNode* prevA = head;
	while (nodeA != NULL)
	{
		LListNode* nodeB = nodeA->next;
		LListNode* prevB = nodeA;
		while (nodeB != NULL)
		{
			if (nodeB->info == nodeA->info)
			{
				isUnique = false;
				LListNode* pom = nodeB->next;
				prevB->next = nodeB->next;
				if (rezultat->head == NULL)
				{
					rezultat->head = nodeB;
				}
				else
				{
					LListNode* tmp = rezultat->head;
					while (tmp->next!= NULL)
						tmp = tmp->next;

					tmp->next = nodeB;
				}
				nodeB->next = NULL;
				nodeB = pom;
			}
			else
			{
				prevB = nodeB;
				nodeB = nodeB->next;
			}
		}

		if (isUnique)
		{
			LListNode* pom = nodeA->next;
			if (head == nodeA)
			{
				prevA = prevA->next;
				if (rezultat->head == NULL)
				{
					rezultat->head = nodeA;
					nodeA->next = NULL;
					head = head->next;
				}
				else
				{
					LListNode* tmp = rezultat->head;
					while (tmp->next != NULL)
						tmp = tmp->next;

					tmp->next = nodeA;
					nodeA->next = NULL;
				}
				nodeA = pom;
			}
			else
			{
				prevA = nodeA;
				nodeA = nodeA->next;
			}
		}
		
	}
	return rezultat;
}

//oktobar 2022 - 1. zad
int LList::MoveHigher(int value)
{
	/*pomera sve studente smestene u lancanoj listi
	koji imaju veci broj bodova od value na pocetak liste
	zadrzavajuci njihov medjusobni redosled*/

	LListNode* currNode, * pom, * pom2, * prevNode;
	currNode = head;
	prevNode = head;
	pom = head;
	bool prvoPremestanje = true;

	while (currNode != NULL)
	{
		if (currNode->info > value and currNode != head)
		{
			if (prvoPremestanje)
			{
				prevNode->next = currNode->next;
				currNode->next = head;
				head = currNode;

				pom = currNode;
				currNode = prevNode->next;
				
				prvoPremestanje = false;
			}
			else
			{
				prevNode->next = currNode->next;
				currNode->next = pom->next;
				pom->next = currNode;
				pom = currNode;

				currNode = prevNode->next;
			}
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
	}

	return 0;
}

//jun 2022 - 1. zad
//dodaje iste elemente pozadi
void LList::GroupElements()
{
	/*Grupise sve cvorove koji imaju istu vrednost info dela
	tako da budu jedna pored drugog, grupisanje vrsiti prelancavanjem*/

	LListNode* currNode,* prevNode, * currNode2, * prevNode2;
	currNode = head;
	prevNode = head;

	while (currNode != NULL)
	{
		if (currNode == head)
			prevNode2 = prevNode;
		else
			prevNode2 = prevNode->next;
		currNode2 = currNode->next;

		while (currNode2 != NULL)
		{
			if (currNode->info == currNode2->info)
			{
				if (currNode == head)
				{
					prevNode2->next = currNode2->next;
					currNode2->next = head;
					head = currNode2;
					prevNode = currNode2;
					currNode2 = prevNode2->next;
				}
				else
				{
					prevNode2->next = currNode2->next;
					currNode2->next = currNode;
					prevNode->next = currNode2;
					prevNode = currNode2;

					currNode2 = prevNode2->next;
				}
			}
			else
			{
				prevNode2 = currNode2;
				currNode2 = currNode2->next;
			}
		}


		prevNode = currNode;
		currNode = currNode->next;
	}
}

//dodaje iste elemente ispred
void LList::GroupElements2()
{
	LListNode* currNode, * currNode2, * prevNode2;
	currNode = head;
 	while (currNode != nullptr)
	{
		prevNode2 = currNode;
		currNode2 = currNode->next;
		//cout << "CurrNode = " << currNode->info << " CurrNode2 = " << currNode2->info << " prevNode2: " << prevNode2->info << endl;
		while (currNode2 != nullptr)
		{
			if (currNode->info == currNode2->info and currNode->info != currNode->next->info)
			{
				prevNode2->next = currNode2->next;
				currNode2->next = currNode->next;
				currNode->next = currNode2;
				currNode = currNode2;

				currNode2 = prevNode2->next;
			}
			else
			{
				prevNode2 = currNode2;
				currNode2 = currNode2->next;
			}
			
		}

		/*LListNode* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->print() << " ";
			tmp = tmp->next;
		}
		cout << endl;*/

		currNode = currNode->next;
	}

}


void LList::InsertSortedUp(int el)
{
	//lista je sortirana u rastucem redosledu,
	//dodaje element tako da lista ostaje sortirana

	if (!isEmpty())
	{
		if (head->next == NULL and el > head->info)
				addToTail(el);
		else
		{
			if (el < head->info)
				addToHead(el);
			else
			{
				LListNode* currNode = head;
				while (currNode->next != NULL and currNode->next->info < el)
					currNode = currNode->next;

				LListNode* newNode = new LListNode(el, currNode->next);
				currNode->next = newNode;
			}
		}
	}
	else
		addToTail(el);
}
void LList::InsertSortedDown(int el)
{
	//lista je sortirana u opadajucem redosledu,
	//dodaje element tako da lista ostaje sortirana

	if (!isEmpty())
	{
		if (head->next == NULL and el < head->info)
			addToTail(el);
		else
		{
			if (el > head->info)
				addToHead(el);
			else
			{
				LListNode* currNode = head;
				while (currNode->next != NULL and currNode->next->info > el)
					currNode = currNode->next;

				LListNode* newNode = new LListNode(el, currNode->next);
				currNode->next = newNode;
			}
		}
	}
	else
		addToTail(el);
}

//jun2 2021 - 1. zad
void LList::injectOrRemove(int br)
{
	/*Lista je uredjena u rastuci redosled
	dodaje element sa info delom br na odgovarajuce mesto
	u listi tako da lista odrzava uredjenje.
	Ukoliko element sa info delom jednakim vrednosti br postoji
	u listi, taj element se onda uklanja iz liste (brise)
	i nista se ne dodaje u listu.*/

	bool obrisan = false;
	if (!isEmpty())
	{
		LListNode* currNode = head;
		LListNode* prevNode = head;
		while (currNode != NULL)
		{
			if (currNode->info == br)
			{
				obrisan = true;
				break;
			}
			prevNode = currNode;
			currNode = currNode->next;
		}
		if (obrisan)
		{
			if (currNode == head)
			{
				LListNode* tmp = head;
				head = head->next;
				delete tmp;
			}
			else
			{
				LListNode* tmp = currNode;
				prevNode->next = currNode->next;
				delete tmp;
			}
		}
		else
		{
			if (head->next == NULL and br > head->info)
				addToTail(br);
			else
			{
				if (br < head->info)
					addToHead(br);
				else
				{
					LListNode* currNode = head;
					while (currNode->next != NULL and currNode->next->info < br)
						currNode = currNode->next;

					LListNode* newNode = new LListNode(br, currNode->next);
					currNode->next = newNode;
				}
			}
		}
	}
	else
		addToTail(br);
}

//cs primer
void LList::fillInTheBlanks()
{
	/*lista je uredjena u neopadajuci redosled,
	funkcija brise sve duple cvorove 
	a dodaje cvorove za sve one vrednosti 
	koje nedostaju izmedju vrednosti dva uzastopna cvora liste*/

	LListNode* currNode = head;
	LListNode* prevNode = head;
	LListNode* tmp;
	while (currNode != NULL)
	{
		if (currNode->info == prevNode->info && currNode != head)
		{
			tmp = currNode;
			prevNode->next = currNode->next;
			currNode = currNode->next;
			delete tmp;
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
	}

	currNode = head;
	while (currNode->next != NULL)
	{
		if (currNode->next->info != (currNode->info + 1))
		{
			LListNode* newNode = new LListNode(currNode->info + 1, currNode->next);
			currNode->next = newNode;
		}

		currNode = currNode->next;
	}
}
