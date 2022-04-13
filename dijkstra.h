#pragma once

#include "graph.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<pair<double, int>> dijkstra(Graph g, int start);

void setUpPaths(vector<pair<double, int>>& paths, unsigned size);
