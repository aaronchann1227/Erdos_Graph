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
        BFS(const Graph & input_graph, Vertex* start);
        void add(Vertex* math_);
        Vertex* pop();
        Vertex* peek() const;
        bool empty() const;
        std::vector<int> myarr;
        Graph& getG() {
            return G;
        }

    private:
        queue<Vertex*> q;
        Vertex* Start;
        Vertex* Current;
        Graph G;
        //std::vector<vector<int> > myarr;
};