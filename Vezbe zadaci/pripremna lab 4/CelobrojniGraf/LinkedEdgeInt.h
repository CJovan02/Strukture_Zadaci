#pragma once

class LinkedNodeInt;

class LinkedEdgeInt
{
public:
	LinkedNodeInt* dest; //pokazivac na odredisni cvor grane
	double weight;  //vrednost na grani
	LinkedEdgeInt* link; //pokazivac na sledecu granu u listi povezanih grana

	LinkedEdgeInt();
	LinkedEdgeInt(LinkedNodeInt* destN, LinkedEdgeInt* linkN);
	LinkedEdgeInt(LinkedNodeInt* destN, double weightN, LinkedEdgeInt* linkN);
};
