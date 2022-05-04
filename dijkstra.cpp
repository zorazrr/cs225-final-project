#include "dijkstra.h"

/**
* Given a starting Graph g and start node, sets up the paths_
* variable and calls Dijkstra's
* @param g the graph dijkstra's is implemented on
* @param start the starting node
**/
Dijkstra::Dijkstra(Graph g, int start): g_(g), start_(start) {
    // populate empty paths_
    setUpPaths(g_.getConnections().size());
    // execute dijkstra to get paths_ to contain the actual paths_
    executeDijkstra();
}

/**
* Executes Dijkstra's to populate paths_, a vector of vector of Roads
* containing the shortest path from the start node to every other node
**/
void Dijkstra::executeDijkstra() {
    vector<vector<Road*>> connections = g_.getConnections();
    
    // first: length of shortest path to start, second: predecessor
    paths_.at(start_).first = 0; // start is distance 0 from itself

    priority_queue<NodeDistPair> toVisit;
    toVisit.push(NodeDistPair(start_, 0));

    while (!toVisit.empty()) {
        // visit the node with highest priority (shortest distance) in toVisit 
        NodeDistPair pair = toVisit.top();
        toVisit.pop();
        int node = pair.getNode();
        double distance = pair.getLength();

        // iterate through nodes adjacent to node
        for (unsigned i = 0; i < connections.at(node).size(); ++i) {
            Road* road = connections.at(node).at(i);
            int adjacentNode = road->getEnd() == node? road->getStart() : road->getEnd();

            // if we haven't visited this node yet, push to queue
            if (paths_.at(adjacentNode).second == -1) {
                toVisit.push(NodeDistPair(adjacentNode, distance + road->getLength()));
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
* Populates paths_ with default values
* @param paths_ first: length of shortest path to start, second: predecessor
* @param size number of nodes
**/
void Dijkstra::setUpPaths(unsigned size) {
    for (unsigned i = 0; i < size; ++i) {
        paths_.push_back(make_pair<double, int>(std::numeric_limits<double>::max(), -1));
    }
}

/**
* Works backward from paths_ to retrieve the path taken from start to destination
* @param dest the destination node
* @return path the path taken from start to dest
**/
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

/**
* Once paths_ has been populated, the function prints the shortest path from
* the starting node to every other node
**/
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
* prints out the shortest path from a specific starting node to an end node
* @param dest the destination node 
*/
void Dijkstra::printOnePath(int dest) {
    vector<int> path = getPath(dest);
    std::cout << "The shortest path from " << start_ << " to " << dest << " is: ";
    for (unsigned j = 0; j < path.size(); ++j) {
        std::cout << path.at(j) << " ";
    }
    std::cout << "\n";
    std::cout << "The distance of the shortest path is: " << convertDist(paths_.at(dest).first) << "km." << std::endl;
}

/**
* Helper function that prints out the start and ending nodes of every road coming out of each node
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
/**
* Convert the distance scale of the dataset to km 
* @param dist the distance between two nodes (in the scale of the dataset)
* @return the input distance in km
**/
double Dijkstra::convertDist(double dist) {
    return dist * 100;
}