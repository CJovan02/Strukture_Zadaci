#pragma once
#include <iostream>
using namespace std;
class BSTNodeInt
{
public:
	int key;
	int value;
	BSTNodeInt* left, * right;

public:
	void setKey(int el) { key = el; }
	int getKey() { return key; }

	BSTNodeInt() { key = NULL; left = right = nullptr; }
	BSTNodeInt(int el) { key = el; left = right = nullptr; }
	BSTNodeInt(int el, BSTNodeInt* left, BSTNodeInt* right) { key = el; this->left = left; this->right = right; }
	BSTNodeInt(int key, int value, BSTNodeInt* left, BSTNodeInt* right) { this->key = key; this->value = value; this->left = left; this->right = right; }

	bool isLT(int el) { return key < el; }
	bool isGT(int el) { return key > el; }
	bool isEQ(int el) { return key == el; }

	void visit() { cout << key << " "; }
};

