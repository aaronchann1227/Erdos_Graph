#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Edge.h"
#include "Vertex.h"




class ErdosGraph {
    
    public:
        /**
        * Constructor for the Erdos Graph
        */ 
        ErdosGraph(std::vector< std::vector<std::string> > erdosVec);

        /**
        * Abstract BFS traversal for the Erdos graph  
        */ 
        void ErdosBFS(Vertex* target) const;

        /**
        * find method that uses dijkstra's algorithm to find a path between two vertices
        */
        std::vector<Edge*> dijkstraFind(const Vertex v1, const Vertex v2) const;
        /**
        * custom printing method for visualizing the path
        */ 
        std::vector<std::string> printPath(std::vector<Edge*> path);
    
    private:
        //Vertex* head;

        std::vector< Vertex*> vertices;

        vector<Edge*> edges;

        unordered_map< string, Vertex*> uniqueAuthors;

        Vertex* root;

        unordered_map<std::string , unsigned int> authorToPaper;

};