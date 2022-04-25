#include "../cs225/catch/catch.hpp"

#include "../dijkstra.h"

#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <numeric>
#include <vector>

void printResult(vector<pair<double, int>>& paths)
    for (unsigned i = 0; i < paths.size(); ++i) {
        std::cout << paths.at(i).first << " " << paths.at(i).second << std::endl;
    }
}

/**
test cases:
small_test_nodes
medium_test_nodes
situation where paths are the same
disconnected

print method that displays the shortest path
after visiting everything, if any node's distance is max value, replace w/-1