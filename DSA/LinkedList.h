#include "Node.h"

#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template <typename T>
class LinkedList
{
private:
	Node<T>* head;
public:
	LinkedList();
	void Print();
	Node<T> *InsertToHead(T _data);
	Node<T> *InsertToTail(T _data);
	void InsertAt(int _i, T _data);
	void RemoveAt(int _i);
};

#include "LINKEDLIST.cpp"

#endif