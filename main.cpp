#include "dijkstra.h"
#include "welsh.h"
<<<<<<< HEAD
#include "utils.h"
=======
#include "calipng.h"
>>>>>>> main
#include <iostream>

using namespace std;

<<<<<<< HEAD
void tests() {
=======
int main()
{
>>>>>>> main
    // Graph smallGraph;
    // smallGraph.makeGraph("data/test_disjoint_nodes.txt", "data/test_disjoint_roads.txt");

    // Graph mediumGraph;
    // mediumGraph.makeGraph("data/test_nodes.txt", "data/test_roads.txt");

    // Graph largeGraph;
    // largeGraph.makeGraph("data/nodes.txt", "data/roads.txt");

    // Dijkstras Tests
    Dijkstra d(largeGraph, 128);
    d.printOnePath(411);
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
    Graph graph;
    graph.makeGraph("data/nodes.txt", "data/roads.txt");
    welcome(graph);

    return 0;
}
