#pragma once

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    // Default Constructor
    Node();
    // Constructor
    Node(int id, double latitude, double longitude);
    // Getters
    int getId() const;
    double getLatitude() const;
    double getLongitude() const;
    // Setters
    void setId(int id);
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    // Calculate distance between two nodes
    double toRadians(const double degree);
    double calcDistance(Node& other);

    bool operator==(const Node other) const;

private:
    int id_;
    double latitude_;
    double longitude_;
};

// Overload operators
std::ostream &operator<<(std::ostream &out, const Node &n);
