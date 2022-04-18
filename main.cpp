#include "dijkstra.h"
#include <iostream>

using namespace std;

int main() {
    Graph newGraph;
    newGraph.makeGraph("data/test_nodes.txt", "data/test_roads.txt");
    vector<pair<double, int>> paths = dijkstra(newGraph, 0);

    printPath(paths, 0);
    return 0;
}