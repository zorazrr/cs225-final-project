#include "graph.h"

Graph::Graph() {
   
}

void Graph::makeGraph(string nodes_file, string roads_file) {
    createNodes(nodes_file);
    vector<Road*> roads = createRoads(roads_file);
    createConnections(roads);
    size_ = (int)(nodes_.size());
}

void Graph::createNodes(string nodes_file) {
    ifstream ifs(nodes_file);

    if (ifs.is_open()) {
        int id;
        double longitude;
        double latitude;

        while (ifs >> id >> longitude >> latitude) {
            nodes_.push_back(new Node(id, longitude, latitude));
            connections_.push_back(vector<Road*>());
        }
        ifs.close();
    } else {
        cout << "Unable to open nodes file." << endl;
    }
}

vector<Road*> Graph::createRoads(string roads_file) {
    ifstream ifs(roads_file);
    vector<Road*> roads;

    if (ifs.is_open()) {
        int id;
        int start;
        int end;
        double length;

        while (ifs >> id >> start >> end >> length) {
            roads.push_back(new Road(id, start, end, length));
        }
        ifs.close();
    } else {
        cout << "Unable to open roads file." << endl;
    }

    return roads;
}

void Graph::createConnections(vector<Road*> roads) {
    for (unsigned i = 0; i < roads.size(); ++i) {
        Road* road = roads.at(i);
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
            if(!visited[*connected[x].getEnd()]) {
                visited[*connected[x].getEnd()] = true;
                q.push_back(*connected[x].getEnd());
            }
        }
    }
}