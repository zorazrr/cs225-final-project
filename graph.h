#pragma once

#include "node.h"
#include "road.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph
{
public:
    // Default constructor 
    Graph();
    // Constructor helpers 
    void createConnections(vector<Road*> roads);

    // Traversal 
    void DFS();
    // Shortest Path 
    void shortestPath();
    
    // Getters
    vector<Road *> getRoad(int id);

private:
    vector<Node *> nodes_;
    vector<vector<Road *> > connections_;
};