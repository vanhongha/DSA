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
	this->size = 0;
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
int LinkedList<T>::GetSize() {
	return this->size;
}

template <typename T>
Node<T> *LinkedList<T>::InsertAt(int _i, T _data) {
	if (_i < 0) {
		cout << "Please enter valid index number!" << endl;
	}

	if (this->head == nullptr) {
		cout << "Can not insert at " << _i << " because the linked list is empty!" << endl;
		return nullptr;
	}

	if (_i >= this->size) {
		cout << "Can not insert at " << _i << " because current linked list only has " << this->size << " elements" << endl << endl;
		return nullptr;
	}

	if (_i == 0) {
		return this->InsertToHead(_data);
	}

	Node<T>* node = head;
	Node<T>* next_node = node->GetNextNode();
	int node_count = 0;
	while (node != nullptr) {
		if (node_count >= _i - 1) {
			break;
		}
		node = node->GetNextNode();
		next_node = node->GetNextNode();
		node_count++;
	}

	Node<T>* new_node = new Node<T>(_data);
	node->SetNextNode(new_node);
	new_node->SetNextNode(next_node);
	this->size++;

	return new_node;
}

template <typename T>
Node<T> *LinkedList<T>::InsertToHead(T _data) {
	if (this->head == nullptr) {
		this->head = new Node<T>(_data);
		this->size++;
		return this->head;
	}

	Node<T>* node = new Node<T>(_data);
	node->SetNextNode(head);
	this->head = node;
	this->size++;

	return node;
}

template <typename T>
Node<T>* LinkedList<T>::InsertToTail(T _data) {
	if (this->head == nullptr) {
		this->head = new Node<T>(_data);
		this->size++;
		return this->head;
	}

	Node<T>* node = head;
	while (node->GetNextNode() != nullptr) {
		node = node->GetNextNode();
	}
	node->SetNextNode(new Node<T>(_data));
	this->size++;

	return node->GetNextNode();
}
#endif