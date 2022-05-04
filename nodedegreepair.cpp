#include "graph.h"
#include "dijkstra.h"

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

/**
* A class that stores a node and its degree. Used in the Welsh-
* Powell algorithm to sort the nodes in decreasing order by degree
**/
class NodeDegreePair
{
public:
    NodeDegreePair(int node, int degree)
    {
        node_ = node;
        degree_ = degree;
    }

    int getNode() const
    {
        return node_;
    }

    double getDegree() const
    {
        return degree_;
    }

    bool operator<(const NodeDegreePair other) const
    {
        return (degree_ > other.getDegree());
    }

private:
    int node_;
    int degree_;
};