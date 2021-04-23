#pragma once

#include <iterator>
#include "BFSGraph.h"
#include <vector>
#include "BFSGraph.cpp"

using namespace std;
class Traversal{
    public:
        Traversal(const Graph & input_graph, const Vertex* start);
        void operator++();
        Vertex* operator*();
        bool T_done();
    private:
        BFS BFS;
};