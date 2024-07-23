#pragma once
#include <iostream>
using namespace std;
class BSTNodeInt
{
public:
	int key;
	double value;
	BSTNodeInt* left, * right;

public:
	void setKey(int el) { key = el; }
	int getKey() { return key; }

	BSTNodeInt() { key = NULL; left = right = nullptr; value = 0; }
	BSTNodeInt(int el) { key = el; left = right = nullptr; value = 0; }
	BSTNodeInt(int el, double value) { key = el; this->value = value; left = right = nullptr; value = 0; }
	BSTNodeInt(int el, BSTNodeInt* left, BSTNodeInt* right) { key = el; this->left = left; this->right = right; value = 0; }
	BSTNodeInt(int key, double value, BSTNodeInt* left, BSTNodeInt* right) { this->key = key; this->value = value; this->left = left; this->right = right; }

	bool isLT(int el) { return key < el; }
	bool isGT(int el) { return key > el; }
	bool isEQ(int el) { return key == el; }

	void visit() { cout << key << " "; }
};

