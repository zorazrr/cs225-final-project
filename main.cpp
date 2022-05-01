#include "dijkstra.h"
#include "welsh.h"
#include <iostream>

using namespace std;

int main()
{
    Graph smallGraph;
    smallGraph.makeGraph("data/test_disjoint_nodes.txt", "data/test_disjoint_roads.txt");

    Graph mediumGraph;
    mediumGraph.makeGraph("data/test_nodes.txt", "data/test_roads.txt");

    Graph largeGraph;
    largeGraph.makeGraph("data/nodes.txt", "data/roads.txt");

    // Dijkstras Tests
    Dijkstra d(largeGraph, 128);
    d.printOnePath(411);
    // Dijkstra d(largeGraph, 0);
    // d.printPaths();

    // Colorability Tests
    // Welsh welsh(smallGraph);
    // vector<int> colors = welsh.getColors();
    // for (auto color : colors) {
    //     std::cout << color << ", ";
    // }
    // std::cout << "\n";

    return 0;
}