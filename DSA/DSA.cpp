#include <iostream>
#include <sstream>
#include "FileHelper.h"
#include "Graph.h"
using namespace std;

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
}