#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Edge.h"
#include "Vertex.h"

class Graph {
    public:
        /**
        * Constructor for the Erdos Graph
        */ 
        Graph(std::vector< std::vector<std::string> > erdosVec, unordered_map<std::string , unsigned int> authorToPaper);

        /**
        * Abstract BFS traversal for the Erdos graph  
        */ 
        void ErdosBFS(Vertex* target) const;

        /**
        * find method that uses dijkstra's algorithm to find a path between two vertices
        */
        std::vector<Edge*> dijkstraFind(const Vertex v1, const Vertex v2) const;

        /**
        * method that return the number of vertices of the graph.
        */ 
        unsigned int getSize();

        /**
        * custom printing method for visualizing the path
        */ 
        std::vector<std::string> printPath(std::vector<Edge*> path);

        /**
        * custom method for finding the ID of a vertex with author name and then returning the respective ID
        */ 
        unsigned int findID(std::string author);

        /**
        * method that return the root of the graph, aka Edros.
        */ 
        Vertex* getRoot();

        /**
        * return the Vertex given the name of the Mathematician.
        */ 
        Vertex* getVertex(std::string name);
    
    private:
        Vertex* root;

        std::vector< Vertex* > vertices;

        std::vector< Edge* > edges;

        std::unordered_map< std::string, Vertex* > uniqueAuthors;

        std::unordered_map< std::string , unsigned int > authorToPaper;
};