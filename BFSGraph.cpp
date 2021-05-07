#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <queue>
//#include "Graph.cpp"
#include "Graph.h"
#include "BFSGraph.h"
#include <iostream>
using namespace std;

/**
 * BFS Constructor that takes in a reference to a graph and a starting vertex pointer.
 */
BFS::BFS(Graph input_graph, Vertex* start) : G(input_graph) {  
  Start=start;
  q.push(Start);
  myarr.resize(G.getSize());
  for (unsigned int i=0; i<myarr.size(); i++){
    myarr[i]=0;
  }
}

/**
 * Adds a vertex with the author's name to the traversal.
 */
void BFS::add(Vertex* math_) {
  q.push(math_);
}

/**
 * Removes and returns the current Vertex in the traversal.
 */
Vertex* BFS::pop() {
  Vertex* v= q.front();
  q.pop();
  return v;
}

/**
 * Returns the current Vertex in the traversal.
 */
Vertex* BFS::peek() const {

  return q.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  if (q.size()==0){
    return true;
  }
  return false;
}