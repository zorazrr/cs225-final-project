#pragma once

#include "graph.h"
#include "nodedegreepair.cpp"

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Welsh
{
public:
    Welsh(Graph g);
    void setUpColors();
    void setUpDegrees();
    void executeWelsh();
    bool isAdjacent(int nodeToColor, vector<int> coloredNodes);
    void printMaxColors();

    // Getters
    vector<int> getColors() { return colors_; }
    vector<NodeDegreePair> getDegrees() { return degrees_; }
    int getMaxColors() { return maxColors_; }

private:
    Graph g_;
    vector<int> colors_;
    vector<NodeDegreePair> degrees_;
    int maxColors_;
};
