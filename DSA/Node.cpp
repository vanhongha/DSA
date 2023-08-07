#include "Node.h"

#pragma once
#ifndef _NODE_CPP_
#define _NODE_CPP_

template <typename T>
Node<T>::Node(T _data) {
	this->data = _data;
	this->next_node = nullptr;
}

template <typename T>
T Node<T>::GetData() {
	return this->data;
}

template <typename T>
Node<T> *Node<T>::GetNextNode() {
	return this->next_node;
}

template <typename T>
void Node<T>::SetNextNode(Node<T>* _node) {
	this->next_node = _node;
}

#endif