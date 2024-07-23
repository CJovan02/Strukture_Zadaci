#include "StackAsArrayInt.h"

#include <exception>
using namespace std;

StackAsArrayLinkedNodeInt::StackAsArrayLinkedNodeInt(long nsize)
{
	size = nsize;
	arr = new LinkedNode * [size]();
	top = -1;
}

LinkedNode* StackAsArrayLinkedNodeInt::getTop() const
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return arr[top];
}

void StackAsArrayLinkedNodeInt::push(LinkedNode* object)
{
	if (top == (size - 1))
		throw new exception("Stack overflow!");
	arr[++top] = object;
}

LinkedNode* StackAsArrayLinkedNodeInt::pop()
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return arr[top--];
}
