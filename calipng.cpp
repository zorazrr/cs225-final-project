#include "calipng.h"
#include "dijkstra.h"

/**
 * Creates an image of California outlined on a blank png
 * Stores in "california.png"
 * @param g the adjacency list that contains nodes in california map
 * @return cali stored as a PNG
 **/
PNG createCali(Graph g)
{
    PNG cali;
    cali.readFromFile("data/graphs/background.png");
    // Set up nodes in image
    vector<Node *> nodes = g.getNodes();
    for (Node *n : nodes)
    {
        auto posPair = castPosition(n->getLatitude(), n->getLongitude());
        HSLAPixel &p = cali.getPixel(posPair.first, posPair.second);
        p.h = 0;
        p.l = 0;
        p.s = 0;
    }
    cali.writeToFile("california.png");
    return cali;
}

/**
 * Draws the shortest path on the image
 * @param cali the png image that we are modifying
 * @param g the adjacency list that contains nodes in california map
 * @param dijk dijk should contain the shortest paths from a starting point to all other nodes
 * @param dest the destination node number
 **/
void drawShortestPath(PNG &cali, Graph g, Dijkstra dijk, int dest)
{
    vector<Node *> nodes = g.getNodes();
    vector<int> path = dijk.getPath(dest);
    for (int nodeIdx : path)
    {
        double posX = nodes[nodeIdx]->getLatitude();
        double posY = nodes[nodeIdx]->getLongitude();
        auto posPair = castPosition(posX, posY);
        for (int i = posPair.first - 5; i < posPair.first + 5; i++)
        {
            for (int j = posPair.second - 5; j < posPair.second; j++)
            {
                HSLAPixel &p = cali.getPixel(i, j);
                p.h = 0;
                p.s = 100;
                p.l = 50;
                p.a = 1;
            }
        }
    }
    cali.writeToFile("californiaShortestPath.png");
}

/**
 * CreateCali helper function
 * Casts a latitude-longitude point to a pixel on a blank image of
 * @param x the latitude of the node
 * @param y the longitude of the node
 **/
std::pair<int, int> castPosition(double x, double y)
{
    // X (latitude) ranges from -114.294 to -124.389 (10.095)
    // Y (longitude) ranges from 32.5413 to 42.0172 (9.4759)
    int newX = (124.389 + x) * 1000 / 10.095 + 50;
    int newY = (42.0172 - y) * 1000 / 10.095 + 50;
    return std::make_pair(newX, newY);
}
