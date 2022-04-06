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
    int getId();
    double getLatitude();
    double getLongitude();
    // Setters
    void setId(int id);
    void setLatitude(double latitude);
    void setLongitude(double longitude);

private:
    int id_;
    double latitude_;
    double longitude_;
};

// Overload operators
std::ostream &operator<<(std::ostream &out, const Node &n);
