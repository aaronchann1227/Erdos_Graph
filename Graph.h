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
        Graph(std::vector< std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper);

        /**
        * Destructor for the Erdos Graph
        */ 
        ~Graph();

        /**
        * copy constructor
        */
        Graph(const Graph & other);

        /**
        * = operator
        */
        const Graph & operator=(const Graph &other);

        /**
        * helper for copy constructor
        */
        void _copy(Graph const & other);
       
        /**
        * helper for delete
        */
        void _delete() ;

////////////////////////////////////////////////////////////////////////////////////////////////////
        // /**
        // * Abstract BFS traversal for the Erdos graph  
        // */ 
        // void ErdosBFS(Vertex* target) const;

        // /**
        // * find method that uses dijkstra's algorithm to find a path between two vertices
        // */
        // std::vector<Edge*> dijkstraFind(const Vertex v1, const Vertex v2) const;

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

        /**
        * return the Edge list of the Graph.
        */ 
        std::vector< Edge* > getWholeEdge();

        /**
        * return the all the Vertices of the Graph.
        */ 
        std::vector< Vertex* > getWholeVertex();
    
    private:
        Vertex* root;

        std::vector< Vertex* > vertices;

        std::vector< Edge* > wholeEdges;

        std::unordered_map< std::string, Vertex* > uniqueAuthors;

        std::unordered_map< std::string , unsigned int > authorToPaper;


        std::vector< std::vector<std::string> > erdosVec_;

        std::unordered_map<std::string , unsigned int> authorToPaper_;
};