#include "StatickoStablo.h"
#include <iostream>
using namespace std;

StatickoStablo::StatickoStablo(int brojNivoa)
{
	t = 0;
	m = 1;
	for (int i = 0; i < brojNivoa; i++)
		m = m * 2;
	m--; //zbog korena
	cvorovi = new int* [m];
	for (int i = 0; i < m; i++)
		cvorovi[i] = NULL;
}
StatickoStablo::~StatickoStablo()
{
	if (cvorovi != NULL)
	{
		for (int i = 0; i < m; i++)
			if(cvorovi[i] != NULL)
				delete cvorovi[i];
	}
	delete[] cvorovi;
}
void StatickoStablo::ubaci(int el)
{
	if (t == m)
		throw new exception("Nema mesta");
	int curr = 0, prev;
	while (cvorovi[curr] != NULL && curr < m)
	{
		prev = curr;
		if (*cvorovi[curr] > el)
			curr = 2 * curr + 1;
		else
			curr = 2 * curr + 2;
	}
	if (curr > m)
		return;
	else if (cvorovi[0] == NULL)
	{
		cvorovi[0] = new int;
		*cvorovi[0] = el;
		t++;
	}
	else if (*cvorovi[prev] > el)
	{
		cvorovi[2 * prev + 1] = new int;
		*cvorovi[2 * prev + 1] = el;
		t++;
	}
	else
	{
		cvorovi[2 * prev + 2] = new int;
		*cvorovi[2 * prev + 2] = el;
		t++;
	}
}

void StatickoStablo::preorder(int i)
{
	if (i < m && cvorovi[i] != NULL)
	{
		cout << *cvorovi[i] << " ";
		preorder(2 * i + 1);
		preorder(2 * i + 2);
	}
}
void StatickoStablo::inorder(int i)
{
	if (i < m && cvorovi[i] != NULL)
	{
		inorder(2 * i + 1);
		cout << *cvorovi[i] << " ";
		inorder(2 * i + 2);
	}
}
void StatickoStablo::postorder(int i)
{
	if (i < m && cvorovi[i] != NULL)
	{
		postorder(2 * i + 1);
		postorder(2 * i + 2);
		cout << *cvorovi[i] << " ";
	}
}

int StatickoStablo::visina(int i)
{
	if (i >= m && cvorovi[i] == NULL)
		return 0;

	if((2 * i + 1 >= m || cvorovi[2 * i + 1] == NULL) && ((2 * i + 2 >= m || cvorovi[2 * i + 2] == NULL)))
		return 1;
	
	return 1 + max(visina(2 * i + 1), visina(2 * i + 2));
}

int StatickoStablo::max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int StatickoStablo::moment(int i)
{
	if (i >= m || cvorovi[i] == NULL)
		return 0;

	return 1 + moment(2 * i + 1) + moment(2 * i + 2);
}

//int StatickoStablo::tezina()
//{
//	int tezina = 0;
//	for (int i = 0; i < m; i++)
//	{
//		if (cvorovi[i] != NULL)
//		{
//			//Moguci slucajevi:
//			//Da premasimo opseg, to znaci da smo kod lista,
//			//ili, 2. slucaj, da JESTE u opsegu, ali da nema decu
//			//sto ponoovo znaci da je u pitanju list.
//			if (2 * i + 1 >= m)//tezina u dinamcikom je 1+rekurzija
//				tezina++;
//			else if (cvorovi[2 * i + 1] == NULL && cvorovi[2 * i + 2] == NULL)
//				tezina++;
//		}
//	}
//	return tezina;
//}

int StatickoStablo::tezina(int i)
{
	if (i >= m || cvorovi[i] == NULL)
		return 0;

	if ((2 * i + 1 >= m || cvorovi[2 * i + 1] == NULL) && ((2 * i + 2 >= m || cvorovi[2 * i + 2] == NULL)))
		return 1;
	else
	{
		return tezina(2 * i + 1) + tezina(2 * i + 2);
	}
}

void StatickoStablo::brisanjeListova(int i)
{
	if (i >= m || cvorovi[i] == NULL)
		return;

	if ((2 * i + 1 >= m || cvorovi[2 * i + 1] == NULL) && ((2 * i + 2 >= m || cvorovi[2 * i + 2] == NULL)))
	{
		delete cvorovi[i];
		cvorovi[i] = NULL;
	}
	else
	{
		brisanjeListova(2 * i + 1);
		brisanjeListova(2 * i + 2);
	}
}

int StatickoStablo::distinct(int i)
{
	if (i >= m || cvorovi[i] == NULL)
		return 0;

	static int count = 0;
	static int* arrDis = new int[m];

	insertDistinct(*cvorovi[i], arrDis, count);
	distinct(2 * i + 1);
	distinct(2 * i + 2);

	return count;
}

void StatickoStablo::insertDistinct(int el, int* arr, int& count)
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

void StatickoStablo::dupliraj(int i, StatickoStablo* result)
{
	if (i >= m || cvorovi[i] == NULL)
		return;

	result->ubaci(*cvorovi[i]);
	dupliraj(2 * i + 1, result);
	dupliraj(2 * i + 2, result);

}