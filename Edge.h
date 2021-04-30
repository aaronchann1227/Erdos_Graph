#pragma once
#include <string>
#include <vector>
#include <Vertex.h>

class Edge {
    public:
        Edge(std::string setV1, Vertex setV2, double setWeight) {
            vertex1 = setV1;
            vertex2 = setV2;
            weight = setWeight;
        }
        
        Vertex vertex1, vertex2;
        double weight;
};