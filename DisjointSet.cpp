#include "DisjointSet.h"
#include <iostream>

using namespace std;

/**
* Creates n unconnected root nodes at the end of the vector.
*
* @param num The number of nodes to create
**/
void DisjointSets::addelements(int num) {
    for (int i = 0; i < num; i++) {
        elements.push_back(-1);
    }
}

/**
* find the root of the uptree that elem is in.
* perform path compression along the way.
* 
* @param elem the index you want to find the root of
* @return index of the root 
**/
int DisjointSets::find(int elem) {
    if (elements[elem] < 0) {
        return elem;
    } else {
        elements[elem] = find(elements[elem]);
        return elements[elem];
    }
}


/**
* union by size: smaller point to larger
* In there is a tie, the second points to first
*
* @param a first index
* @param b second index
**/
void DisjointSets::setunion(int a, int b) {
    int root1 = find(a);
    int root2 = find(b);

    if (root1 == root2) return; 

    int newSize = elements[root1] + elements[root2];

    // first size larger or equal
    if (elements[root1] <= elements[root2]) {
        elements[root2] = root1;
        elements[root1] = newSize;
    } else {
    // second size larger
        elements[root1] = root2;
        elements[root2] = newSize;
    }
}


/**
*  return the number of nodes in the up-tree containing the element.
*
* @param elem the element
* @return the number of nodes in the up-tree containing the element.
**/
int DisjointSets::size(int elem) {
    int rootIndex = find(elem);
    return -1 * elements[rootIndex];
}