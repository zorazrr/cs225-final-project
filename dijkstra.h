#pragma once

#include "graph.h"
#include "nodedistpair.cpp"

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Dijkstra {
public:
    Dijkstra(Graph g, int start);

    void executeDijkstra();

    vector<pair<double, int>> getPaths();

    void setUpPaths(unsigned size);

    void printConnections(vector<vector<Road*>>& connections);

    void printPaths();

    void printOnePath(int dest);

    vector<int> getPath(int dest);

    double convertDist(double dist);

private:
    Graph g_;
    int start_;
    vector<pair<double, int>> paths_;
};