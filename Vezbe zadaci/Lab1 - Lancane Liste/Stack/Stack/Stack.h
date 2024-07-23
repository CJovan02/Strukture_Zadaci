#pragma once
class Stack
{
private:
	float* array;
	int size;
	int top;
public:
	Stack(int size);
	~Stack();
	bool IsEmpty();
	void Push(float el);
	float Pop();
	float GetTop();
	int NumberOfElements();
};

