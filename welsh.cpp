#include "welsh.h"

/**
 * Sets up the Welsh-Powell algorithm by setting up degrees, colors,
 * and calling the Welsh-Powell method
 * @param g the graph to execute the algorithm on
 **/
Welsh::Welsh(Graph g)
{
    g_ = g;
    setUpDegrees();
    setUpColors();
    executeWelsh();
}

/**
 * Fills degrees with the degree of each node in descending order
 **/
void Welsh::setUpDegrees()
{
    vector<vector<Road *>> connections = g_.getConnections();
    for (size_t i = 0; i < connections.size(); i++)
    {
        int degree = connections[i].size();
        degrees_.push_back(NodeDegreePair(i, degree));
    }
    // sort in descending order
    std::sort(degrees_.begin(), degrees_.end());
}

/**
 * Fills colors with -1 for each node to represent that nodes are 
 * uncolored
 **/
void Welsh::setUpColors()
{
    for (int i = 0; i < g_.getNumNodes(); i++)
    {
        colors_.push_back(-1);
    }
}

/**
 * Executes the Welsh-Powell algorithm to obtain an upper bound for the
 * number of colors needed to color the graph
 **/
void Welsh::executeWelsh()
{
    vector<NodeDegreePair> nodesToColor = degrees_;
    int currColor = 0;
    for (size_t i = 0; i < nodesToColor.size(); i++) {
        int currNode = nodesToColor[i].getNode();
        if (colors_[currNode] != -1) continue;

        vector<int> coloredNodes;
        coloredNodes.push_back(currNode);
        colors_[currNode] = currColor;

        for (size_t j = i + 1; j < nodesToColor.size(); j++) {
            int newNode = nodesToColor[j].getNode();
            if (colors_[newNode] == -1 && !isAdjacent(newNode, coloredNodes)) {
                coloredNodes.push_back(newNode);
                colors_[newNode] = currColor;
            } 
        }
        currColor++;
    }
    maxColors_ = currColor;
}

/**
 * Prints the upper bound of colors needed to color the graph
 **/
void Welsh::printMaxColors() {
    std::cout << "The upper bound on the number of colors needed is " << maxColors_ << "." << std::endl;
}

/**
 * Determines if the node inputted is adjacent to any of the nodes in
 * coloredNodes. If it's not adjacent, it can be safely colored the 
 * same color
 * @param nodeToColor the node that can potentially be colored the 
 * current color
 * @param coloredNodes vector of nodes that have already been colored
 * the current color
 * @return true if nodeToColor is adjacent to 1+ nodes in coloredNodes
 * (and therefore cannot be given the same color), false if not
 **/
bool Welsh::isAdjacent(int nodeToColor, vector<int> coloredNodes)
{
    set<int> connected = g_.getConnected();

    for (int coloredNode : coloredNodes) {
        int a = nodeToColor < coloredNode? nodeToColor : coloredNode;
        int b = nodeToColor < coloredNode? coloredNode : nodeToColor;
        if (connected.count((a + b) * (a + b + 1) / 2 + a) == 1) {
            return true;
        }
    }
    return false;
}