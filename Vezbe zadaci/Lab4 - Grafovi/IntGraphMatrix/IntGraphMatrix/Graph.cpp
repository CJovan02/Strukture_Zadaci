#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph()
{
	matrix = NULL;
	brEl = 0;
	maxDim = 0;
	nizCvorova = NULL;
}
Graph::Graph(int maxDimN)
{
	maxDim = maxDimN;
	brEl = 0;
	matrix = new int* [maxDim];
	nizCvorova = new int[maxDim];

	for (int i = 0; i < maxDim; i++)
	{
		matrix[i] = new int[maxDim];
		nizCvorova[i] = 0;
	}
	for (int i = 0; i < maxDim; i++)
		for (int j = 0; j < maxDim; j++)
			matrix[i][j] = 0;
}
void Graph::dodajCvor(int data)
{
	nizCvorova[brEl++] = data;
}
void Graph::dodajVezu(int a, int b)
{
	int i = nadjiCvor(a);
	int j = nadjiCvor(b);
	if(i != -1 && j != -1)
		matrix[i][j] = 1;
}
int Graph::nadjiCvor(int data)
{
	for (int i = 0; i < brEl; i++)
		if (data == nizCvorova[i])
			return i;

	return -1;
}
void Graph::print()
{
	cout << "Cvorovi: " << endl;
	for (int i = 0; i < brEl; i++)
		cout << nizCvorova[i] << " ";

	cout << endl << "Matrica susedstva: " << endl;
	for (int i = 0; i < brEl; i++)
	{
		for (int j = 0; j < brEl; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

//7. zad
int Graph::maxInDeg()
{
	int max = 0;
	int count;
	int result = -1;
	for (int j = 0; j < brEl; j++)
	{
		count = 0;
		for (int i = 0; i < brEl; i++)
		{
			if (matrix[i][j] == 1)
				count++;
		}
		if (count > max)
		{
			max = count;
			result = nizCvorova[j];
		}
	}

	if (result != -1)
	{
		cout << "Cvor sa najvecim ulaznim stepenom je: " << result << "." << endl;
		cout << "Njegov ulazni stepen je: " << max << "." << endl;
	}
	else
		cout << "Stablo nema ulaznih cvorova";

	return result;
}

//8. zad
int Graph::maxOutDeg()
{
	int max = 0;
	int result = -1;
	int count;

	for (int i = 0; i < brEl; i++)
	{
		count = 0;
		for (int j = 0; j < brEl; j++)
		{
			if (matrix[i][j] == 1)
				count++;
		}
		if (count > max)
		{
			result = nizCvorova[i];
			max = count;
		}
	}

	if (result != -1)
	{
		cout << "Cvor sa najvecim izlaznim stepenom je: " << result << "." << endl;
		cout << "Njegov izlazni stepen je: " << max << "." << endl;
	}
	else
		cout << "Stablo nema izlaznih cvorova";

	return result;
}

//9. zad
int Graph::countZeroIn()
{
	cout << "Cvorovi koji nemaju ulazni stepen: ";
	int count;
	int result = 0;
	for (int j = 0; j < brEl; j++)
	{
		count = 0;
		for (int i = 0; i < brEl; i++)
		{
			if (matrix[i][j] == 1)
				count++;
		}
		if (count == 0)
		{
			cout << nizCvorova[j] << " ";
			result++;
		}
	}
	cout << endl;
	return result;
}

//10. zad
int Graph::countZeroOut()
{
	cout << "Cvorovi koji nemaju izlazni stepen: ";
	int count;
	int result = 0;
	for (int i = 0; i < brEl; i++)
	{
		count = 0;
		for (int j = 0; j < brEl; j++)
		{
			if (matrix[i][j] == 1)
				count++;
		}
		if (count == 0)
		{
			cout << nizCvorova[i] << " ";
			result++;
		}
	}

	cout << endl;
	return result;
}

//bonus zad
bool Graph::isStronglyConnected()
{
	int br = 0;
	for (int i = 0; i < maxDim; i++)
	{
		for (int j = 0; i < maxDim; i++)
		{
			if (matrix[i][j] == 1 && matrix[i][j] == matrix[j][i])
				br++;
		}
	}
	if (br == brEl * brEl)
		return true;
	return false;
}