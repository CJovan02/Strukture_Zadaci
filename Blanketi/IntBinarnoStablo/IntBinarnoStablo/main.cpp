#include "BSTreeInt.h"
#include <iostream>
using namespace std;

void main()
{
	BSTreeInt* stablo = new BSTreeInt();

	/*stablo->insert(0);
	stablo->insert(7);
	stablo->insert(4);
	stablo->insert(9);
	stablo->insert(2);
	stablo->insert(6);
	stablo->insert(8);
	stablo->insert(10);
	stablo->insert(1);
	stablo->insert(5);
	stablo->insert(11);
	stablo->insert(12);*/

	/*stablo->insert(50);
	stablo->insert(20);
	stablo->insert(70);
	stablo->insert(5);
	stablo->insert(65);
	stablo->insert(90);
	stablo->insert(8);
	stablo->insert(60);
	stablo->insert(68);
	stablo->insert(110);
	stablo->insert(7);
	stablo->insert(10);
	stablo->insert(6);
	stablo->insert(9);
	stablo->insert(12);
	stablo->insert(14);*/

	/*stablo->insert(25);
	stablo->insert(20);
	stablo->insert(39);
	stablo->insert(18);
	stablo->insert(24);
	stablo->insert(35);
	stablo->insert(80);

	stablo->breadthFirstSearch();
	cout << stablo->isPerfect();*/

	stablo->insert(15);
	stablo->insert(10);
	stablo->insert(12);
	stablo->insert(60);
	stablo->insert(8);
	stablo->insert(7);
	stablo->insert(5);
	stablo->inorder();
	stablo->postorder();
	stablo->preorder();

	delete stablo;
}