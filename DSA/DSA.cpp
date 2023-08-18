#include <iostream>
#include "Graph.h"

int main()
{
    Graph* graph = new Graph(5);
    graph->AddEdge(2, 4);
    graph->Print();
}