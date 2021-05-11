#pragma once

#include <iterator>
#include "BFSGraph.h"
#include <vector>

using namespace std;
class Traversal {
    public:

        /**
         * Traversal Constructor that takes in a reference to a graph and a starting vertex pointer.
         */
        Traversal(Graph  input_graph, Vertex* start);

        /**
         * Traversal Operators++ and Operator*.
         */
        void operator++();
        Vertex* operator*();

        /**
         * Checking if Traversal is done.
         */
        bool T_done();
        
        vector<string> getBFSvisited() { return BFSvisited; }
        void printBFSvisited(unsigned itr);

    private:
        BFS bfs;
        vector<string> BFSvisited;
};