#include <iterator>
#include "BFSGraph.h"
#include "BFSGraph.cpp"
#include <vector>
#include "Traversal.h"

using namespace std;

Traversal::Traversal(const Graph & input_graph, const Vertex* start){
    BFS BFS;
    BFS= BFS(input_graph, start);
}


/*
//TODO
1  get_neighbors contructor using Vertex Struct (add constructor in vertex struct that returns a vector of vertex pointers)
2  Keep track of visited vertices (maybe using the information from the edges).
*/

Traversal::operator++(){
    Vertex* curr;
    curr=BFS.peek();
    //Pseudocode Starts
    for i in get_neighbors(curr){
        BFS.add(i);
    }
    while ((!BFS.empty()) && (!visited(curr)){
      Vertex* vertex=BFS.pop();
      curr=vertex;
    }
    if ((!BFS.empty())){
      visited(i)==true;
    }
}

Vertex* Traversal::operator*(){
    return BFS.peek();
}

