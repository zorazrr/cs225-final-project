#include "graph.h"

Graph::Graph() {
   
}

void Graph::makeGraph(string nodes_file, string roads_file) {
    createNodes(nodes_file);
    createRoads(roads_file);
    createConnections();
    size_ = (int)(nodes_.size());
}

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

void Graph::createConnections() {
    for (unsigned i = 0; i < roads_.size(); ++i) {
        Road* road = roads_.at(i);
        int startId = road->getStart();
        int endId = road->getEnd();

        connections_.at(startId).push_back(road);
        connections_.at(endId).push_back(road);
    }
}

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