#include "dijkstra.h"

Dijkstra::Dijkstra(Graph g, int start): g_(g), start_(start) {
    // populate empty paths_
    setUpPaths(g_.getConnections().size());
    // execute dijkstra to get paths_ to contain the actual paths_
    executeDijkstra();
}

void Dijkstra::executeDijkstra() {
    vector<vector<Road*>> connections = g_.getConnections();
    
    // first: length of shortest path to start, second: predecessor
    paths_.at(start_).first = 0; // start is distance 0 from itself

    priority_queue<NodePair> toVisit;
    toVisit.push(NodePair(start_, 0));

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
            if (paths_.at(adjacentNode).second == -1) {
                toVisit.push(NodePair(adjacentNode, distance + road->getLength()));
            }

            // if the node's current path is shorter than its previous, update
            if (paths_.at(adjacentNode).first > distance + road->getLength()) {
                paths_.at(adjacentNode).first = distance + road->getLength();
                paths_.at(adjacentNode).second = node;
            }
        }
    }
}


/**
* @param paths_ first: length of shortest path to start, second: predecessor
* @param size number of nodes
*/
void Dijkstra::setUpPaths(unsigned size) {
    for (unsigned i = 0; i < size; ++i) {
        paths_.push_back(make_pair<double, int>(std::numeric_limits<double>::max(), -1));
    }
}

vector<int> Dijkstra::getPath(int dest) {
    vector<int> path;
    int curr = dest;
    while (curr != start_ && paths_.at(curr).second >= 0) {
        path.push_back(curr);
        curr = paths_.at(curr).second;
    }
    path.push_back(start_);
    std::reverse(path.begin(), path.end());
    return path;
}

void Dijkstra::printPaths() {
    for (unsigned i = 0; i < paths_.size(); ++i) {
        // returns the path from start to node i
        vector<int> path = getPath(i);
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
void Dijkstra::printConnections(vector<vector<Road*>>& connections) {
    for (unsigned i = 0; i < connections.size(); ++i) {
        std::cout << "node id: " << i << std::endl;
        for (unsigned j = 0; j < connections.at(i).size(); ++j) {
            std::cout << connections.at(i).at(j)->getStart() << " " << connections.at(i).at(j)->getEnd() << " | ";
        }
        std::cout << " " << std::endl;
    }
}