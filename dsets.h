/* Your code here! */
#pragma once
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class DisjointSets {
  private:
    std::vector<int> arr;

  public:
    void addelements(int num);

    int find(int elem);

    void setunion(int a, int b);

    int size(int elem);

    vector<int> getArr() {return arr;}
};