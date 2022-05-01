#include "dijkstra.h"
#include <iostream>

using namespace std;

int main() {
    Graph newGraph;
    newGraph.makeGraph("data/test_nodes.txt", "data/test_roads.txt");
    Dijkstra d(newGraph, 0);

    d.printPaths();
    return 0;
}