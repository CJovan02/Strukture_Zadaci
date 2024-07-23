#pragma once
class MaxHeap
{
public:
	int* elements;
	int length;
	int count;

public:
	MaxHeap(int length);
	~MaxHeap();

	void insert(int el);
	void print();

	void mergeHeaps(MaxHeap&);

	void transformIntoMin();
	void insertIntoMin(int el);
};

