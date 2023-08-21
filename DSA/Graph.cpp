#include "Graph.h"
#include "LinkedList.h"

Graph::Graph(int _verticals) {
	array_list = new LinkedList<int>[_verticals];
	this->verticals = _verticals;
}

void Graph::AddEdge(int vertex, int edge) {
	if (vertex >= verticals) {
		cout << "Please enter vertex smaller than number of verticals" << endl;
		return;
	}

	if (edge >= verticals) {
		cout << "Please enter edge smaller than number of verticals" << endl;
		return;
	}

	this->array_list[vertex].InsertToTail(edge);
}

void Graph::Print() {
	for (int i = 0; i < this->verticals; i++) {
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

int Graph::GetVerticals() {
	return this->verticals;
}

LinkedList<int>* Graph::GetArrayList() {
	return this->array_list;
}