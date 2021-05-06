#include <iterator>
#include <vector>
#include "Traversal.h"

using namespace std;

/**
 * Traversal Constructor that takes in a reference to a graph and a starting vertex pointer.
 */

Traversal::Traversal(const Graph & input_graph, const Vertex* start){
    BFS BFS;
    BFS= BFS(input_graph, start);
}

/**
 * Traversal operator ++ that adds neighbors of current vertex into the traversal and visits current vertex.
 */

Traversal::operator++(){
    Vertex* curr;
    curr=BFS.peek();
    //Pseudocode Starts
    for Edge* e :curr.getEdge()){
        if (e->vertex1==curr){
            BFS.add(&e->vertex2);
            //unsigned int ID = e->vertex2.getID();
            //myarr[ID]=1;
        }
        else{
            BFS.add(&e->vertex1);
            //unsigned int ID = e->vertex1.getID();
            //myarr[ID]=1;
        }
    }
    while ((!BFS.empty()) && (BFS.myarr[curr->getID]){
      Vertex* vertex=BFS.pop();
      curr=vertex;
    }
    if ((!BFS.empty())){
      BFS.myarr[curr->getID]=1;
      //BFS.pop();
    }
}

/**
 * Checks if Traversal is complete.
 */

bool Traversal::T_done(){
    return BFS.empty();
}

/**
 * Returns current vertex in Traversal.
 */


Vertex* Traversal::operator*(){
    return BFS.peek();
}

