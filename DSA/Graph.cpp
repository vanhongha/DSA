#include "Graph.h"
#include "LinkedList.h"

Graph::Graph(int _vertices) {
	array_list = new LinkedList<int>[_vertices];
	this->vertices = _vertices;
}

void Graph::AddEdge(int vertex, int edge) {
	if (vertex >= vertices) {
		cout << "Please enter vertex smaller than number of vertices" << endl;
		return;
	}

	if (edge >= vertices) {
		cout << "Please enter edge smaller than number of vertices" << endl;
		return;
	}

	this->array_list[vertex].InsertToTail(edge);
}

void Graph::Print() {
	for (int i = 0; i < this->vertices; i++) {
		LinkedList<int> list = this->array_list[i];
		Node<int> *node = list.GetNodeAt(0);

		cout << "|" << i << "|" << " : ";
		while (node != nullptr) {
			cout << "[" << node->GetData() << "]" << " -> ";
			node = node->GetNextNode();
		}
		cout << "NULL" << endl;
	}
}

int Graph::GetVertices() {
	return this->vertices;
}

LinkedList<int>* Graph::GetArrayList() {
	return this->array_list;
}