#include "../cs225/catch/catch.hpp"

#include "../graph.h"
#include "../dijkstra.h"
#include "../welsh.h"
#include "../kdtree.h"
#include "../point.h"

#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <numeric>
#include <vector>

#include <iostream>
#include <cctype>
#include <locale>

TEST_CASE("KDTree::testSmallerDimVal Tests", "[weight=1][kdtree]") {
    vector<Point<3>> pts;
    KDTree<3> tree(pts);
    Point<3> a(1, 2, 4);
    Point<3> b(3, 2, 2);

    REQUIRE(tree.smallerDimVal(a, b, 0) == true);
    REQUIRE(tree.smallerDimVal(a, b, 2) == false);
    REQUIRE(tree.smallerDimVal(a, b, 1) == true);
}

TEST_CASE("KDTree::shouldReplace Tests", "[weight=1][kdtree]") {
    vector<Point<3>> pts;
    KDTree<3> tree(pts);

    Point<3> target(1, 3, 5);
    Point<3> currentBest1(1, 3, 2);
    Point<3> possibleBest1(2, 4, 4);
    Point<3> currentBest2(1, 3, 6);
    Point<3> possibleBest2(2, 4, 4);
    Point<3> currentBest3(0, 2, 4);
    Point<3> possibleBest3(2, 4, 6);

    REQUIRE(tree.shouldReplace(target, currentBest1, possibleBest1) == true);
    REQUIRE(tree.shouldReplace(target, currentBest2, possibleBest2) == false);
    REQUIRE(tree.shouldReplace(target, currentBest3, possibleBest3) == false);
}

TEST_CASE("KDTree::findNearestNeighbor (2D), returns correct result", "[weight=1][part=1]") {
  double coords[6][2] = {
    {-15, 7}, {6, 7}, {-13, -1},
    {-5, 0}, {14, -3}, {14, 2}
  };
  double targetCoords[2] = {-13, 1};
  double expectedCoords[2] = {-13, -1};

  vector<Point<2>> points;
  for (int i = 0; i < 6; ++i)
      points.push_back(Point<2>(coords[i]));
  Point<2> target(targetCoords);
  Point<2> expected(expectedCoords);

  KDTree<2> tree(points);
  int size = 2;
  int K = 2;
  std::string fname = "test_result_kdtree_"+to_string(K)+"_"+to_string(size)+".kd";

  REQUIRE( tree.findNearestNeighbor(target) == expected );
}

TEST_CASE("KDTree::findNearestNeighbor (3D), testing that left recursion does not include the root", "[weight=1][kdtree]") {
  double coords[10][3] = {
    {5, 3, 1}, {3, 1, 10}, {2, 0, 8}, {4, 3, 0}, {0, 2, 9},
    {10, 10, 10}, {11, 11, 11}, {12, 12, 12}, {13, 13, 13}, {14, 14, 14}
  };
  double targetCoords[3] = {1, 1, 9};
  double expectedCoords[3] = {0, 2, 9};

  vector<Point<3>> points;
  for (int i = 0; i < 10; ++i)
      points.push_back(Point<3>(coords[i]));
  Point<3> target(targetCoords);
  Point<3> expected(expectedCoords);

  KDTree<3> tree(points);
  int size = 10;
  int K = 3;
  std::string fname = "test_result_kdtree_"+to_string(K)+"_"+to_string(size)+".kd";

  REQUIRE( tree.findNearestNeighbor(target) == expected );
}


vector<Road *> getSmallRoads()
{
    string roads_file = "./data/small_test_roads.txt";

    vector<Road *> roads;
    Road *road1 = new Road(0, 0, 1, 0.002025);
    Road *road2 = new Road(1, 3, 1, 0.005952);
    Road *road3 = new Road(2, 1, 2, 0.014350);
    Road *road4 = new Road(3, 2, 3, 0.012279);
    Road *road5 = new Road(4, 3, 4, 0.011099);

    roads.push_back(road1);
    roads.push_back(road2);
    roads.push_back(road3);
    roads.push_back(road4);
    roads.push_back(road5);

    return roads;
}

vector<Node *> getSmallNodes()
{
    string nodes_file = "./data/small_test_nodes.txt";

    vector<Node *> nodes;
    Node *node1 = new Node(0, -121.904167, 41.974556);
    Node *node2 = new Node(1, -121.902153, 41.974766);
    Node *node3 = new Node(2, -121.896790, 41.988075);
    Node *node4 = new Node(3, -115.257767, 33.832241);
    Node *node5 = new Node(4, -122.404907, 39.053646);

    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    nodes.push_back(node5);

    return nodes;
}

vector<vector<Road *>> getSmallConnections()
{
    vector<vector<Road *>> connections(5);
    vector<Road *> roads = getSmallRoads();

    for (unsigned i = 0; i < roads.size(); ++i)
    {
        Road *road = roads.at(i);
        int startId = road->getStart();
        int endId = road->getEnd();

        connections.at(startId).push_back(road);
        connections.at(endId).push_back(road);
    }
    return connections;
}

TEST_CASE("test_create_roads", "[weight=5][graph]")
{
    vector<Road *> expectedRoads = getSmallRoads();

    Graph g;
    vector<Road *> roads = g.createRoads("./data/small_test_roads.txt");

    REQUIRE(expectedRoads.size() == roads.size());

    for (unsigned i = 0; i < expectedRoads.size(); ++i)
    {
        REQUIRE(expectedRoads.at(i)->getStart() == roads.at(i)->getStart());
        REQUIRE(expectedRoads.at(i)->getEnd() == roads.at(i)->getEnd());
    }
}

TEST_CASE("test_create_nodes", "[weight=5][graph]")
{
    vector<Node *> expectedNodes = getSmallNodes();

    Graph g;
    g.createNodes("./data/small_test_nodes.txt");
    vector<Node *> nodes = g.getNodes();

    REQUIRE(expectedNodes.size() == nodes.size());
    REQUIRE(g.getConnections().size() == nodes.size());

    for (unsigned i = 0; i < expectedNodes.size(); ++i)
    {
        REQUIRE(expectedNodes.at(i)->getLatitude() == nodes.at(i)->getLatitude());
        REQUIRE(expectedNodes.at(i)->getLongitude() == nodes.at(i)->getLongitude());
    }
}

TEST_CASE("test_create_connections", "[weight=5][graph]")
{
    vector<vector<Road *>> expectedConnections = getSmallConnections();

    Graph g;
    g.makeGraph("./data/small_test_nodes.txt", "./data/small_test_roads.txt");
    vector<vector<Road *>> connections = g.getConnections();

    REQUIRE(expectedConnections.size() == connections.size());

    for (unsigned i = 0; i < expectedConnections.size(); ++i)
    {
        REQUIRE(expectedConnections.at(i).size() == connections.at(i).size());
    }
}

// Dijkstra Tests

TEST_CASE("test_dijkstra_non_connected_1", "[weight=5][dijkstra]")
{
    Graph g;
    g.makeGraph("data/test_disjoint_nodes.txt", "data/test_disjoint_roads.txt");
    vector<int> dijkstraPath = Dijkstra(g, 8).getPath(6);
    vector<int> expectedPath = {8, 7};
    for (size_t i = 0; i < expectedPath.size(); i++)
    {
        REQUIRE(dijkstraPath[i] == expectedPath[i]);
    }
}

TEST_CASE("test_dijkstra_non_connected_2", "[weight=5][dijkstra]")
{
    Graph g;
    g.makeGraph("data/test_disjoint_nodes.txt", "data/test_disjoint_roads.txt");
    vector<int> dijkstraPath = Dijkstra(g, 3).getPath(6);
    vector<int> expectedPath = {3};
    for (size_t i = 0; i < expectedPath.size(); i++)
    {
        REQUIRE(dijkstraPath[i] == expectedPath[i]);
    }
}

TEST_CASE("test_dijkstra_non_connected_3", "[weight=5][dijkstra]")
{
    Graph g;
    g.makeGraph("data/test_disjoint_nodes.txt", "data/test_disjoint_roads.txt");
    vector<int> dijkstraPath = Dijkstra(g, 3).getPath(1);
    vector<int> expectedPath = {3, 2, 4, 1};
    for (size_t i = 0; i < expectedPath.size(); i++)
    {
        REQUIRE(dijkstraPath[i] == expectedPath[i]);
    }
}

// Welsh-Powell Tests
TEST_CASE("welsh_powell_small", "[weight=5][welsh]")
{
    Graph g;
    g.makeGraph("data/test_nodes.txt", "data/test_roads.txt");
    Welsh welsh(g);

    vector<int> welshColors = welsh.getColors();
    vector<int> expectedColors = {2, 1, 2, 0, 1, 2, 0, 1, 0, 0, 2, 1, 2, 0, 1, 2, 0, 2, 0, 1, 2, 0, 1, 0, 1, 2, 1, 2, 0, 2};

    REQUIRE(welshColors.size() == expectedColors.size());
    for (size_t i = 0; i < expectedColors.size(); i++)
    {
        REQUIRE(welshColors[i] == expectedColors[i]);
    }
}

TEST_CASE("welsh_powell_disjoint", "[weight=5][welsh]")
{
    Graph g;
    g.makeGraph("data/test_disjoint_nodes.txt", "data/test_disjoint_roads.txt");
    Welsh welsh(g);

    vector<int> welshColors = welsh.getColors();
    vector<int> expectedColors = {1, 1, 2, 0, 0, 2, 1, 0, 1};

    REQUIRE(welshColors.size() == expectedColors.size());
    for (size_t i = 0; i < expectedColors.size(); i++)
    {
        REQUIRE(welshColors[i] == expectedColors[i]);
    }
}
