#include "../cs225/catch/catch.hpp"

#include "../graph.h"

#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <numeric>
#include <vector>

vector<Road*> getSmallRoads() {
    string roads_file = "./data/small_test_roads.txt";

    vector<Road*> roads;
    Road* road1 = new Road(0, 0, 1, 0.002025);
    Road* road2 = new Road(1, 3, 1, 0.005952);
    Road* road3 = new Road(2, 1, 2, 0.014350);
    Road* road4 = new Road(3, 2, 3, 0.012279);
    Road* road5 = new Road(4, 3, 4, 0.011099);

    roads.push_back(road1);
    roads.push_back(road2);
    roads.push_back(road3);
    roads.push_back(road4);
    roads.push_back(road5);

    return roads;
}

TEST_CASE("test_create_roads", "[weight=5][graph]") {
    vector<Road*> expectedRoads = getSmallRoads();

    Graph g;
    vector<Road*> roads = g.createRoads("./data/small_test_roads.txt");

    REQUIRE(expectedRoads.size() == roads.size());

    for (unsigned i = 0; i < expectedRoads.size(); ++i) {
        REQUIRE(expectedRoads.at(i) == roads.at(i));
    }
}

TEST_CASE("test_create_nodes", "[weight=5][graph]") {

}

TEST_CASE("test_create_connections", "[weight=5][graph]") {

}