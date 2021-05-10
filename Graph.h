#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Edge.h"
#include "Vertex.h"
#include "Animation.h"
class Graph {
    public:
        /**
        * Helper function for the Constructor
        */ 
        void constructGraphHelper(std::vector<std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper);

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

        /**
        * find method that uses Kruskal's algorithm to find a list of Edges that connects a minimum spanning tree.
        */
        std::vector<Edge*> KruskalMST();

        /**
        * THE BARYCENTRIC METHOD to visualize the Graph
        */
        
        PNG BCVisualize();


        
    
    private:
        // root is always Erdos
        Vertex* root;

        // the vector to store all the vertices
        std::vector< Vertex* > vertices;

        // the vector to store all the edges
        std::vector< Edge* > wholeEdges;

        // a map from name of the Mathematician to the corresponding vertex
        std::unordered_map< std::string, Vertex* > uniqueAuthors;

        // a map from name of the Mathematician to number of publications
        std::unordered_map< std::string , unsigned int > authorToPaper_;

        // a map from vertex ID to the vertex
        std::unordered_map< unsigned int, Vertex* > idToVertex;

        // a vector that contains all Mathematicians
        std::vector< std::vector<std::string> > erdosVec_;

        // length of the visualization figure (constant)
        int length = 1000;

        // width of the visualization figure (constant)
        int width = 1000;

        // area of the visualization figure (constant)
        int Area = length*width;

};

/**
* The method to compare two edges
*/
bool compareEdges(Edge* edge1, Edge* edge2);

/**
* helper function of BCVisualize()
*/
float fa(unsigned x, unsigned k);

/**
* helper function of BCVisualize()
*/
float fr(unsigned x, unsigned k);

/**
* helper function of BCVisualize() to calculate the magnitude
*/
float magnitude(std::pair<int, int> delta);