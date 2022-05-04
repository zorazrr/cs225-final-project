#pragma once

#include "node.h"
#include "road.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

class Graph
{
public:
    // Default constructor
    Graph();

    // Constructor helpers
    void makeGraph(string nodes_file, string roads_file);
    void createNodes(string nodes_file);
    void createRoads(string roads_file);

    void createConnections();

    // BFS Traversal given a starting node
    vector<int> BFS(int id);
    // Shortest Path
    void shortestPath();

    // Getters
    vector<Road *> getRoads() { return roads_; }
    vector<Road *> getRoad(int id);
    vector<Node *> getNodes() { return nodes_; }
    vector<vector<Road *>> getConnections() { return connections_; }
    set<int> getConnected() { return connected_; }
    int getNumNodes() { return nodes_.size(); }

private:
    vector<Road *> roads_;
    vector<Node *> nodes_;
    vector<vector<Road *> > connections_;
    set<int> connected_;
    int size_; // number of nodes
};