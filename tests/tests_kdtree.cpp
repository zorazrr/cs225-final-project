#include "../cs225/catch/catch.hpp"

#include "../kdtree.h"
#include "../point.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
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
  writeKdTreeToFile(tree,fname);
  compareBinaryFiles(fname, "tests/expected_kdtree_"+to_string(K)+"_"+to_string(size)+".kd" );

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
  writeKdTreeToFile(tree,fname);
  compareBinaryFiles(fname, "tests/expected_kdtree_"+to_string(K)+"_"+to_string(size)+".kd" );

  REQUIRE( tree.findNearestNeighbor(target) == expected );
}
