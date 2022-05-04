#pragma once

#include <vector>
// #include "util/coloredout.h"
#include "point.h"

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;

template <int Dim>
class KDTree
{
  private:
    struct KDTreeNode
    { 
      Point<Dim> point;
      KDTreeNode *left, *right;

      KDTreeNode() : point(), left(NULL), right(NULL) {}
      KDTreeNode(const Point<Dim> &point) : point(point), left(NULL), right(NULL) {}
    };

  public:
    bool smallerDimVal(const Point<Dim>& first, const Point<Dim>& second,
                       int curDim) const;

    bool shouldReplace(const Point<Dim>& target, const Point<Dim>& currentBest,
                       const Point<Dim>& potential) const;

    double squaredDist(const Point<Dim>& point1, const Point<Dim>& point2) const;

    KDTree(const vector<Point<Dim>>& newPoints);

    void buildTree(vector<Point<Dim>>& newPoints, int dim, int left, int right, KDTreeNode*& curRoot);

    int partition(vector<Point<Dim>>& list, int dim, int left, int right, int pivotIndex);

    Point<Dim>& quickselect(vector<Point<Dim>>& list, int dim, int left, int right, int k);

    KDTree(const KDTree<Dim>& other);

    void copy(KDTreeNode*& node, const KDTreeNode* copynode);

    KDTree const &operator=(const KDTree<Dim>& rhs);

    ~KDTree();

    void destroy(KDTreeNode*& node);

    Point<Dim> findNearestNeighbor(const Point<Dim>& query) const;

    Point<Dim> nearestNeighborHelper(const Point<Dim>& query, int dim, const KDTreeNode* curRoot) const;

    // void printTree(ostream& out = cout,
    //                colored_out::enable_t enable_bold = colored_out::COUT,
    //                int modWidth = -1) const;

  private:

    // Internal representation, root and size
    KDTreeNode *root;
    size_t size;

    // Helper function for grading
    // int getPrintData(KDTreeNode * subroot) const;

    // Helper function for grading
    // void printTree(KDTreeNode * subroot, std::vector<std::string>& output,
    //                int left, int top, int width, int currd) const;
};

#include "kdtree.hpp"
