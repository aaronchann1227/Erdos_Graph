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
        ErdosGraph(std::vector< std::vector<std::string> > erdosVec, unordered_map<std::string , unsigned int> authorToPaper);

        /**
        * Abstract BFS traversal for the Erdos graph  
        */ 
        void ErdosBFS(Vertex* target) const;

        /**
        * find method that uses dijkstra's algorithm to find a path between two vertices
        */
        std::vector<Edge*> dijkstraFind(const Vertex v1, const Vertex v2) const;
        unsigned int getSize(){
            return vertices.size();
        }
        /**
        * custom printing method for visualizing the path
        */ 
        std::vector<std::string> printPath(std::vector<Edge*> path);

        /**
        * custom method for finding a vertex with author name and then returning the respective ID
        */ 
        unsigned int find(std::string author){
            for (int i=0;i<vertices.size(); i++){
                if vertices[i]==author{
                    return vertices[i].getID();
                }
            }
            return -1;
        }
    
    private:
        //Vertex* head;

        std::vector< Vertex*> vertices;

        vector<Edge*> edges;

        unordered_map< string, Vertex*> uniqueAuthors;

        Vertex* root;

        unordered_map<std::string , unsigned int> authorToPaper;

};