#pragma once

#include "graph.h"
#include "dijkstra.h"
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"

using namespace std;
using namespace cs225;

PNG createCali(Graph g);
std::pair<int, int> castPosition(double x, double y);

void drawShortestPath(Graph g, Dijkstra dijk, int dest);