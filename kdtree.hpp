#include "kdtree.h"
#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    if(first[curDim] == second[curDim]) {
        return first < second;
    }
    return first[curDim] < second[curDim];
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    double sumcurrent = 0.0;
    double sumpotential = 0.0;
    for(int x = 0; x < Dim; x++) {
        double currbestdiff = target[x] - currentBest[x];
        double currbestdiffsquared = currbestdiff * currbestdiff;
        double potentialdiff = target[x] - potential[x];
        double potentialdiffsquared = potentialdiff * potentialdiff;
        sumcurrent += currbestdiffsquared;
        sumpotential += potentialdiffsquared;
    }
    if(sumpotential == sumcurrent) {
        return potential < currentBest;
    }
    return sumpotential < sumcurrent;
}

template <int Dim>
double KDTree<Dim>::squaredDist(const Point<Dim>& point1, const Point<Dim>& point2) const {
    double distance = 0.0;
    for(int x = 0; x < Dim; x++) {
        distance += ((point1[x] - point2[x]) * (point1[x] - point2[x]));
    }
    return distance;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)  
{
    int size = (int)(newPoints.size());
    if(newPoints.empty()) {
        root = NULL;
        return;
    }
    vector<Point<Dim>> points(newPoints);
    buildTree(points, 0, 0, size-1, root);
}

template <int Dim>
void KDTree<Dim>::buildTree(vector<Point<Dim>>& newPoints, int dim, int left, int right, KDTreeNode*& curRoot) {
    if((int)(newPoints.size()) == 0) {
        return;
    }
    if(left <= right) {
        int middle = (left+right)/2;
        curRoot = new KDTreeNode(quickselect(newPoints, dim, left, right, middle));
        if(middle > left) {
        buildTree(newPoints, (dim+1)%Dim, left, middle-1, curRoot->left);
        }
        if(middle < right) {
        buildTree(newPoints, (dim+1)%Dim, middle+1, right, curRoot->right);
        }
    }
}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& list, int dim, int left, int right, int pivotIndex) {
    Point<Dim> pivotValue = list.at(pivotIndex);
    swap(list.at(pivotIndex), list.at(right));
    int storeIndex = left;
    for(int i = left; i < right; i++) {
        if(smallerDimVal(list.at(i), pivotValue, dim)) {
        swap(list.at(storeIndex), list.at(i));
        storeIndex++;
        }
    }
    swap(list.at(right), list.at(storeIndex));
    return storeIndex;
}

template <int Dim>
Point<Dim>& KDTree<Dim>::quickselect(vector<Point<Dim>>& list, int dim, int left, int right, int k) {
    while(true) {
        if(left == right) {
            return list.at(left);
        }
        int pivotIndex = partition(list, dim, left, right, k);
        if(k == pivotIndex) {
            return list.at(k);
        }
        else if(k < pivotIndex) {
            right = pivotIndex - 1;
        }
        else {
            left = pivotIndex + 1;
        }
    }
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
    copy(root, other.root);
}

template <int Dim>
void KDTree<Dim>::copy(KDTreeNode*& node, const KDTreeNode* copynode) {
    if(copynode == NULL) {
        return;
    }
    node = new KDTreeNode(copynode->point);
    copy(node->left, copynode->left);
    copy(node->right, copynode->right);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
    if(this != &rhs) {
        destroy(root);
        this = KDTree(rhs);
    }
    return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
    destroy(root);
}

template <int Dim>
void KDTree<Dim>::destroy(KDTreeNode*& node) {
    if(node == NULL) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    if(root != NULL) {
        return nearestNeighborHelper(query, 0, root);
    }
    return Point<Dim>();
}

template <int Dim>
Point<Dim> KDTree<Dim>::nearestNeighborHelper(const Point<Dim>& query, int dim, const KDTreeNode* curRoot) const {
    if(curRoot->left == NULL && curRoot->right == NULL) {
        return curRoot->point;
    }
    Point<Dim> nearest;
    bool recursedLeft = false;
    bool recursedRight = false;
    if(smallerDimVal(query, curRoot->point, dim) && curRoot->left != NULL) {
        nearest = nearestNeighborHelper(query, (dim+1)%Dim, curRoot->left); //left subtree
        recursedLeft = true;
    }
    else if(curRoot->right != NULL) {
        nearest = nearestNeighborHelper(query, (dim+1)%Dim, curRoot->right); //right subtree
        recursedRight = true;
    }
    if(shouldReplace(query, nearest, curRoot->point)) {
        nearest = curRoot->point;
    }
    double radius = squaredDist(query, nearest);
    double splitDist = (curRoot->point[dim] - query[dim]) * (curRoot->point[dim] - query[dim]);
    if(radius >= splitDist) {
        Point<Dim> tempNearest;
        if(recursedLeft && curRoot->right != NULL) {
            tempNearest = nearestNeighborHelper(query, (dim+1)%Dim, curRoot->right);
        }
        else if(recursedRight && curRoot->left != NULL) {
            tempNearest = nearestNeighborHelper(query, (dim+1)%Dim, curRoot->left);
        }
        if(shouldReplace(query, nearest, tempNearest)) {
            nearest = tempNearest;
        }
    }
    return nearest;
}