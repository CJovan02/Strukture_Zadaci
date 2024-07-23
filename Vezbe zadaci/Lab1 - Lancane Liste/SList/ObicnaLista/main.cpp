#include <iostream>
#include "LList.h"
#include "LLNode.h"

using namespace std;

void main()
{
	LList list;
	list.AddToHead(1);
	list.AddToHead(2);
	list.AddToHead(3);
	list.AddToHead(4);
	list.AddToHead(5);

	list.Print();

	cout << list.FindNodePtr(1);
	cout << list.FindNodePtr(3);
	cout << list.FindNodePtr(5);
}