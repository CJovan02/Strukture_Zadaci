#include <iostream>
#include "Stack.h"
using namespace std;

void main()
{
	try
	{
		Stack s(100);

		s.Push(1);
		s.Push(2);
		s.Push(3);

		cout << s.Pop() << " ";
		cout << s.Pop() << " ";
		cout << s.Pop() << " ";
	}
	catch (const char* txt)
	{
		cerr << txt << endl;
	}
}