#include "Graph.h"
#include <iostream>
#include "DisjointSet.h"
#include <algorithm>
#include <math.h>
#include "cs225/PNG.h"

#include "Animation.h"

using namespace cs225;
using namespace std;

void Graph::constructGraphHelper(std::vector< std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper) {
    //Initializes the root of the graph
    this->authorToPaper_ = authorToPaper;
    this->erdosVec_ = erdosVec;
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

            if ( uniqueAuthors.find(erdosVec[i][j]) == uniqueAuthors.end() ) {
                Vertex* author = new Vertex(erdosVec[i][j]);
                author->setID(idCounter);

                // populating uniqueAuthors
                uniqueAuthors[erdosVec[i][j]] = author;
                
                // populating idToVertex
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
        //  Formula for the edge weight: 1/(n(a,b)/[(erd(a)+erd(b))/2])
        //
        //  An edge will always have the following format:
        //  Edge (name of whoever is closer to Erdos, name of second person, weight)
        double weight = 0.5;
        double publications = 1.0;
        if (authorToPaper.find(erdosVec[i][0]) != authorToPaper.end() ) {
            publications = authorToPaper[erdosVec[i][0]];
            weight = 1 / (2 * publications);
        }

        Edge* erdosToErdos1 = new Edge("Erdos", erdos1->getAuthor(), weight);
        wholeEdges.push_back(erdosToErdos1);
        
        //adding edge for Erdos and Erdos1
        root->addEdge(erdosToErdos1);
        erdos1->addEdge(erdosToErdos1);

        for (size_t j = 1; j < erdosVec[i].size(); j++) {
            Vertex* erdos2 = uniqueAuthors[erdosVec[i][j]];
            // An edge will always have the following format:
            // Edge (name of whoever is closer to Erdos, name of second person, weight)
            Edge* edge = new Edge(erdos1->getAuthor(), erdos2->getAuthor(), 1.0);
            wholeEdges.push_back(edge);
            erdos1->addEdge(edge);
            erdos2->addEdge(edge);
        }
    }
}
Graph::Graph(std::vector< std::vector<std::string> > erdosVec, std::unordered_map<std::string , unsigned int> authorToPaper) {
    constructGraphHelper(erdosVec, authorToPaper);
}

void Graph::_copy(Graph const & other) {
    // Clear self
    _delete();
    constructGraphHelper(other.erdosVec_, other.authorToPaper_);
    
}

void Graph::_delete() {
    for (unsigned j = 0; j < wholeEdges.size(); j++) {
        if (wholeEdges[j] != NULL)
            delete wholeEdges[j];
    }

    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i] != NULL)
            delete vertices[i];
    }
}


Graph::~Graph() {
    _delete();
}

Graph::Graph(const Graph & other) {
    _copy(other);
}

const Graph & Graph::operator=(Graph const & other) {
    if (this != &other) {
        _copy(other);
    }
    return *this;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
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

std::vector< Edge* > Graph::getWholeEdge() {
    return wholeEdges;
}

std::vector< Vertex* > Graph::getWholeVertex() {
    return vertices;
}

bool compareEdges(Edge* edge1, Edge* edge2) {return edge1->weight < edge2->weight;}
////////////////////////////////////////////////
std::vector<Edge*> Graph::KruskalMST() {
    DisjointSets forest;
    for (Vertex* v: vertices) {
        forest.addelements(v->getID());
    }

    std::vector<Edge*> priorityQueue;
    for (Edge* edge: wholeEdges) {
        priorityQueue.push_back(edge);
    }
    std::sort(priorityQueue.begin(), priorityQueue.end(), compareEdges);

    std::vector<Edge*> spanningTree;

    while (spanningTree.size() < vertices.size() - 1) {
        Edge* edge = priorityQueue.front();
        priorityQueue.erase(priorityQueue.begin());
        Vertex* v1 = getVertex(edge->vertex1); 
        Vertex* v2 = getVertex(edge->vertex2); 

        if (forest.find(v1->getID()) != forest.find(v2->getID())) {
            spanningTree.push_back(edge);
            forest.setunion(forest.find(v1->getID()), forest.find(v2->getID()));
        }
    }

    return spanningTree;

}

float fa(unsigned x, unsigned k){
    return x*x/k;
}

float fr(unsigned x, unsigned k){
    return k*k/(x+0.0001);
}

float magnitude(std::pair<unsigned int, unsigned int> delta){
    return pow((delta.first*delta.first)+(delta.second*delta.second),0.5);
}

Animation Graph::BCVisualize() {
    Animation animation;
    unsigned k = pow(Area/vertices.size(), 0.5);
    float t = 10;
    unsigned int c=0;
    std::vector<std::pair<unsigned int, unsigned int>> coordinates;
    std::vector<std::pair<unsigned int, unsigned int>> displacement;

    for (Vertex* v : vertices) {
        if (v->getID() == 0) {
           coordinates.push_back(std::pair<unsigned int, unsigned int>((width / 2), (length / 2)));
     
        } else {
            coordinates.push_back(std::pair<unsigned int, unsigned int>(((v->getID() * 50) % width), ((v->getID() * 50) /width)));
        }
    }
    displacement.resize(coordinates.size());
    for (int i = 0; i<10; i++) {
        for (Vertex* v : vertices){
            std::pair<unsigned int, unsigned int> vdisp(0,0);
            for (Vertex* u : vertices){
                if (v == u) {
                    continue;
                }
                unsigned int cord1=coordinates[v->getID()].first-coordinates[u->getID()].first;
                unsigned int cord2=coordinates[v->getID()].second-coordinates[u->getID()].second;
                std::pair<unsigned int, unsigned int> delta(cord1, cord2);
                vdisp.first+=(delta.first/magnitude(delta)) * fr(magnitude(delta), k);
                vdisp.second+=(delta.second/magnitude(delta)) * fr(magnitude(delta), k);
                displacement[v->getID()]=(vdisp);
            }
        }
        for (Edge* e : wholeEdges){
            int v1id=getVertex(e->vertex1)->getID();
            int v2id=getVertex(e->vertex2)->getID();
            unsigned int cord3=coordinates[getVertex(e->vertex1)->getID()].first-coordinates[getVertex(e->vertex2)->getID()].first;
            unsigned int cord4=coordinates[getVertex(e->vertex1)->getID()].second-coordinates[getVertex(e->vertex2)->getID()].second;
            std::pair<unsigned int, unsigned int> delta(cord3, cord4);
            displacement[v1id].first -= (delta.first/magnitude(delta)) * fa(magnitude(delta), k);
            displacement[v1id].second -= (delta.second/magnitude(delta)) * fa(magnitude(delta), k);
            displacement[v2id].first += (delta.first/magnitude(delta)) * fa(magnitude(delta), k);
            displacement[v2id].second += (delta.second/magnitude(delta)) * fa(magnitude(delta), k);
        }
        for (Vertex* v : vertices){
            int ID = v->getID();
            coordinates[ID].first += (displacement[ID].first/magnitude(displacement[ID])) * min(magnitude(displacement[ID]), t);
            coordinates[ID].second += (displacement[ID].second/magnitude(displacement[ID])) * min(magnitude(displacement[ID]), t);
            coordinates[ID].first = min(width, std::max(c, coordinates[ID].first)); 
            coordinates[ID].second = min(length, std::max(c, coordinates[ID].second));
        }

        PNG png(width, length);
        for (unsigned int i = 0; i < coordinates.size(); i++) {
            unsigned int xPos = coordinates[i].first % width;
            unsigned int yPos = coordinates[i].second % length;
            unsigned int color = (rand() * 360 / 100)  % 360;
            unsigned int radius = 3;
            if (authorToPaper_.find(vertices[i]->getAuthor()) != authorToPaper_.end() ) {
                radius = authorToPaper_[vertices[i]->getAuthor()];
            }
            if (i == 0) {
                radius = 60;
            }
            for (unsigned int x = xPos - radius; x < 2 * radius; x++) {
                for (unsigned int y = yPos - radius; y < 2 * radius; y++) {
                    if (sqrt(x*x + y*y) <= radius) {
                        HSLAPixel & pixel = png.getPixel(x, y);
                        pixel.h = color;
                        pixel.l = 0.6;
                        pixel.s = 0.5; 
                    }
                }
            }
            // for (Edge* edge : vertices[i]->getEdge()) {
            //    Vertex* target = getVertex(edge->vertex2);
            //    if (vertices[i] == target) {
            //        target = getVertex(edge->vertex1);
            //    }
            //    unsigned int targetX = coordinates[target->getID()].first % width;
            //    unsigned int targetY = coordinates[target->getID()].second % length;
            //    unsigned int dy = yPos - targetY; 
            //    unsigned int dx = xPos - targetX; 
            //    if (dy > dx) {
            //        for (unsigned int yM = targetY; yM != yPos; yM += (dy / abs((int) dy) )) {
            //            unsigned int currentX = targetX + (yM - targetY) * dx / dy;
            //             HSLAPixel & pixel = png.getPixel(currentX, yM);
            //             pixel.h = (rand() * 36) % 360;
            //             pixel.l = 0.6;
            //             pixel.s = 0.5;
            //        }
            //    } else {
            //        for (unsigned int xM = targetX; xM != xPos; xM += (dx / abs((int) dx))) {
            //            unsigned int currentY = targetY + (xM - targetX) * dy / dx;
            //            HSLAPixel & pixel = png.getPixel(xM, currentY);
            //            pixel.h = (rand() * 36) % 360;
            //            pixel.l = 0.6;
            //            pixel.s = 0.5;
            //        }
            //    }               
            // }
        }
        animation.addFrame(png);

        t *= 0.9;
    }
    return animation;
}