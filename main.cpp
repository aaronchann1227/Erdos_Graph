#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "ErdosRead.hpp"
#include "ErdosRead.cpp"
#include "Graph.h"
#include "Animation.h"
using std::cout;
using std::endl;

int main() {
    
    Graph graph(readErdos(), createAuthorToPaper());

    
    std::vector<std::pair<unsigned int, unsigned int>> animation = graph.BCVisualize();

    for (unsigned int i = 0; i < 100; i++) {
        cout << animation[i].first << endl;
        cout << animation[i].second << endl;
    }

    return 0;
}




