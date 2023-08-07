#include <iostream>
#include "LinkedList.h"
using namespace std;

#pragma once
#ifndef _LINKEDLIST_CPP_
#define _LINKEDLIST_CPP_

template<typename T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
}

template <typename T>
void LinkedList<T>::Print() {
	if (this->head == nullptr) {
		cout << "Linked list is NULL!" << endl;
		return;
	}

	cout << "Linked list: ";
	Node<T>* node = this->head;
	while (node != nullptr) {
		cout << node->GetData() << "\t";
		node = node->GetNextNode();
	}
}

template <typename T>
void LinkedList<T>::InsertAt(int _i, T _data) {

}

template <typename T>
Node<T> *LinkedList<T>::InsertToHead(T _data) {
	if (this->head == nullptr) {
		this->head = new Node<T>(_data);
		return this->head;
	}

	Node<T>* node = new Node<T>(_data);
	node->SetNextNode(head);
	head = node;

	return node;
}

template <typename T>
Node<T>* LinkedList<T>::InsertToTail(T _data) {
	if (this->head == nullptr) {
		this->head = new Node<T>(_data);
		return this->head;
	}

	Node<T>* node = head;
	while (node->GetNextNode() != nullptr) {
		node = node->GetNextNode();
	}
	node->SetNextNode(new Node<T>(_data));

	return node->GetNextNode();
}
#endif