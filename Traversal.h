#pragma once

#include <iterator>
#include "BFSGraph.h"
#include <vector>

using namespace std;
class Traversal {
    public:
        Traversal(Graph  input_graph, Vertex* start);
        void operator++();
        Vertex* operator*();
        bool T_done();
        vector<string> getBFSvisited() { return BFSvisited; }

    private:
        BFS bfs;
        vector<string> BFSvisited;
};