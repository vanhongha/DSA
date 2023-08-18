#include "Node.h"

#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <typename T>
class LinkedList
{
private:
	Node<T>* head;
	int size;
public:
	LinkedList();
	void Print();
	int GetSize();
	Node<T> *InsertToHead(T _data);
	Node<T> *InsertToTail(T _data);
	Node<T> *InsertAt(int _i, T _data);
	Node<T> *GetNodeAt(int _i);
	bool RemoveAt(int _i);
	void Reversal();
	bool IsLooped();
};

#include "LINKEDLIST.cpp"

#endif