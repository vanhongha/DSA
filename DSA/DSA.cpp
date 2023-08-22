#include <iostream>
#include <sstream>
#include "FileHelper.h"
#include "Graph.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

/* PROBLEMS */
void BreadthFirstSearch(Graph*);
void DepthFirstSearch(Graph*);
bool IsCycled(Graph*);

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
    DepthFirstSearch(graph);

    if (IsCycled(graph)) {
        cout << "Graph is cycled" << endl;
    }
    else {
        cout << "Graph is not cycled" << endl;
    }
}

void BreadthFirstSearch(Graph* graph) {
    cout << "Breadth first search: ";
    int verticals = graph->GetVerticals();

    bool* visited = new bool[verticals];
    for (int i = 0; i < verticals; i++) {
        visited[i] = false;
    }

    Queue* queue = new Queue();
    for (int i = 0; i < verticals; i++) {
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

void DepthFirstSearch(Graph* graph) {
    cout << "Depth first search: ";
    int verticals = graph->GetVerticals();

    bool* visited = new bool[verticals];
    for (int i = 0; i < verticals; i++) {
        visited[i] = false;
    }

    Stack* stack = new Stack();
    for (int i = 0; i < verticals; i++) {
        if (!visited[i]) {
            stack->Push(i);
            visited[i] = true;
        }

        int node_num = stack->Pop();
        cout << "\t" << node_num;
        Node<int>* node = graph->GetArrayList()[node_num].GetNodeAt(0);
        while (node != nullptr) {
            if (!visited[node->GetData()]) {
                stack->Push(node->GetData());
                visited[node->GetData()] = true;
            }
            node = node->GetNextNode();
        }
    }

    cout << endl;
}

bool IsCycled(Graph* graph) {
    int verticals = graph->GetVerticals();

    bool* visited = new bool[verticals];
    for (int i = 0; i < verticals; i++) {
        visited[i] = false;
    }

    Stack* stack = new Stack();
    for (int i = 0; i < verticals; i++) {
        if (!visited[i]) {
            visited[i] = true;
            stack->Push(i);
        }

        int node_num = stack->Pop();
        Node<int>* node = graph->GetArrayList()[node_num].GetNodeAt(0);
        while (node != nullptr) {
            if (visited[node->GetData()]) {
                return true;
            }
            stack->Push(node->GetData());
            visited[node->GetData()] = true;
            node = node->GetNextNode();
        }
    }

    return false;
}