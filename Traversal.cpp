#include <iterator>
#include <vector>
#include "Traversal.h"

using namespace std;

/**
 * Traversal Constructor that takes in a reference to a graph and a starting vertex pointer.
 */

Traversal::Traversal(Graph input_graph, Vertex* start) : bfs{BFS(input_graph, start)} {}

/**
 * Traversal operator ++ that adds neighbors of current vertex into the traversal and visits current vertex.
 */

void Traversal::operator++(){
    Vertex* curr;
    curr=bfs.peek();
    bfs.myarr[0] = 1;
    while ((!bfs.empty()) && (bfs.myarr[curr->getID()])) {
      Vertex* vertex=bfs.pop();
      curr=vertex;
    }
    for (Edge* e : curr->getEdge()){
        if (e->vertex1==curr->getAuthor() && !bfs.myarr[bfs.getG().getVertex(e->vertex2)->getID()]){
            bfs.add(bfs.getG().getVertex(e->vertex2));
        }
        else if (!bfs.myarr[bfs.getG().getVertex(e->vertex1)->getID()]){
            bfs.add(bfs.getG().getVertex(e->vertex1));
        }
    }
    if ((!bfs.empty())){
      bfs.myarr[curr->getID()]=1;
      BFSvisited.push_back(curr->getAuthor());
      //bfs.pop();
    }
}

/**
 * Checks if Traversal is complete.
 */

bool Traversal::T_done(){
    return bfs.empty();
}

/**
 * Returns current vertex in Traversal.
 */


Vertex* Traversal::operator*(){
    return bfs.peek();
}

