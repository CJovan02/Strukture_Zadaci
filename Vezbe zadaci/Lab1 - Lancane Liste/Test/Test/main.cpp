#include <iostream>
#include "Kvadrat.h"
using namespace std;

void main()
{
	Kvadrat* kv = new Kvadrat(4);
	kv->Print();
	cout << kv->GetA();
	delete kv;
}