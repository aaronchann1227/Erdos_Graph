#pragma once
#include <string>
#include <vector>
#include "Edge.h"

class Vertex {
    public:
        /**
        * Constructor for Vertex
        */
        Vertex(std::string& author) : author(author) {}

        /**
        * function that return the Mathematician of the Vertex
        */
        std::string getAuthor() { return author; }

        /**
        * function to set the Mathematician of the Vertex
        */
        void setAuthor(std::string setAuthor) {this->author = setAuthor;}

        /**
        * function to add an edge to the Vertex
        */
        void addEdge(Edge* edge) {edges.push_back(edge);}

        /**
        * function that return the edge list of the Vertex
        */
        std::vector<Edge*> getEdge(){
            return edges;
        }

        /**
        * function that ID of the Vertex
        */
        unsigned int getID(){
            return id;
        }
        
        /**
        * function that set the ID of the Vertex
        */
        void setID(unsigned int id) {this->id = id;}

        /**
        * function that takes in an Mathematician and determines if that Mathematician is a neighbor of the Vertex.
        */
        bool isNeighbor(std::string author) {
            bool result = false;
            for (unsigned i = 0; i < edges.size(); ++i) {
                if ((edges[i]->vertex1 == author) ||  (edges[i]->vertex2 == author)) {
                    result = true;
                    break;
                }
            }
            return result;
        }

        /**
        * function that return a specific edge to a neighbor give the name of the Mathematician
        */
        Edge* getEdge(std::string author) {
            for (unsigned i = 0; i < edges.size(); ++i) {
                if ((edges[i]->vertex1 == author) ||  (edges[i]->vertex2 == author)) {
                    return edges[i];
                }
            }
            return nullptr;
        }

    private:
        // the name of the Mathematician
        std::string author;

        // the list of all the edges
        std::vector<Edge*> edges;

        // the ID of the vertex
        unsigned int id;
};