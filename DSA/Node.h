#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	T data;
	Node* next_node;
public:
	Node(T _data);
	T GetData();
	Node<T>* GetNextNode();
	void SetNextNode(Node<T>* _node);
};

#include "NODE.cpp"

#endif