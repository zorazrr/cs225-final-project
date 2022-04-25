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
    vector<int> nodesToRemove;
    int currColor = 0;
    int totalNumNodes = nodesToColor.size();
    while (nodesToRemove.size() < totalNumNodes)
    {
        vector<int> nodesToRemove;
        vector<int> coloredNodes;
        for (size_t i = 0; i < nodesToColor.size(); i++)
        {
            int currNode = nodesToColor[i].getNode();
            if (colors_[currNode] != 1 && !isAdjacent(currNode, coloredNodes))
            {
                coloredNodes.push_back(currNode);
                colors_[currNode] = currColor;
                nodesToRemove.push_back(i);
            }
        }
        for (int idx : nodesToRemove) {
            nodesToColor.erase(nodesToColor.begin() + idx);
        }
        currColor++;
    }
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