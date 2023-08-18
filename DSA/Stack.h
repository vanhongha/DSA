#include "LinkedList.h"

#pragma once

class Stack {
private:
	LinkedList<int>* list;
public:
	Stack();
	void Print();
	void Push(int value);
	int Pop();
	int GetTop();
	bool IsEmpty();
};