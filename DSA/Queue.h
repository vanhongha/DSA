#include "LinkedList.h"

#pragma once

class Queue {
private:
	LinkedList<int>* list;
public:
	Queue();
	void Print();
	void Enqueue(int value);
	int Dequeue();
	int GetFront();
	bool IsEmpty();
};