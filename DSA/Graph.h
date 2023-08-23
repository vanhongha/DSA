#include "LinkedList.h"

#pragma once

class Graph {
private:
	int vertices;
	LinkedList<int>* array_list;
public:
	Graph(int);
	void AddEdge(int vertex, int edge);
	void Print(); // Print as Adjacency list
	int GetVertices();
	LinkedList<int>* GetArrayList();
};
