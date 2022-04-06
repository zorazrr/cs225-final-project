#pragma once

#include <iostream>
#include <string>

using namespace std;

class Road
{
public:
    // Default Constructor
    Road();
    // Constructor
    Road(int id, int start, int end, int length);
    // Getters
    int getId();
    double getLength();
    int getStart();
    int getEnd();
    // Setters
    void setId();
    void setLength();
    void setStart();
    void setEnd();

    // Overload operators
    bool operator<(Road const &other) const;

private:
    int id_;
    double length_;
    int start_;
    int end_;
};