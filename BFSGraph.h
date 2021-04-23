#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <queue>
#include "Graph.cpp"
#include "Graph.h"
 
using namespace std;
class BFS{
    public:
        BFS(const Graph & input_graph, const Vertex* start);
        void add(const Vertex & math_);
        Vertex pop();
        Vertex peek() const;
        bool empty() const;
        std::vector<int> myarr;

    private:
        queue<Vertex*> q;
        Vertex* Start;
        Vertex* Current;
        Graph G;
        //std::vector<vector<int> > myarr;
};