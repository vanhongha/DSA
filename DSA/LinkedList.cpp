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
		return;
	}

	cout << "List: ";
	Node<T>* node = this->head;
	while (node != nullptr) {
		cout << node->GetData() << "\t";
		node = node->GetNextNode();
	}
	cout << endl;
}

template <typename T>
int LinkedList<T>::GetSize() {
	return this->size;
}

template <typename T>
Node<T>* LinkedList<T>::InsertAt(int _i, T _data) {
	if (_i < 0) {
		cout << "Please enter valid index number!" << endl;
		return nullptr;
	}

	if (this->head == nullptr) {
		return nullptr;
	}

	if (_i >= this->size) {
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
Node<T>* LinkedList<T>::GetNodeAt(int _i) {
	if (_i < 0) {
		return nullptr;
	}

	if (this->head == nullptr) {
		return nullptr;
	}

	int count = 0;
	Node<T>* node = this->head;

	while (node != nullptr) {
		if (count == _i) {
			return node;
		}
		count++;
		node = node->GetNextNode();
	}

	return nullptr;
}

template <typename T>
Node<T>* LinkedList<T>::InsertToHead(T _data) {
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

	Node<T>* node = this->head;
	while (node->GetNextNode() != nullptr) {
		node = node->GetNextNode();
	}
	node->SetNextNode(new Node<T>(_data));
	this->size++;

	return node->GetNextNode();
}

template <typename T>
bool LinkedList<T>::RemoveAt(int _i) {
	if (_i < 0) {
		cout << "Please enter valid index number!" << endl;
		return false;
	}

	if (this->head == nullptr) {
		return false;
	}

	if (_i >= this->size) {
		return false;
	}

	if (_i == 0) {
		Node<T>* node = this->head;
		this->head = node->GetNextNode();
		node->SetNextNode(nullptr);
		delete(node);
		this->size--;
		return true;
	}

	Node<T>* prev_node = this->head;
	Node<T>* delete_node = prev_node->GetNextNode();
	int node_count = 1;
	while (prev_node != nullptr) {
		if (node_count >= _i) {
			break;
		}

		prev_node = prev_node->GetNextNode();
		delete_node = prev_node->GetNextNode();
		node_count++;
	}
	prev_node->SetNextNode(delete_node->GetNextNode());
	delete_node->SetNextNode(nullptr);
	delete(delete_node);
	this->size--;

	return true;
}

template<typename T>
void LinkedList<T>::Reversal() {
	if (this->head == nullptr) {
		return;
	}

	Node<T>* prev_node = nullptr;
	Node<T>* cur_node = this->head;
	Node<T>* next_node = cur_node->GetNextNode();

	while (cur_node != nullptr) {
		cur_node->SetNextNode(prev_node);
		prev_node = cur_node;
		cur_node = next_node;
		if (next_node == nullptr) {
			this->head = prev_node;
			break;
		}
		next_node = next_node->GetNextNode();
	}

}

template<typename T>
bool LinkedList<T>::IsLooped() {
	if (this->head == nullptr) {
		return false;
	}

	Node<T>* slow_node = this->head;
	Node<T>* fast_node = this->head;

	while (slow_node != nullptr && fast_node != nullptr) {
		slow_node = slow_node->GetNextNode();
		fast_node = fast_node->GetNextNode();
		if (fast_node == nullptr || fast_node->GetNextNode() == nullptr) {
			return false;
		}
		fast_node = fast_node->GetNextNode();
		if (slow_node == fast_node) {
			return true;
		}
	}

	return false;
}

template<typename T>
bool LinkedList<T>::IsEmpty() {
	return this->head == nullptr;
}
#endif