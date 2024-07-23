#pragma once
#include "LinkedNode.h"
#include <iostream>
using namespace std;

class LinkedNode;

class Edge
{
public:
	LinkedNode* dest; //cvor na koji pokazuje
	Edge* link; //sledeca veza u listi
	double weight;

public:

	Edge() { dest = NULL; link = NULL; }
	Edge(LinkedNode* destN, Edge* linkN) { dest = destN; link = linkN; }
	Edge(LinkedNode* destN, Edge* linkN, double weightN) { dest = destN; link = linkN; weight = weightN; }
};

