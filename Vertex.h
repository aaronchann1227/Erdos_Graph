#pragma once
#include <string>
#include <vector>


class Vertex {

    public:
    
        Vertex(std::string author) : author(author) {}

        std::string getAuthor() { return author; }

        void setAuthor(std::string setAuthor) {this->author = setAuthor;}

        void addEdge(Edge* edge) { edges.push_back(edge);}
        
        void setID(unsigned int id) {this->id = id;}

    private:

        std::string author;

        std::vector<Edge*> edges;

        unsigned int id;
        

};