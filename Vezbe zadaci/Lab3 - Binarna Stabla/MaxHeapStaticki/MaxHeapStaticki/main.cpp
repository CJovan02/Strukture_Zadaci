#include "MaxHeap.h"
#include <iostream>
using namespace std;

void main()
{
	MaxHeap heap(10);

	heap.insert(1);
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.insert(5);
	heap.insert(6);

	/*heap.insertIntoMin(6);
	heap.insertIntoMin(5);
	heap.insertIntoMin(4);
	heap.insertIntoMin(3);
	heap.insertIntoMin(2);
	heap.insertIntoMin(1);*/

	heap.print();
	heap.transformIntoMin();
	heap.print();
}