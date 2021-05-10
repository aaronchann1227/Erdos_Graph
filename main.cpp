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
using namespace std;

int main() {
    
    Graph graph(readErdos(), createAuthorToPaper());

    Animation animation = graph.BCVisualize();

    animation.write("ErdosVisualzied.gif");

    return 0;
}




