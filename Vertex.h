#pragma once
#include <string>
#include <vector>


class Vertex {

    public:
    
        Vertex(std::string author) : author(author) {}

        std::string getAuthor() { return author; }

        void setAuthor(std::string setAuthor) {this->author = setAuthor;}

        

    private:

        std::string author;

        std::vector<Edge*> edges;

    
};