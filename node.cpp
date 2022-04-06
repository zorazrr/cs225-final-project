#include "node.h"

Node::Node() {
    id_ = 0;
    latitude_ = 0.0;
    longitude_ = 0.0;
}

Node::Node(int id, double latitude, double longitude) {
    id_ = id;
    latitude_ = latitude;
    longitude_ = longitude;
}

int Node::getId() {
    return id_;
}

double Node::getLatitude() {
    return latitude_;
}

double Node::getLongitude() {
    return longitude_;
}

void Node::setId(int id) {
    id_ = id;
}

void Node::setLatitude(double latitude) {
    latitude_ = latitude;
}

void Node::setLongitude(double longitude) {
    longitude_ = longitude;
}

std::ostream &operator<<(std::ostream &out, const Node &n) {
    out << id << ": (" << latitude_ << ", " << longitude_ << ")";
    return out;
}