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
vector<int> FindMotherVertex(Graph*); // TODO: find all mother vertex in another unconnected components
int CountEdge(Graph*);
bool HasPath(Graph*, int source, int destination);

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

    FindMotherVertex(graph);

    cout << "Number of edges: " << CountEdge(graph) << endl;

    int source = 0;
    int destination = 4;
    if (HasPath(graph, source, destination)) {
        cout << "There are paths from " << source << " to " << destination << endl;
    }
    else {
        cout << "There is no path from " << source << " to " << destination << endl;
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

vector<int> FindMotherVertex(Graph* graph) {
    vector<int> result;
    int verticals = graph->GetVerticals();

    int* visited_count = new int[verticals];

    for (int i = 0; i < verticals; i++) {
        visited_count[i] = 0;
    }

    Stack* stack = new Stack();
    for (int i = 0; i < verticals; i++) {
        stack->Push(i);

        int node_num = stack->Pop();
        visited_count[node_num]++;
        Node<int>* node = graph->GetArrayList()[node_num].GetNodeAt(0);
        while (node != nullptr) {
            visited_count[node->GetData()]++;
            node = node->GetNextNode();
        }
    }

    int min_visited_count = visited_count[0];
    for (int i = 1; i < verticals; i++) {
        if (visited_count[i] < min_visited_count) {
            min_visited_count = visited_count[i];
        }
    }

    cout << "List mother vertex: ";
    for (int i = 0; i < verticals;i++) {
        if (visited_count[i] == min_visited_count) {
            result.push_back(i);
            cout << "\t" << i;
        }
    }
    cout << endl;

    return result;
}

int CountEdge(Graph* graph) {
    int edge = 0;
    int verticals = graph->GetVerticals();

    for (int i = 0; i < verticals; i++) {
        Node<int>* node = graph->GetArrayList()[i].GetNodeAt(0);
        while (node != nullptr) {
            edge++;
            node = node->GetNextNode();
        }
    }

    return edge;
}

bool HasPath(Graph* graph, int source, int destination) {
    int verticals = graph->GetVerticals();
    if (source >= verticals || destination >= verticals) {
        return false;
    }

    Stack* stack = new Stack();
    stack->Push(source);
    while (!stack->IsEmpty()) {
        int node_num = stack->Pop();
        if (node_num == destination) {
            return true;
        }

        Node<int>* node = graph->GetArrayList()[node_num].GetNodeAt(0);
        while (node != nullptr) {
            stack->Push(node->GetData());
            node = node->GetNextNode();
        }
    }

    return false;
}