#pragma once

#include <iterator>
#include "BFSGraph.h"
#include <vector>
//#include "BFSGraph.cpp"

using namespace std;
class Traversal {
    public:
        Traversal(Graph  input_graph, Vertex* start);
        void operator++();
        Vertex* operator*();
        bool T_done();
    private:
        BFS bfs;
};