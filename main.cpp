#include "dijkstra.h"
#include "welsh.h"
#include <iostream>

using namespace std;

int main()
{
    Graph newGraph;
    newGraph.makeGraph("data/test_disjoint_nodes.txt", "data/test_disjoint_roads.txt");

    // Dijkstras Tests
    // Dijkstra d(newGraph, 0);
    // d.printPaths();

    // Colorability Tests
    Welsh welsh(newGraph);
    welsh.executeWelsh();
    vector<int> colors = welsh.getColors();
    for (auto color : colors) {
        std::cout << color << " ";
    }
    std::cout << "\n";

    return 0;
}