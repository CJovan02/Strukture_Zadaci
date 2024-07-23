#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
	this->size = size;
	array = new float[size];
	top = -1;
}
Stack::~Stack()
{
	delete[] array;
}
bool Stack::IsEmpty()
{
	return top == -1;
}
void Stack::Push(float el)
{
	if (top == size - 1)
		throw new exception("Stack Overflow");
	array[++top] = el;
}
float Stack::Pop()
{
	if (top == -1)
		throw new exception("Stack underflow");
	return array[top--];
}
float Stack::GetTop()
{
	if (top == -1)
		throw new exception("Stack underflow!");
	return array[top];
}
int Stack::NumberOfElements()
{
	return top + 1;
}