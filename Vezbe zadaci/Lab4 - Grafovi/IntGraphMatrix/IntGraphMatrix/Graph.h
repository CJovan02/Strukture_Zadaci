#pragma once
class Graph
{
public:
	int** matrix;
	int brEl;
	int maxDim;
	int* nizCvorova;

public:

	Graph();
	Graph(int);
	void dodajCvor(int);
	void dodajVezu(int, int);
	int nadjiCvor(int);
	void print();

	//7. zad
	int maxInDeg();

	//8. zad
	int maxOutDeg();

	//9. zad
	int countZeroIn();

	//10. zad
	int countZeroOut();

	//bonus zad
	bool isStronglyConnected();
};

