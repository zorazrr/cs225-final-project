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

class Welsh {
public:
    Welsh(Graph g);
    void executeWelsh();

private:
    Graph g_;
    vector<int> colors_;
};

class NodeDegreePair {
public:
    NodeDegreePair(int node, int degree) {
        node_ = node;
        degree_ = degree;
    }

    int getNode() const {
        return node_;
    }

    double getDegree() const {
        return degree_;
    }

    bool operator<(const NodePair other) const {
        return (degree_ < other.getDegree());
    }

private:
    int node_;
    int degree_;
};