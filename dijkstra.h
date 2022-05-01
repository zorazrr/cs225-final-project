#pragma once

#include "graph.h"

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

private:
    Graph g_;
    int start_;
    vector<pair<double, int>> paths_;
};

class NodePair {
public:
    NodePair(int node, double length) {
        node_ = node;
        length_ = length;
    }

    int getNode() const {
        return node_;
    }

    double getLength() const {
        return length_;
    }

    bool operator<(const NodePair other) const {
        return (length_ > other.getLength());
    }

private:
    int node_;
    double length_;
};