#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <queue>
#include "Graph.cpp"
#include "Graph.h"
#include "BFSGraph.h"
using namespace std;
BFS::BFS(const Graph & input_graph, const Vertex* start) {  
  Start=start;
  q.push(Start);
  G=input_graph;
}

void BFS::add(const Vertex* & math_) {
  q.push(math_);
  /** @todo [Part 1] */
}

/**
 * Removes and returns the current Point in the traversal.
 */
Vertex* BFS::pop() {
  /** @todo [Part 1] */
  Vertex v= q.front();
  q.pop();
  return v;
  //return Point(0, 0);
}

/**
 * Returns the current Point in the traversal.
 */
Vertex* BFS::peek() const {
  /** @todo [Part 1] */
  return q.front();
  //return Point(0, 0);
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  if (q.size()==0){
  /** @todo [Part 1] */
    return true;
  }
  return false;
}