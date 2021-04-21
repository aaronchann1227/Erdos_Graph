#pragma once
#include <string>
#include <vector>


struct Vertex {

    Vertex(string setV1, string setV2, double setWeight) {
        vertex1 = setV1;
        vertex2 = setV2;
        weight = setWeight;
    }

    string author;
    vector<Edge*> edges;
    
};