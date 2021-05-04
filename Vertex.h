#pragma once
#include <string>
#include <vector>
#include "Edge.h"

class Vertex {
    public:
        Vertex(std::string& author) : author(author) {}

        std::string getAuthor() { return author; }

        void setAuthor(std::string setAuthor) {this->author = setAuthor;}

        void addEdge(Edge* edge) {edges.push_back(edge);}

        std::vector<Edge*> getEdge(){
            return edges;
        }

        unsigned int getID(){
            return id;
        }
        
        void setID(unsigned int id) {this->id = id;}

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

        Edge* getEdge(std::string author) {
            for (unsigned i = 0; i < edges.size(); ++i) {
                if ((edges[i]->vertex1 == author) ||  (edges[i]->vertex2 == author)) {
                    return edges[i];
                }
            }
            return nullptr;
        }

    private:
        std::string author;

        std::vector<Edge*> edges;

        unsigned int id;
};