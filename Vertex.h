#pragma once
#include <string>
#include <vector>


struct Vertex {
    std::string author;
    std::vector<Edge*> edges;
};