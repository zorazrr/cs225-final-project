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
    Road(int id, int start, int end, double length);
    // Getters
    int getId() const;
    double getLength() const;
    int getStart() const;
    int getEnd() const;
    // Setters
    void setId(int id);
    void setLength(double length);
    void setStart(int start);
    void setEnd(int end);

    // Overload operators
    bool operator<=(const Road other) const;
    bool operator<(const Road other) const;
    bool operator>=(const Road other) const;
    bool operator>(const Road other) const;
    bool operator==(const Road other) const;
    bool operator!=(const Road other) const;

private:
    int id_;
    int start_;
    int end_;
    double length_;
};