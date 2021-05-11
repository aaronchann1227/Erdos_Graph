#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <queue>
#include "Graph.h"
 
using namespace std;
class BFS{
    public:
        /**
        * BFS Constructor that takes in a reference to a graph and a starting vertex pointer.
        */
        BFS(Graph input_graph, Vertex* start);

        /**
        * Constructors for adding, popping, peeking and checking for empty queue.
        */
        void add(Vertex* math_);
        Vertex* pop();
        Vertex* peek() const;
        bool empty() const;

        /**
        * Array to keep track of visited nodes
        */
        std::vector<int> myarr;
        
        Graph& getG() {
            return G;
        }

    private:
        queue<Vertex*> q;
        Vertex* Start;
        Graph G;
};