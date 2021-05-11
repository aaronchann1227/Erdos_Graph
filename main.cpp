
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
    
    // construct Graph
    Graph graph(readErdos(), createAuthorToPaper());

    Vertex* Erdos = graph.getRoot();

    cout << "\n\n";

    /////////////////////////////////////////////////////////////////////
    // BFS
    Traversal Traversal(graph, Erdos);
    int count = -1;
    while (!Traversal.T_done()){
        count += 1;
        ++Traversal;
    }
    // print out the first 10 names that BFS traversed.
    cout << "The first 10 Mathematicians that BFS traverses: \n";
    Traversal.printBFSvisited(10);

    cout << "\n\n";
    /////////////////////////////////////////////////////////////////////
    // Kruskal MST

    // We compared the number of edges Kruskal returns to expected number of edges Kruskal returns, which is n-1.
    std::vector<Edge*> KruskalEdgeVec = graph.KruskalMST();
    cout << "The number of edges KruskalMST() returns: "  << KruskalEdgeVec.size() << "\n";

    cout << "The expected number of edges: " << graph.getSize() - 1 << "\n";

    cout << "\n";
    // calculating expected total weight of the spanning tree and comparing it to the total
    // weights of all edges KruskalMST() returns.
    float expectedTotalWeight = 0.0;
    unsigned int numOfErdos1 = 0;
    for (Edge* edge: graph.getRoot()->getEdge()) {
        expectedTotalWeight += edge->weight;
        numOfErdos1++;
    }
    float totalWeightErdos2 = (float) graph.getSize() - numOfErdos1 - 1;
    expectedTotalWeight += totalWeightErdos2;

    std::vector<Edge*> minimalSpanningTree = graph.KruskalMST();
    float resultEdgeWeight = 0.0;
    for (Edge* edge: minimalSpanningTree) {
        resultEdgeWeight += edge->weight;
    }

    cout << "The total weight of all edges KruskalMST() returns: "  << resultEdgeWeight << "\n";

    cout << "The expected total weight of the spanning tree: "  << expectedTotalWeight << "\n";

    cout << "\n\n";
    return 0;
}




