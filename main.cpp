
#include <string>
#include <vector>
#include <iostream>
#include "ErdosRead.hpp"
#include "ErdosRead.cpp"
#include "Graph.h"
#include "Animation.h"
#include "Traversal.h"
#include "Traversal.cpp"
using std::cout;
using std::endl;


int main() {
    
    Graph graph(readErdos(), createAuthorToPaper());

    Vertex* Erdos = graph.getRoot();
    Traversal Traversal(graph, Erdos);
    int count = -1;
    while (!Traversal.T_done()){
        count += 1;
        ++Traversal;
    }

    // print out the first 10 names that BFS traversed.
    cout << "The first 10 Mathematicians that BFS traverses: \n";
    Traversal.printBFSvisited(10);

    
    // PNG animation = graph.BCVisualize();
    // animation.writeToFile("ErdosPNG.png");

    return 0;
}




