#include "road.h"

Road::Road() {}

Road::Road(int id, int start, int end, double length): id_(id), start_(start), end_(end), length_(length) {

} 

int Road::getId() const { return id_; }

double Road::getLength() const { return length_; }

int Road::getStart() const { return start_; }

int Road::getEnd() const { return end_; }

void Road::setId(int id) {
    id_ = id;
}

void Road::setLength(double length) {
    length_ = length;
}

void Road::setStart(int start) {
    start_ = start;
}

void Road::setEnd(int end) {
    end_ = end;
}

bool Road::operator<=(const Road other) const {
    return (length_ <= other.getLength());
}

bool Road::operator==(const Road other) const {
    return (start_ == other.getStart() && end_ == other.getEnd());
}