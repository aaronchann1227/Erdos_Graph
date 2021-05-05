#include "Graph.h"
#include <iostream>
using namespace std;
//unordered_map< Vertex, vector<Edge*> > vertexMap
// vector<Edge*> edges;
//
Graph::Graph(std::vector< std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper) {
    //Initializes the root of the graph
    this->authorToPaper = authorToPaper;
    /////////////////Need to create vertex first
    string authorErdos = "Erdos";
    Vertex* setRoot = new Vertex(authorErdos);
    //root->setAuthor("Erdos");
    root = setRoot;
    //cout << "enter constructor12";
    root->setID(0);
    vertices.push_back(root);

    //Traverses through the erdosVec the first time while initializing an
    //unordered map that is filled with all of the unique author names in erdosVec
    //std::cout << " at line 16" << std::endl;
    unsigned int idCounter = 1;
    for (size_t i = 0; i < erdosVec.size(); i++) {
        for (size_t j = 0; j < erdosVec[i].size(); j++) {

            if ( uniqueAuthors.find(erdosVec[i][j]) == uniqueAuthors.end() ) {
                //Vertex author(erdosVec[i][j]);
                Vertex* author = new Vertex(erdosVec[i][j]);
                author->setID(idCounter);
                uniqueAuthors[erdosVec[i][j]] = author;
                //Initializes a vector of Vertex pointers to each unique author
                vertices.push_back(author);
                
                idCounter++;
            }
        }
    }
    // for(unsigned i = 0; i < erdosVec.size(); ++i) {
    //     std::cout << "Key: " << erdosVec[i][0] << std::endl;
    // }

    //cout << "look" << ( uniqueAuthors.find("ALAOGLU, LEONIDAS") == uniqueAuthors.end() ) << endl;

    //std::cout << "print" << uniqueAuthors["ALAOGLU, LEONIDAS:"]->getAuthor() << std::endl;
    //Initializes the edge vectors inside each Vertex inside the graph
    unsigned count = 0;
    for (size_t i = 0; i < erdosVec.size(); i++) {
        Vertex* erdos1 = uniqueAuthors[erdosVec[i][0]];
        //std::cout << " at line 36 " << erdosVec[i][0] << std::endl;
        //cout << count << std::endl;
        count++;
        //  1/(n(a,b)/[(erd(a)+erd(b))/2])
        //
        // An edge will always have the following format:
        // Edge (name of whoever is closer to Erdos, name of second person, weight)
        double weight = 1;
        unsigned int publications = 1;
        if (authorToPaper.find(erdosVec[i][0]) != authorToPaper.end() ) {
            publications = authorToPaper[erdosVec[i][0]];
            weight = 1 / (2 * publications);
        }

        //cout << "enter " << erdos1->getAuthor() << " line 59" << endl;
        Edge* erdosToErdos1 = new Edge("Erdos", erdos1->getAuthor(), weight);
        //Edge erdosToErdos1("Erdos", erdos1->getAuthor(), weight);
        
        //adding edge for Erdos and Erdos1
        root->addEdge(erdosToErdos1);
        erdos1->addEdge(erdosToErdos1);

        for (size_t j = 1; j < erdosVec[i].size(); j++) {
            Vertex* erdos2 = uniqueAuthors[erdosVec[i][j]];
            //std::cout << "line 56" << std::endl;
            //An edge will always have the following format:
            // Edge (name of whoever is closer to Erdos, name of second person, weight)
            Edge* edge = new Edge(erdos1->getAuthor(), erdos2->getAuthor(), 1.0);
            //Edge edge(erdos1->getAuthor(), erdos2->getAuthor(), 1.0);
            erdos1->addEdge(edge);
            erdos2->addEdge(edge);
        }
    }
}

Graph::~Graph() {
    for (unsigned j = 0; j < edges.size(); j++) {
        delete edges[j];
    }

    for (unsigned i = 0; i < vertices.size(); i++) {
        delete vertices[i];
    }
}

unsigned int Graph::getSize() {
    return vertices.size();
}

unsigned int Graph::findID(std::string author) {
    for (size_t i = 0; i < vertices.size(); i++){
        if (vertices[i]->getAuthor() == author) {
            return vertices[i]->getID();
        }
    }
    return -1;
}

Vertex* Graph::getRoot() {
    return root;
}

Vertex* Graph::getVertex(std::string name) {
    return uniqueAuthors[name];
}