class NodeDistPair {
public:
    NodeDistPair(int node, double length) {
        node_ = node;
        length_ = length;
    }

    int getNode() const {
        return node_;
    }

    double getLength() const {
        return length_;
    }

    bool operator<(const NodeDistPair other) const {
        return (length_ > other.getLength());
    }

private:
    int node_;
    double length_;
};