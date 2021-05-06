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
    for (Edge* e : curr->getEdge()){
        if (e->vertex1==curr->getAuthor()){
            bfs.add(bfs.getG().getVertex(e->vertex2));
            //unsigned int ID = e->vertex2.getID();
            //myarr[ID]=1;
        }
        else{
            bfs.add(bfs.getG().getVertex(e->vertex1));
            //unsigned int ID = e->vertex1.getID();
            //myarr[ID]=1;
        }
    }
    while ((!bfs.empty()) && (bfs.myarr[curr->getID()])) {
      Vertex* vertex=bfs.pop();
      curr=vertex;
    }
    if ((!bfs.empty())){
      bfs.myarr[curr->getID()]=1;
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

