#include "welsh.h"

Welsh::Welsh(Graph g)
{
    g_ = g;
    setUpDegrees();
    setUpColors();
    executeWelsh();
}

/**
 * Fill in degrees with degree of each node
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
 * Fill in default colors
 * -1 represents uncolored nodes
 **/
void Welsh::setUpColors()
{
    for (int i = 0; i < g_.getNumNodes(); i++)
    {
        colors_.push_back(-1);
    }
}

void Welsh::executeWelsh()
{
    vector<NodeDegreePair> nodesToColor = degrees_;
    int currColor = 0;
    while (!nodesToColor.empty())
    {
        vector<int> coloredNodes; // vector containing nodes corresponding to this color
        for (size_t i = 0; i < nodesToColor.size(); i++)
        {
            int currNode = nodesToColor[i].getNode();
            if (!isAdjacent(currNode, coloredNodes))
            {
                coloredNodes.push_back(currNode);
                colors_[currNode] = currColor;
            }
        }
        for (int node : coloredNodes) {
            for (size_t j = 0; j < nodesToColor.size(); j++) {
                if (nodesToColor[j].getNode() == node) {
                    nodesToColor.erase(nodesToColor.begin() + j);
                    break;
                }
            }
        }
        currColor++;
    }
    maxColors_ = currColor;
}

void Welsh::printMaxColors() {
    std::cout << "The upper bound on the number of colors needed is " << maxColors_ << "." << std::endl;
}

bool Welsh::isAdjacent(int nodeToColor, vector<int> coloredNodes)
{
    vector<vector<Road *>> connections = g_.getConnections();
    vector<Road *> roads = connections[nodeToColor];
    for (auto road : roads)
    {
        for (int coloredNode : coloredNodes)
        {
            if (road->getEnd() == coloredNode || road->getStart() == coloredNode)
                return true;
        }
    }
    return false;
}