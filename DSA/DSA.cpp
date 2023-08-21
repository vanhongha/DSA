#include <iostream>
#include <sstream>
#include "FileHelper.h"
#include "Graph.h"
#include "Queue.h"
using namespace std;

/* PROBLEMS */
void BreadthFirstSearch(Graph*);


int main()
{
	vector<string> lines = FileHelper::ReadFile("import.txt");
    int verticals = stoi(lines[0]);
    string segment;

    Graph* graph = new Graph(verticals);
    for (int i = 1; i < lines.size(); i++) {
        if (lines[i].size() > 0) {
            stringstream ss(lines[i]);
            while (getline(ss, segment, ',')) {
                graph->AddEdge(i - 1, stoi(segment));
            }
        }
    }
    graph->Print();
    BreadthFirstSearch(graph);
}

void BreadthFirstSearch(Graph* graph) {
    cout << "Breadth first search: ";
    int vertical = graph->GetVerticals();

    bool* visited = new bool[vertical];
    for (int i = 0; i < vertical; i++) {
        visited[i] = false;
    }

    Queue* queue = new Queue();
    for (int i = 0; i < vertical; i++) {
        if (!visited[i]) {
            visited[i] = true;
            queue->Enqueue(i);
        }

        int node_num = queue->Dequeue();
        cout << "\t" << node_num;
        Node<int>* node = graph->GetArrayList()[node_num].GetNodeAt(0);
        while (node != nullptr) {
            if (!visited[node->GetData()]) {
                queue->Enqueue(node->GetData());
                visited[node->GetData()] = true;
            }
            node = node->GetNextNode();
        }
    }

    cout << endl;
}