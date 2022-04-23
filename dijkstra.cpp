#include "dijkstra.h"

vector<pair<double, int>> dijkstra(Graph g, int start) {
    vector<vector<Road*>> connections = g.getConnections();
    
    // first: length of shortest path to start, second: predecessor
    vector<pair<double, int>> paths; 
    setUpPaths(paths, connections.size());
    paths.at(start).first = 0; // start is distance 0 from itself

    priority_queue<NodePair> toVisit;
    toVisit.push(NodePair(start, 0));

    while (!toVisit.empty()) {
        // visit the node with highest priority (shortest distance) in toVisit 
        NodePair pair = toVisit.top();
        toVisit.pop();
        int node = pair.getNode();
        double distance = pair.getLength();

        // iterate through nodes adjacent to node
        for (unsigned i = 0; i < connections.at(node).size(); ++i) {
            Road* road = connections.at(node).at(i);
            int adjacentNode = road->getEnd() == node? road->getStart() : road->getEnd();

            // if we haven't visited this node yet, push to queue
            if (paths.at(adjacentNode).second == -1) {
                toVisit.push(NodePair(adjacentNode, distance + road->getLength()));
            }

            // if the node's current path is shorter than its previous, update
            if (paths.at(adjacentNode).first > distance + road->getLength()) {
                paths.at(adjacentNode).first = distance + road->getLength();
                paths.at(adjacentNode).second = node;
            }
        }
    }
    return paths;
}


/**
* @param paths first: length of shortest path to start, second: predecessor
* @param size number of nodes
*/
void setUpPaths(vector<pair<double, int>>& paths, unsigned size) {
    for (unsigned i = 0; i < size; ++i) {
        paths.push_back(make_pair<double, int>(std::numeric_limits<double>::max(), -1));
    }
}

vector<int> getPath(vector<pair<double, int>>& paths, int start, int dest) {
    vector<int> path;
    int curr = dest;
    while (curr != start && paths.at(curr).second >= 0) {
        path.push_back(curr);
        curr = paths.at(curr).second;
    }
    path.push_back(start);
    return path;
}

void printPath(vector<pair<double, int>>& paths, int start) {
    for (unsigned i = 0; i < paths.size(); ++i) {
        vector<int> path = getPath(paths, start, i);
        std::cout << i << ": ";
        for (unsigned j = 0; j < path.size(); ++j) {
            std::cout << path.at(j) << " ";
        }
        std::cout << " " << std::endl;
        std::cout << "------" << std::endl;
       
    }
}

/**
* @param connections vector of vectors, where each vector contains the roads connected to the corresponding node
*/
void printConnections(vector<vector<Road*>>& connections) {
    for (unsigned i = 0; i < connections.size(); ++i) {
        std::cout << "node id: " << i << std::endl;
        for (unsigned j = 0; j < connections.at(i).size(); ++j) {
            std::cout << connections.at(i).at(j)->getStart() << " " << connections.at(i).at(j)->getEnd() << " | ";
        }
        std::cout << " " << std::endl;
    }
}