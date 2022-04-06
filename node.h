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
    Node(int id, double longitude, double latitude);
    // Getters
    int getId();
    double getLongitude();
    double getLatitude();
    // Setters
    void setId();
    void setLongitude();
    void setLatitude();

private:
    int id_;
    double longitude_;
    double latitude_;
};

// Overload operators
std::ostream &operator<<(std::ostream &out, const Node &n);
