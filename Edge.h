#pragma once
#include <string>
#include <vector>


class Edge {
    public:
        /**
        * Constructor of an Edge
        */
        Edge(std::string setV1, std::string setV2, double setWeight) {
            vertex1 = setV1;
            vertex2 = setV2;
            weight = setWeight;
        }
        
        // the two ends of the Edge
        std::string vertex1, vertex2;

        
        // the weight of the Edge
        double weight;
};

class EdgeCompare {
    public:
        // comparator function
        bool operator()(const Edge& a, const Edge& b) {
            return a.weight > b.weight; // compare based on age
    }
};