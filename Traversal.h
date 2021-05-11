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
        
        /**
         * get vector that stores all namve visisted in order
         */ 
        vector<string> getBFSvisited() { return BFSvisited; }

        /**
         * function that print out the first "itr"(number) names visited by BFS
         */ 
        void printBFSvisited(unsigned itr);

    private:
        BFS bfs;

        // The vector that stores all namve visisted in order
        vector<string> BFSvisited;
};