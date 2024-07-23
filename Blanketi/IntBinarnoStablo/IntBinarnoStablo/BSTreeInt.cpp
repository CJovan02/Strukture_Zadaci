#include "BSTreeInt.h"
#include "BSTNodeInt.h"
#include "StackAsArrayInt.h"
#include "QueueAsArrayInt.h"
#include <math.h>

void BSTreeInt::deleteTree(BSTNodeInt* node)
{
	if (node != nullptr)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

void BSTreeInt::insert(int el)
{
	BSTNodeInt* currNode = root;
	BSTNodeInt* prevNode = nullptr;

	while (currNode != nullptr)
	{
		prevNode = currNode;
		if (currNode->isLT(el))
			currNode = currNode->right;
		else
			currNode = currNode->left;
	}

	if (root == nullptr)
		root = new BSTNodeInt(el);
	else if (prevNode->isLT(el))
		prevNode->right = new BSTNodeInt(el);
	else
		prevNode->left = new BSTNodeInt(el);

	numOfElements++;
}

void BSTreeInt::insert(int el, double value)
{
	BSTNodeInt* currNode = root;
	BSTNodeInt* prevNode = nullptr;

	while (currNode != nullptr)
	{
		prevNode = currNode;
		if (currNode->isLT(el))
			currNode = currNode->right;
		else
			currNode = currNode->left;
	}

	if (root == nullptr)
		root = new BSTNodeInt(el, value);
	else if (prevNode->isLT(el))
		prevNode->right = new BSTNodeInt(el, value);
	else
		prevNode->left = new BSTNodeInt(el, value);

	numOfElements++;
}

BSTNodeInt* BSTreeInt::search(int el)
{
	BSTNodeInt* currNode = root;
	while (root != nullptr)
	{
		if (currNode->isEQ(el))
			return currNode;
		else if (currNode->isGT(el))
			currNode = currNode->left;
		else
			currNode = currNode->right;
	}
	return nullptr;
}

void BSTreeInt::preorder(BSTNodeInt* node)
{
	if (node != nullptr)
	{
		node->visit();
		preorder(node->left);
		preorder(node->right);
	}
}

void BSTreeInt::inorder(BSTNodeInt* node)
{
	if (node != nullptr)
	{
		inorder(node->left);
		node->visit();
		inorder(node->right);
	}
}

void BSTreeInt::postorder(BSTNodeInt* node)
{
	if (node != nullptr)
	{
		postorder(node->left);
		postorder(node->right);
		node->visit();
	}
}

void BSTreeInt::iterativePreorder()
{
	BSTNodeInt* ptr = root;
	StackAsArrayBSTNodeInt stack(numOfElements);
	if (ptr != nullptr)
	{
		stack.push(ptr);
		while (!stack.isEmpty())
		{
			ptr = stack.pop();
			ptr->visit();
			if (ptr->right != nullptr)
				stack.push(ptr->right);
			if (ptr->left != nullptr)
				stack.push(ptr->left);
		}
	}
}

void BSTreeInt::breadthFirstSearch()
{
	BSTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	if (ptr != nullptr)
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			ptr->visit();
			if (ptr->left != nullptr)
				queue.enqueue(ptr->left);
			if (ptr->right != nullptr)
				queue.enqueue(ptr->right);
		}
	}
	cout << endl;
}

void BSTreeInt::deleteByCopying(int el)
{
	BSTNodeInt* ptr = root, * prev = NULL, * node;
	while (ptr != NULL && !ptr->isEQ(el))
	{
		prev = ptr;
		if (ptr->isGT(el))
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	node = ptr;

	if (ptr != NULL && ptr->isEQ(el))
	{
		if (node->right == NULL)
			node = node->left;
		else if (node->left == NULL)
			node = node->right;
		else
		{
			BSTNodeInt* tmp = node->left, * prevTmp = node;
			while (tmp->right != NULL)
			{
				prevTmp = tmp;
				tmp = tmp->right;
			}
			node->setKey(tmp->getKey());
			if (prevTmp == node)
				prevTmp->left = tmp->left;
			else
				prevTmp->right = tmp->left;
			delete tmp;
			numOfElements--;
			return;
		}

		if (ptr == root)
			root = node;
		else if (prev->right == ptr)
			prev->right = node;
		else
			prev->left = node;
		delete ptr;
		numOfElements--;
	}
	else if (root != NULL)
		throw new exception("Element nije u stablu");
	else
		throw new exception("Stablo je prazno");
}

void BSTreeInt::deleteByMerging(int el)
{
	BSTNodeInt* ptr = root, * prev = NULL, * node;
	while (ptr != NULL && !ptr->isEQ(el))
	{
		prev = ptr;
		if (ptr->isGT(el))
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	node = ptr;
	
	if (ptr != NULL && ptr->isEQ(el))
	{
		if (node->left == NULL)
			node = node->right;
		else if (node->right == NULL)
			node = node->left;
		else
		{
			BSTNodeInt* tmp = ptr->left;
			while (tmp->right != NULL)
				tmp = tmp->right;
			tmp->right = node->right;
			node = node->left;
		}
		if (root == ptr)
			root = node;
		else if (prev->right == ptr)
			prev->right = node;
		else
			prev->left = node;
		delete ptr;
		numOfElements--;

	}
	else if (root != NULL)
		throw new exception("Element se ne nalazi u stablu");
	else
		throw new exception("Stablo je prazno");
}

//zadaci za pripremu vezbe
int BSTreeInt::distinctElementsIterative()
{
	int count = 0;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	BSTNodeInt* ptr = root;
	if (ptr != NULL)
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			
			BSTNodeInt* tmp = root;
			while (tmp != NULL)
			{
				if (tmp != ptr && tmp->isEQ(ptr->getKey()))
					break;
				if (tmp->isGT(ptr->getKey()))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (tmp == NULL)
				count++;

			if (ptr->left != NULL)
				queue.enqueue(ptr->left);
			if (ptr->right != NULL)
				queue.enqueue(ptr->right);
		}
	}

	return count;
}
int BSTreeInt::distinct(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return 0;

	static int* arrDis = new int[numOfElements];
	static int count = 0;

	insertDistinct(arrDis, count, ptr->key);

	distinct(ptr->left);
	distinct(ptr->right);

	return count;
}

void BSTreeInt::insertDistinct(int* arr, int& count, int el)
{
	bool ubaci = true;
	for (int i = 0; i < count; i++)
	{
		if (arr[i] == el)
		{
			ubaci = false;
			break;
		}
	}
	if (ubaci)
		arr[count++] = el;
		
}

int BSTreeInt::heightIterative()
{
	int maxNivo = 0, nivoEle = 0;
	BSTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	if (ptr != NULL)
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			if (ptr->left != NULL)
				queue.enqueue(ptr->left);
			if (ptr->right != NULL)
				queue.enqueue(ptr->right);
			if (ptr->right == NULL && ptr->left == NULL)
			{
				nivoEle = 0;
				BSTNodeInt* tmp = root;
				while (tmp != NULL)
				{
					if (tmp->isGT(ptr->getKey()))
					{
						tmp = tmp->left;
						nivoEle++;
					}
					else
					{
						tmp = tmp->right;
						nivoEle++;
					}
				}
			}
			if (nivoEle > maxNivo)
				maxNivo = nivoEle;
		}
	}
	return maxNivo;
}
int BSTreeInt::height(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return 0;

	int leftHeight = height(ptr->left);
	int rightHeight = height(ptr->right);
	
	return 1 + max(leftHeight, rightHeight);
}

int BSTreeInt::momentIterative()
{
	int count = 0;
	BSTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	if (ptr != NULL)
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			count++;
			if (ptr->left != NULL)
				queue.enqueue(ptr->left);
			if (ptr->right != NULL)
				queue.enqueue(ptr->right);
			
		}
	}
	return count;
}
int BSTreeInt::moment(BSTNodeInt* ptr)
{
	if (ptr != NULL)
	{
		return 1 + moment(ptr->left) + moment(ptr->right);
	}
	return 0;
}

int BSTreeInt::weightIterative()
{
	int count = 0;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	BSTNodeInt* ptr = root;
	if (ptr != NULL)
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			if (ptr->right != NULL)
				queue.enqueue(ptr->right);
			if (ptr->left != NULL)
				queue.enqueue(ptr->left);
			if (ptr->right == NULL && ptr->left == NULL)
				count++;
		}
	}
	return count;
}
int BSTreeInt::weight(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return 0;
	if (ptr->left == NULL && ptr->right == NULL)
		return 1;
	else
		return weight(ptr->left) + weight(ptr->right);
}

void BSTreeInt::deleteListsIterative()
{
	StackAsArrayBSTNodeInt stack(numOfElements);
	BSTNodeInt* ptr = root, * prev = NULL;
	if (ptr != NULL)
	{
		stack.push(ptr);
		while (!stack.isEmpty())
		{
			prev = ptr;
			ptr = stack.pop();
			if (ptr->right != NULL)
				stack.push(ptr->right);
			if (ptr->left != NULL)
				stack.push(ptr->left);
			if (ptr->right == NULL && ptr->left == NULL)
			{
				if (prev->left == ptr)
					prev->left = NULL;
				else
					prev->right = NULL;
				BSTNodeInt* tmp = ptr;
				delete tmp;
				numOfElements--;
				
			}
		}
	}
}



int BSTreeInt::sumOfLeafs(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return 0;
	if (ptr->left == NULL && ptr->right == NULL)
		return ptr->getKey();
	else
		return sumOfLeafs(ptr->left) + sumOfLeafs(ptr->right);
}
void BSTreeInt::deleteLeafs(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return;

	if (ptr->left != NULL)
	{
		if (ptr->left->left == NULL && ptr->left->right == NULL)
		{
			delete ptr->left;
			ptr->left = NULL;
		}
	}
	if (ptr->right != NULL)
	{
		if (ptr->right->left == NULL && ptr->right->right == NULL)
		{
			delete ptr->right;
			ptr->right = NULL;
		}
	}
	deleteLeafs(ptr->left);
	deleteLeafs(ptr->right);
}

void BSTreeInt::dupliraj(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return;
	ptr->setKey(ptr->getKey() * 2);
	dupliraj(ptr->left);
	dupliraj(ptr->right);
}

int BSTreeInt::suma(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return 0;
	static int sum = 0;
	sum += ptr->key;
	suma(ptr->left);
	suma(ptr->right);
	return sum;
}

int BSTreeInt::findMax(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return 0;
	static int max;
	if (ptr->getKey() > max)
		max = ptr->getKey();
	findMax(ptr->left);
	findMax(ptr->right);
	return max;
}

void BSTreeInt::mirror(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return;

	BSTNodeInt* pom = ptr->left;
	ptr->left = ptr->right;
	ptr->right = pom;
	mirror(ptr->left);
	mirror(ptr->right);
}

BSTreeInt* BSTreeInt::duplicate(BSTNodeInt* ptr)
{
	if (ptr == NULL)
		return nullptr;
	static BSTreeInt* result = new BSTreeInt();
	
	//umetanje u novo stablo bez funkcije insert
	//result.insert(ptr.getKey());
	BSTNodeInt* tmp = result->root, * prev = NULL;
	while (tmp != NULL)
	{
		prev = tmp;
		if (tmp->isLT(ptr->getKey()))
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	if (result->root == NULL)
		result->root = new BSTNodeInt(ptr->getKey());
	else if (prev->isLT(ptr->getKey()))
		prev->right = new BSTNodeInt(ptr->getKey());
	else
		prev->left = new BSTNodeInt(ptr->getKey());
	result->numOfElements++;

	duplicate(ptr->left);
	duplicate(ptr->right);
	return result;
}

void BSTreeInt::spojiStabla(BSTNodeInt* a, BSTNodeInt* b, BSTreeInt* result)
{
	if (a == NULL && b != NULL)
	{
		result->insert(b->key);
		return;
	}
	else if (a != NULL && b == NULL)
	{
		result->insert(a->key);
		return;
	}
	else if (a == NULL && b == NULL)
		return;
	result->insert(a->key);
	result->insert(b->key);
	spojiStabla(a->left, b->left, result);
	spojiStabla(a->right, b->right, result);
}

/* ------------------------------------------------------------------------------ */
/* ---------------------------------- blanketi ---------------------------------- */
/* ------------------------------------------------------------------------------ */

//jun2 2022
int BSTreeInt::brojCvorova(int keyMin, double valueMin, BSTNodeInt* ptr)
{
	//broji koliko cvorova ima key veci od keyMin i ako barem jedan od njihovih predaka ima value veci od valueMin
	if (ptr == NULL)
		return 0;

	static int count = 0;
	static int brojProlaza = 0;

	if (ptr->key > keyMin)
	{
		BSTNodeInt* curr = root;
		while (curr != NULL && curr != ptr)
		{
			if (curr->value > valueMin)
			{
				count++;
				break;
			}
			if (curr->key < ptr->key)
				curr = curr->right;
			else
				curr = curr->left;
		}
	}

	if(ptr->key > keyMin)
		brojCvorova(keyMin, valueMin, ptr->left);

	brojCvorova(keyMin, valueMin, ptr->right);

	brojProlaza++;
	//return brojProlaza;
	return count;
}

//kol2 2021
int BSTreeInt::deleteAllLeftLeafs(BSTNodeInt* ptr)
{
	//brise sve listove koji su lefi potomci rodjitelja i vraca broj obrisanih
	static int count = 0;

	if (ptr == NULL)
		return 0;

	if (ptr->left != NULL)
	{
		if (ptr->left->left == NULL && ptr->left->right == NULL)
		{
			ptr->left = NULL;
			delete ptr->left;
			count++;
		}
	}

	deleteAllLeftLeafs(ptr->left);
	deleteAllLeftLeafs(ptr->right);

	return count;
}

//kol2 2019
int BSTreeInt::count(BSTNodeInt* ptr)
{
	//racuna broj elemenata u stablu
	if (ptr == NULL)
		return 0;

	return 1 + count(ptr->left) + count(ptr->right);
}
int BSTreeInt::maxNode(int& maxN, BSTNodeInt* ptr)
{
	//uporedjuje levo i desno podstablo svakog cvora i vraca info deo cvora sa najvecom razlikom
	//u broju elemenata levog i desnog podstabla preko povratne vrednosti, a razliku preko maxN
	
	if (ptr == NULL)
		return 0;

	static int levo = 0, desno = 0, razlika;
	static int maxRazlika = 0;

	levo = count(ptr->left);
	desno = count(ptr->right);

	razlika = abs(levo - desno);

	if (razlika > maxRazlika)
	{
		maxRazlika = razlika;
		maxN = ptr->key;
	}

	maxNode(maxN, ptr->left);
	maxNode(maxN, ptr->right);

	return maxRazlika;
}

//septembar 2022
int BSTreeInt::countNodesInRange(int min, int max, BSTNodeInt* ptr)
{
	//broji koliko ima cvorova u intervalu [min, max] ali tako da prolazi samo
	//kroz neophodne cvorove.

	if (ptr == NULL)
		return 0;

	static int count = 0;
	static int brojProlaza = 0;

	brojProlaza++;

	if(ptr->key >= min && ptr->key <= max)
		count++;
	if (ptr->key >= min)
		countNodesInRange(min, max, ptr->left);
	if (ptr->key <= max)
		countNodesInRange(min, max, ptr->right);

	return count;
	//return brojProlaza;
}

//jun2 2021
BSTNodeInt* BSTreeInt::findNodeWithLargestRightSubtree()
{
	//trazi cvor sa najvecim brojem cvorova u desnom podstablu
	BSTNodeInt* ptr = root;
	BSTNodeInt* ptrRight;
	BSTNodeInt* maxNode = nullptr;
	int countRight = 0;
	int max = 0;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	QueueAsArrayBSTNodeInt queueRight(numOfElements);
	if (ptr != nullptr)
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			
			//broj cvorove u desnom podstablu
			countRight = 0;
			ptrRight = ptr->right;
			if (ptrRight != nullptr)
			{
				queueRight.enqueue(ptrRight);
				while (!queueRight.isEmpty())
				{
					ptrRight = queueRight.dequeue();
					countRight++;
					if (ptrRight->left != nullptr)
						queueRight.enqueue(ptrRight->left);
					if (ptrRight->right != nullptr)
						queueRight.enqueue(ptrRight->right);
				}
			}

			if (countRight > max)
			{
				max = countRight;
				maxNode = ptr; 
			}

			if (ptr->left != nullptr)
				queue.enqueue(ptr->left);
			if (ptr->right != nullptr)
				queue.enqueue(ptr->right);
		}
	}

	return maxNode;
}

//oktobar2 2022
BSTNodeInt* BSTreeInt::findSibling(BSTNodeInt* p)
{
	//trazi da li p ima neki cvor u istom nivuo kao i on i vraca bilo koji
	//ako p nema brace vraca null, pretraga se prekinje kada se nadje cvor i 
	//potrebno je samo jednom proci kroz stablo

	QueueAsArrayBSTNodeInt queue(numOfElements);
	BSTNodeInt* ptr = root,* prev = root, * next = nullptr;
	if (ptr != nullptr)
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty())
		{
			prev = ptr;
			ptr = queue.dequeue();
			
			if (ptr == p)//pronaso je trazeni cvor
			{
				//proverava se prethodni i sledeci cvor u redu (kanditati za sibling)
				//mora da se zadovolji uslov:
				//trenutni ptr mora da bude veci od prethodnog (tada je prethodni njegov sibling)
				//trenutni ptr mora da bude manji od sledeceg (tada je sledeci njegov sibling)
				//vazi samo za uredjena stabla

				if (ptr->key > prev->key && prev->left != ptr && prev->right != ptr) //proverava se granicni slucaj, da li je prev roditelj od ptr
					return prev;
				BSTNodeInt* next = queue.getHead();
				if (ptr->key < next->key && ptr->left != next && ptr->right != next) //isto granicni slucaj
					return next;
			}

			if (ptr->left != nullptr)
				queue.enqueue(ptr->left);
			if (ptr->right != nullptr)
				queue.enqueue(ptr->right);
		}
	}

	return nullptr;
}

//jun 2022
bool BSTreeInt::isPerfect()
{
	//proverava da li je stablo perfektno balansirano - 
	//broj cvorova u levom i desnom podstablu bilo kog cvora ne razlikuje za vise od 1

	QueueAsArrayBSTNodeInt queue(numOfElements);
	QueueAsArrayBSTNodeInt leftQueue(numOfElements);
	QueueAsArrayBSTNodeInt rightQueue(numOfElements);
	BSTNodeInt* ptr = root;
	if (ptr != NULL)
	{
		queue.enqueue(ptr);
		while (!queue.isEmpty())
		{
			ptr = queue.dequeue();
			//broji cvorove u levom podstablu
			int countLevi = 0;
			BSTNodeInt* ptr2 = ptr->left;
			if (ptr2 != NULL)
			{
				leftQueue.enqueue(ptr2);
				while (!leftQueue.isEmpty())
				{
					ptr2 = leftQueue.dequeue();
					countLevi++;
					if (ptr2->left != NULL)
						leftQueue.enqueue(ptr2->left);
					if (ptr2->right != NULL)
						leftQueue.enqueue(ptr2->right);
				}
			}

			//broji cvorove u desnom podstablu
			int countDesni = 0;
			ptr2 = ptr->right;
			if (ptr2 != NULL)
			{
				rightQueue.enqueue(ptr2);
				while (!rightQueue.isEmpty())
				{
					ptr2 = rightQueue.dequeue();
					countDesni++;
					if (ptr2->left != NULL)
						rightQueue.enqueue(ptr2->left);
					if (ptr2->right != NULL)
						rightQueue.enqueue(ptr2->right);
				}
			}

			if (abs(countLevi - countDesni) > 1)
				return false;

			if (ptr->left != NULL)
				queue.enqueue(ptr->left);
			if (ptr->right != NULL)
				queue.enqueue(ptr->right);
		}
	}

	return true;
}