#include "graph.h"

Graph::Graph() {}

/**
* Calls the functions for populating nodes_, roads_, connected_, and
* connections_, and initializes the size
* @param nodes_file the file containing information about the nodes
* @param roads_file the file containing information about the roads
**/
void Graph::makeGraph(string nodes_file, string roads_file) {
    createNodes(nodes_file);
    createRoads(roads_file);
    createConnections();
    size_ = (int)(nodes_.size());
}

/**
* Reads from nodes_file to populate nodes_, a vector containing
* all of the Road objects corresponding to the dataset. Also
* populates connections_ with default values to avoid segmentation
* faults in createConnections()
* @param nodes_file the file containing information about the nodes
**/
void Graph::createNodes(string nodes_file) {
    ifstream ifs(nodes_file);

    if (ifs.is_open()) {
        int id;
        double longitude;
        double latitude;

        while (ifs >> id >> longitude >> latitude) {
            nodes_.push_back(new Node(id, latitude, longitude));
            connections_.push_back(vector<Road*>());
        }
        ifs.close();
    } else {
        cout << "Unable to open nodes file." << endl;
    }
}

/**
* Reads from roads_file to populate roads_, a vector containing
* all of the Road objects corresponding to the dataset. Also populates
* connected_, a set used in the Welsh-Powell algorithm to determine
* if a connection between two nodes exists. The cantor pairing function
* is used to ensure that mapping the connection between two nodes to a 
* single integer is unique and deterministic
* @param roads_file the file containing information about the roads
**/
void Graph::createRoads(string roads_file) {
    ifstream ifs(roads_file);

    if (ifs.is_open()) {
        int id;
        int start;
        int end;
        double length;

        while (ifs >> id >> start >> end >> length) {
            roads_.push_back(new Road(id, start, end, length));
            int a = start < end? start : end;
            int b = start < end? end : start;
            // cantor pairing function: unique & deterministic
            connected_.insert((a + b) * (a + b + 1) / 2 + a);
        }
        ifs.close();
    } else {
        cout << "Unable to open roads file." << endl;
    }
}

/**
* Populates connections_, the adjacency list representation of our graph, 
* once roads_ has been created. Each index of connections_ corresponds to a node,
* and the vector at that index contains the roads connected to that node.
**/
void Graph::createConnections() {
    for (unsigned i = 0; i < roads_.size(); ++i) {
        Road* road = roads_.at(i);
        int startId = road->getStart();
        int endId = road->getEnd();

        connections_.at(startId).push_back(road);
        connections_.at(endId).push_back(road);
    }
}

/**
* Executes bfs on the graph and prints the traversal
* @param id the id of the starting node
**/
void Graph::BFS(int id) {
    bool *visited = new bool[size_];
    for(int i = 0; i < size_; i++) {
        visited[i] = false;
    }
    std::list<int> q;
    visited[id] = true; // mark starting node as visited
    q.push_back(id);

    while(!q.empty()) {
        int temp = q.front();
        std::cout << temp << " ";
        q.pop_front();
        std::vector<Road*> connected = connections_.at(temp);
        for(int x = 0; x < (int)(connected.size()); x++) {
            if(!visited[connected[x]->getEnd()]) {
                visited[connected[x]->getEnd()] = true;
                q.push_back(connected[x]->getEnd());
            }
        }
    }
}