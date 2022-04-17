#include "dijkstra.h"

// figure out what to do if not all connected
vector<pair<double, int>> dijkstra(Graph g, int start) {
    vector<vector<Road*>> connections = g.getConnections();
    
    vector<pair<double, int>> paths; 
    setUpPaths(paths, connections.size());
    paths.at(start).first = 0;

    priority_queue<int> toVisit;
    toVisit.push(start);

    while (!toVisit.empty()) {
        int node = toVisit.pop_back();
        double distance = paths.at(node).first;
        std::cout << node << std::endl;
        int closestNode = -1;

        for (unsigned i = 0; i < connections.at(node).size(); ++i) {
            Road* road = connections.at(node).at(i);
            int adjacentNode = road->getEnd();

            if (paths.at(adjacentNode).second == -1) {
                toVisit.push(adjacentNode);
            }

            if (paths.at(adjacentNode).first > distance + road->getLength()) {
                paths.at(adjacentNode).first = distance + road->getLength();
                paths.at(adjacentNode).second = node;
            }
            if (closestNode == -1) closestNode = adjacentNode;
            else if (paths.at(adjacentNode).first < paths.at(closestNode).first) closestNode = adjacentNode;
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