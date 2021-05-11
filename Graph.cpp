#include <algorithm>
#include <chrono>
#include <random>
#include "Graph.h"
#include <iostream>
#include "DisjointSet.h"
#include <algorithm>
#include <math.h>
#include "cs225/PNG.h"

#include "Animation.h"

using namespace cs225;
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// below are constructor, copy constructor, destructor, operator= and their helper functions.

void Graph::constructGraphHelper(std::vector< std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper) {
    // The map that contains publication number of the majority of Erdos 1
    this->authorToPaper_ = authorToPaper;
    // The vector that contains names of all Mathematicians 
    this->erdosVec_ = erdosVec;

    //Initializes the root of the graph
    string authorErdos = "Erdos";
    Vertex* setRoot = new Vertex(authorErdos);
    root = setRoot;
    root->setID(0);
    vertices.push_back(root);
    uniqueAuthors["Erdos"] = root;

    //Traverses through the erdosVec the first time while initializing an
    //unordered map that is filled with all of the unique author names in erdosVec
    unsigned int idCounter = 1;

    for (size_t i = 0; i < erdosVec.size(); i++) {
        for (size_t j = 0; j < erdosVec[i].size(); j++) {
            // Check if the vertex already exists
            if ( uniqueAuthors.find(erdosVec[i][j]) == uniqueAuthors.end() ) {
                Vertex* author = new Vertex(erdosVec[i][j]);
                // set unique ID for each vertex
                author->setID(idCounter);

                // populating uniqueAuthors (the map that map name to vertex pointer)
                uniqueAuthors[erdosVec[i][j]] = author;
                
                // populating idToVertex  (the map that map ID to vertex pointer)
                idToVertex[idCounter] = author;

                //Initializes a vector of Vertex pointers to each unique author
                vertices.push_back(author);
                
                idCounter++;
            }
        }
    }
    
    //Initializes the edge vectors inside each Vertex inside the graph
    unsigned count = 0;
    for (size_t i = 0; i < erdosVec.size(); i++) {
        Vertex* erdos1 = uniqueAuthors[erdosVec[i][0]];
        count++;
        //  Formula for the edge weight: 1 / (2 * publications with Erdos)
        //
        //  An edge will always have the following format:
        //  Edge (name of whoever is closer to Erdos, name of second person, weight)
        double weight = 0.5;

        // if publication information did not exist in authorToPaper, it means that publications = 1 and weight = 0.5.
        double publications = 1.0;

        // check if publication information for that Mathematician exists
        if (authorToPaper.find(erdosVec[i][0]) != authorToPaper.end() ) {
            publications = authorToPaper[erdosVec[i][0]];
            weight = 1 / (2 * publications);
        }

        // initialize Edge between Erdos 1 and Erdos
        Edge* erdosToErdos1 = new Edge("Erdos", erdos1->getAuthor(), weight);

        // push back to wholeEdges: the vector containing all Edges of the Graph
        wholeEdges.push_back(erdosToErdos1);
        
        // adding Edge for Erdos and Erdos1
        root->addEdge(erdosToErdos1);
        erdos1->addEdge(erdosToErdos1);

        for (size_t j = 1; j < erdosVec[i].size(); j++) {
            Vertex* erdos2 = uniqueAuthors[erdosVec[i][j]];
            // An edge will always have the following format:
            // Edge (name of whoever is closer to Erdos, name of second person, weight)

            // for all Mathematicians that have no direct publications with Erdos (Erdos2 Mathematicians), that will all have weight = 1.
            Edge* edge = new Edge(erdos1->getAuthor(), erdos2->getAuthor(), 1.0);
            wholeEdges.push_back(edge);
            erdos1->addEdge(edge);
            erdos2->addEdge(edge);
        }
    }
}

// The actual constructor
Graph::Graph(std::vector< std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper) {
    constructGraphHelper(erdosVec, authorToPaper);
}

void Graph::_copy(Graph const & other) {
    // Clear self
    _delete();
    constructGraphHelper(other.erdosVec_, other.authorToPaper_);
}

void Graph::_delete() {
    // clear all Edges
    for (unsigned j = 0; j < wholeEdges.size(); j++) {
        if (wholeEdges[j] != NULL)
            delete wholeEdges[j];
    }
    // clearn all vertices
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i] != NULL)
            delete vertices[i];
    }
}

// destructor
Graph::~Graph() {
    _delete();
}

// copy constructor
Graph::Graph(const Graph & other) {
    _copy(other);
}

// operator=
const Graph & Graph::operator=(Graph const & other) {
    if (this != &other) {
        _copy(other);
    }
    return *this;
}

// above are constructor, copy constructor, destructor, operator= and their helper functions.
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// below are class utility methods

// get the total number of vertices in the Graph
unsigned int Graph::getSize() {
    return vertices.size();
}

// find the ID of the vertex give the name of the Mathematician
unsigned int Graph::findID(std::string author) {
    for (size_t i = 0; i < vertices.size(); i++){
        if (vertices[i]->getAuthor() == author) {
            return vertices[i]->getID();
        }
    }
    return -1;
}

// get Root: Erdos
Vertex* Graph::getRoot() {
    return root;
}

// find the vertex give the name of the Mathematician
Vertex* Graph::getVertex(std::string name) {
    return uniqueAuthors[name];
}

// get the vector that contains all Edges of the Graph
std::vector< Edge* > Graph::getWholeEdge() {
    return wholeEdges;
}

// get the vector that contains all Verteices of the Graph
std::vector< Vertex* > Graph::getWholeVertex() {
    return vertices;
}

// the compare function to compare two Edges by weights
bool compareEdges(Edge* edge1, Edge* edge2) {return edge1->weight < edge2->weight;}

// above are class utility methods
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// below is Kruskal Minimum Spanning Tree algorithm
std::vector<Edge*> Graph::KruskalMST() {
    // initialize and build the Disjoint Set O(n)
    DisjointSets forest;
    for (Vertex* v: vertices) {
        forest.addelements(v->getID());
    }

    // initialize, build and sort the priority Queue running time O(mlog(n))
    // implement the priority Queue using a sorted array
    std::vector<Edge*> priorityQueue;
    for (Edge* edge: wholeEdges) {
        priorityQueue.push_back(edge);
    }
    // sort the priority Queue
    std::sort(priorityQueue.begin(), priorityQueue.end(), compareEdges);

    // initialize the the vector that contains all edges to connect the MST
    // this vector is also the output of the function
    std::vector<Edge*> spanningTree;

    // keep removing till number of Edges reaches (n - 1)
    while (spanningTree.size() < vertices.size() - 1) {
        Edge* edge = priorityQueue.front();
        // removing Edge
        priorityQueue.erase(priorityQueue.begin());
        // retrieve the Vertices by name
        Vertex* v1 = getVertex(edge->vertex1); 
        Vertex* v2 = getVertex(edge->vertex2); 

        // check if two vertices already belong to the same set (already connected)
        if (forest.find(v1->getID()) != forest.find(v2->getID())) {
            // push Edge to output vector if two vertices are not already connected
            spanningTree.push_back(edge);
            // set union of two Vertices
            forest.setunion(forest.find(v1->getID()), forest.find(v2->getID()));
        }
    }
    // return the vector that contains all edges to connect the MST
    return spanningTree;
}

// above is Kruskal Minimum Spanning Tree algorithm
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// below is visualization algorithm: Barycentric method and its helper functions


/**
* method that calculates attractive forces between vertices of the Graph 
*/
float fa(unsigned x, unsigned k){
    return (x*x)/k;
}

/**
* method that calculates repulsive forces between vertices of the Graph 
*/
float fr(unsigned x, unsigned k){
    return (k*k)/(x+0.0001);
}

/**
* method that calculates magnitude of a 2D vector
*/
float magnitude(std::pair<int, int> delta){
    return pow((delta.first*delta.first)+(delta.second*delta.second),0.5);
}

/**
* Implements The Barycentric Method and writes result to a PNG file 
*/
PNG Graph::BCVisualize() {
    Animation animation;
    unsigned k = pow(Area/vertices.size(), 0.5);
    float t = 10;
    int c=0;
    std::vector<std::pair<int, int>> coordinates;
    std::vector<std::pair<int, int>> displacement;

    // assign all vertices their initial random positions
    for (Vertex* v : vertices) {
        if (v->getID() == 0) {
           coordinates.push_back(std::pair<int, int>((width / 2), (length / 2)));
     
        } else {
            coordinates.push_back(std::pair<int,int>((v->getID() * 50 + v->getID()) % width + 1, (v->getID() * 50) % width));
        }
    }

    // calculating all forces on each vertex and relocating them accordingly
    displacement.resize(coordinates.size());
    PNG png(width, length);
    for (int i = 0; i<1; i++) {
        for (Vertex* v : vertices){
            std::pair<int, int> vdisp(0,0);
            for (Vertex* u : vertices){
                if (v != u) {
                    int cord1=coordinates[v->getID()].first-coordinates[u->getID()].first;
                    int cord2=coordinates[v->getID()].second-coordinates[u->getID()].second;
                    std::pair<int, int> delta(cord1, cord2);
                    vdisp.first+=(int)((delta.first/magnitude(delta)) * fr(magnitude(delta), k))%width;
                    vdisp.second+=(int)((delta.second/magnitude(delta)) * fr(magnitude(delta), k))%width;
                    displacement[v->getID()]=(vdisp);
                }
            }
        }
        for (Edge* e : wholeEdges){
            int v1id = getVertex(e->vertex1)->getID();
            int v2id = getVertex(e->vertex2)->getID();
            int cord3 = coordinates[getVertex(e->vertex1)->getID()].first - coordinates[getVertex(e->vertex2)->getID()].first;
            int cord4 = coordinates[getVertex(e->vertex1)->getID()].second - coordinates[getVertex(e->vertex2)->getID()].second;
            std::pair<int, int> delta(cord3, cord4);
            displacement[v1id].first -= (int)((delta.first / magnitude(delta)) * fa(magnitude(delta), k))%width;
            displacement[v1id].second -= (int)((delta.second / magnitude(delta)) * fa(magnitude(delta), k))%width;
            displacement[v2id].first += (int)((delta.first / magnitude(delta)) * fa(magnitude(delta), k))%width;
            displacement[v2id].second += (int)((delta.second / magnitude(delta)) * fa(magnitude(delta), k))%width;

        }
        for (Vertex* v : vertices){
            int ID = v->getID();
            coordinates[ID].first += (displacement[ID].first / magnitude(displacement[ID])) * min(magnitude(displacement[ID]), t);
            coordinates[ID].second += (displacement[ID].second / magnitude(displacement[ID])) * min(magnitude(displacement[ID]), t);
            coordinates[ID].first = min(width, std::max(c, coordinates[ID].first)); 
            coordinates[ID].second = min(length, std::max(c, coordinates[ID].second));
            coordinates[ID].first = abs(coordinates[ID].first);
            coordinates[ID].second = abs(coordinates[ID].second);
        }

        // begin writing vertices to PNG
        for (unsigned int i = 0; i < coordinates.size(); i++) {
            unsigned int xPos = coordinates[i].first % width;
            unsigned int yPos = coordinates[i].second % length;
            unsigned int color = (rand() * 360 / 100) % 360;
            int radius = 4;
            if (i == 0) {
                radius = 30;
            }
            for (int x = -radius; x < radius; x++) {
                for (int y = -radius; y < radius; y++) {
                    if ((xPos + x < width) && (yPos + y) < length && (xPos + x) >= 0 && (yPos + y) >= 0) {  
                        if (sqrt(x*x + y*y) <= radius) {  
                            HSLAPixel & pixel = png.getPixel(xPos + x, yPos + y);
                            pixel.h = color;
                            pixel.l = 0.6;
                            pixel.s = 0.5;
                        }    
                    }
                }   
            }
            for (Edge* edge : vertices[i]->getEdge()) {
               Vertex* target = getVertex(edge->vertex2);
               if (vertices[i] == target) {
                   target = getVertex(edge->vertex1);
               }
               unsigned int targetX = coordinates[target->getID()].first % width;
               unsigned int targetY = coordinates[target->getID()].second % length;
               unsigned int dy = yPos - targetY; 
               unsigned int dx = xPos - targetX; 
               if (dy > dx) {
                   for (unsigned int yM = targetY; yM != yPos; yM += (dy / abs((int) dy) )) {
                       unsigned int currentX = targetX + (yM - targetY) * dx / dy;
                       if ((currentX < width) && (yM) < length && (currentX) >= 0 && (yM) >= 0){
                        HSLAPixel & pixel = png.getPixel(currentX, yM);
                        pixel.h = (rand() * 36) % 360;
                        pixel.l = 0.6;
                        pixel.s = 0.5;
                       }
                   }
               } else {
                   for (unsigned int xM = targetX; xM != xPos; xM += (dx / abs((int) dx))) {
                       unsigned int currentY = targetY + (xM - targetX) * dy / dx;
                       if ((xM < width) && (currentY) < length && (xM) >= 0 && (currentY) >= 0){
                        HSLAPixel & pixel = png.getPixel(xM, currentY);
                        pixel.h = (rand() * 36) % 360;
                        pixel.l = 0.6;
                        pixel.s = 0.5;
                       }
                   }
               }               
            }
        }

        t *= 0.9;
    }
     return png;
}