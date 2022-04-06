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

double Node::toRadians(const double degree) {
    return (M_PI / 180) * degree;
}

double Node::calcDistance(Node& other) {
    double lat1 = toRadians(latitude_);
    double long1 = toRadians(longitude_);
    double lat2 = toRadians(other.latitude_);
    double long2 = toRadians(other.longitude_);

    double dlong = long2 - long1;
    double dlat = lat2 - lat1;
    double ans = pow(sin(dlat / 2), 2) +
                    cos(lat1) * cos(lat2) *
                    pow(sin(dlong / 2), 2);
    ans = 2 * asin(sqrt(ans));

    double R = 6371; // radius of Earth in kilometers
    return ans*R;
}

std::ostream &operator<<(std::ostream &out, const Node &n) {
    out << id << ": (" << latitude_ << ", " << longitude_ << ")";
    return out;
}