#pragma once

#include "node.h"
#include "road.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Graph
{
public:
    // Default constructor 
    Graph();

    // Constructor helpers 
    void makeGraph(string nodes_file, string roads_file);
    void createNodes(string nodes_file);
    vector<Road*> createRoads(string roads_file);
    
    void createConnections(vector<Road*> roads);

    // BFS Traversal given a starting node
    void BFS(int id);
    // Shortest Path 
    void shortestPath();
    
    // Getters
    vector<Road *> getRoad(int id);
    vector<Node *> getNodes() {return nodes_;}
    vector<vector<Road *>> getConnections() {return connections_;}

private:
    vector<Node *> nodes_;
    vector<vector<Road *> > connections_;
    int size_; // number of nodes
};