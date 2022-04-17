#include "dijkstra.h"
#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello World" << std::endl;
    Graph newGraph;
    newGraph.makeGraph("data/small_test_nodes.txt", "data/small_test_roads.txt");
    vector<pair<double, int>> paths = dijkstra(newGraph, 0);

    for (unsigned i = 0; i < paths.size(); ++i) {
        std::cout << paths.at(i).first << " " << paths.at(i).second << std::endl;
    }
    return 0;
}