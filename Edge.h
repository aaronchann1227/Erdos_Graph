#pragma once
#include <string>
#include <vector>

struct Edge {
    Edge(string setV1, string setV2, double setWeight) {
        vertex1 = setV1;
        vertex2 = setV2;
        weight = setWeight;
    }
    
    Vertex vertex1, vertex2;
    double weight;
};