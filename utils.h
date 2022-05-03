#pragma once

#include "dijkstra.h"
#include "welsh.h"
#include "kdtree.h"
#include <iostream>

void welcome();
void select(Graph& graph);
void gps(Graph& graph);
void tour(Graph& graph);
void nearestAttractions(Graph& graph);
KDTree<2> getTree(Graph& graph);