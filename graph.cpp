#include "graph.h"

Graph::Graph() {
    createNodes();
    vector<Road*> roads = createRoads();
    createConnections(roads);
}

void Graph::createNodes() {
    ifstream ifs{"./data/nodes.txt"};

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

vector<Road*> Graph::createRoads() {
    ifstream ifs("./data/roads.txt");
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