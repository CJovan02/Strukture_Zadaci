#pragma once
#include "BSTNodeInt.h"

class BSTreeInt
{
public:
	BSTNodeInt* root;
	int numOfElements;

public:
	BSTreeInt() { root = nullptr; numOfElements = 0; }
	~BSTreeInt() { deleteTree(root); }
	void deleteTree(BSTNodeInt* node);

	bool isEmpty() { return root == nullptr; }

	void insert(int el);
	void insert(int el, double value);

	BSTNodeInt* search(int el);
	bool isInTree(int el) { return search(el) != nullptr; }

	void deleteByCopying(int el);
	void deleteByMerging(int el);

	void preorder(BSTNodeInt* ptr);
	void inorder(BSTNodeInt* ptr);
	void postorder(BSTNodeInt* ptr);

	void preorder() { preorder(root); cout << endl; }
	void inorder() { inorder(root); cout << endl; }
	void postorder() { postorder(root); cout << endl; }
	void iterativePreorder();
	void breadthFirstSearch();

	//zadaci za pripremu vezbe
	int distinctElementsIterative();
	int distinct(BSTNodeInt* ptr);
	int distinct() { return distinct(root); }
	void insertDistinct(int* arr, int& count, int el);

	int heightIterative();
	int height(BSTNodeInt* ptr);
	int height() { return height(root); }

	int momentIterative();
	int moment(BSTNodeInt* ptr);
	int moment() { return moment(root); }

	int weightIterative();
	int weight(BSTNodeInt* ptr);
	int weight() { return weight(root); }

	void deleteListsIterative();
	void deleteLeafs(BSTNodeInt* ptr);
	void deleteLeafs() { deleteLeafs(root); }

	void dupliraj() { dupliraj(root); }
	void dupliraj(BSTNodeInt* ptr);

	int suma() { return suma(root); }
	int suma(BSTNodeInt* ptr);
	int findMax() { return findMax(root); }
	int findMax(BSTNodeInt* ptr);

	void mirror() { mirror(root); }
	void mirror(BSTNodeInt* ptr);

	BSTreeInt* duplicate() { return duplicate(root); }
	BSTreeInt* duplicate(BSTNodeInt* ptr);

	void spojiStabla(BSTreeInt* b, BSTreeInt* result) { spojiStabla(root, b->root, result); }
	void spojiStabla(BSTNodeInt* a, BSTNodeInt* b, BSTreeInt* result);

	int sumOfLeafs(BSTNodeInt* ptr);
	int sumOfLeafs() { return sumOfLeafs(root); }

	/* ------------------------------------------------------------------------------ */
	/* ---------------------------------- blanketi ---------------------------------- */
	/* ------------------------------------------------------------------------------ */

	//jun2 2022
	int brojCvorova(int keyMin, double valueMin) { return brojCvorova(keyMin, valueMin, root); }
	int brojCvorova(int keyMin, double valueMin, BSTNodeInt* ptr);

	//kol2 2021
	int deleteAllLeftLeafs(BSTNodeInt* ptr);
	int deleteAllLeftLeafs() { return deleteAllLeftLeafs(root); }

	//kol2 2019
	int count() { return count(root); }
	int count(BSTNodeInt* ptr);

	int maxNode(int& maxN) { return maxNode(maxN, root); }
	int maxNode(int& maxN, BSTNodeInt* ptr);

	//septembar 2022
	int countNodesInRange(int min, int max) { return countNodesInRange(min, max, root); }
	int countNodesInRange(int min, int max, BSTNodeInt* ptr);

	//jun2 2021
	BSTNodeInt* findNodeWithLargestRightSubtree();
	//BSTNodeInt* findNodeWithLargestRightSubtree(BSTNodeInt* ptr);

	//oktobar2 2022
	BSTNodeInt* findSibling(BSTNodeInt* p);

	//jun 2022
	bool isPerfect();
};

