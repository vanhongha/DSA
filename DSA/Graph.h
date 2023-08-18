#include "LinkedList.h"

#pragma once

class Graph {
private:
	int verticals;
	LinkedList<int>* array_list;
public:
	Graph(int);
	void AddEdge(int vertex, int edge);
	void Print(); // Print as Adjacency list
};
