#pragma once

#include "graph.h"

#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<pair<double, int>> dijkstra(Graph g, int start);

void setUpPaths(vector<pair<double, int>>& paths, unsigned size);

void printConnections(vector<vector<Road*>>& connections);

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