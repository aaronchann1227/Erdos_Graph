#pragma once
#include <string>
#include <vector>


class Edge {
    public:
        Edge(std::string setV1, std::string setV2, double setWeight) {
            vertex1 = setV1;
            vertex2 = setV2;
            weight = setWeight;
        }
        
        std::string vertex1, vertex2;
        double weight;
};