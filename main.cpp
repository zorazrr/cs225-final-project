#include "dijkstra.h"
#include "welsh.h"
#include "utils.h"
#include "calipng.h"
#include "kdtree.h"
#include <iostream>

using namespace std;

void tests() {
    // Graph smallGraph;
    // smallGraph.makeGraph("data/test_disjoint_nodes.txt", "data/test_disjoint_roads.txt");

    Graph mediumGraph;
    mediumGraph.makeGraph("data/test_nodes.txt", "data/test_roads.txt");

    // Graph largeGraph;
    // largeGraph.makeGraph("data/nodes.txt", "data/roads.txt");

    // Dijkstras Tests
    // Dijkstra d(largeGraph, 128);
    // d.printOnePath(411);
    // Dijkstra d(largeGraph, 0);
    // d.printPaths();

    // Colorability Tests
    // Welsh welsh(mediumGraph);
    // vector<int> colors = welsh.getColors();
    // for (auto color : colors) {
    //     std::cout << color << ", ";
    // }
    // std::cout << "\n";
    // welsh.printMaxColors();
}

int main()
{
    tests();
    welcome();

    return 0;
}
