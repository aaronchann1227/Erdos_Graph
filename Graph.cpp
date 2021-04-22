// implementation

#include "Graph.h"

//unordered_map< Vertex, vector<Edge*> > vertexMap
// vector<Edge*> edges;
//
ErdosGraph::ErdosGraph(std::vector< std::vector<std::string> > erdosVec) {
    //Initializes the root of the graph
    root->setAuthor("Erdos");

    vertices.push_back(&root);

    //Traverses through the erdosVec the first time while initializing an
    //unordered map that is filled with all of the unique author names in erdosVec
    for (size_t i = 0; i < erdosVec.size(); i++) {
        for (size_t j = 1; j < erdosVec[i].size(); j++) {
            Vertex author(erdosVec[i][j]);
            if (uniqueAuthors.find(erdosVec[i][j]) == uniqueAuthors.end() ) {
                uniqueAuthors[erdosVec[i][j]] = &author;
                //Initializes a vector of Vertex pointers to each unique author
                vertices.push_back(&author);
            }
        }
    }
    //Initializes the edge vectors inside each Vertex inside the graph
    for (size_t i = 0; i < erdosVec.size(); i++) {
        Vertex* erdos1 = uniqueAuthors[erdosVec[i][0]];
        //An edge will always have the following format:
        // Edge (name of whoever is closer to Erdos, name of second person, weight)
        Edge erdosToErdos1("Erdos", erdos1->getAuthor(), 1);
        root->addEdge(&erdosToErdos1);
        erdos1->addEdge(&erdosToErdos1);
        for (size_t j = 1; j < erdosVec[i].size(); j++) {
            Vertex* erdo2(uniqueAuthors[erdosVec[i][j]]);

            //An edge will always have the following format:
            // Edge (name of whoever is closer to Erdos, name of second person, weight)
            Edge edge(erdos1->getAuthor(), erdos2->getAuthor(), 1.0);
            erdos1->addEdge(&edge);
            erdos2->addEdge(&edge);

        }

    }



    



    




}

