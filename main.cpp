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
#include "Graph.h"

using namespace std;

int main() {
    std::ifstream text("Erdos.csv");

    std::stringstream strStream;
    if (text.is_open()) {
        strStream << text.rdbuf();
    }

    std::string authors = strStream.str();

    std::vector<std::string> out;
    std::string delimiter = "&";

    size_t pos = 0;
    std::string token;
    while ((pos = authors.find(delimiter)) != std::string::npos) {
        token = authors.substr(0, pos);
        out.push_back(token);
        authors.erase(0, pos + delimiter.length());
    }

    //out[0].erase(0,1);

    //out.push_back("end123");

    std::vector< std::vector<std::string> > erdosVec;
    erdosVec.resize(512, std::vector<std::string> (0));

    unsigned count = 0;
    for (std::vector<std::string>::const_iterator i = out.begin(); i != out.end(); ++i) {
        while (*i != "end123") {
            erdosVec[count].push_back(*i);

            ++i;
                

            if ( i == out.end() ) {break;}
        }
        if (i == out.end() ) {break;}
        std::cout << count << "\n";
        count++;
        if (count == 513) {
            cout << "line 61";
            break;
        }
        std::cout << "line 60" << "\n";
    }
    for (size_t i = 0; i < erdosVec.size(); i++) {
        for (unsigned int k = 0; k < erdosVec[i].size(); k++) {
            cout << erdosVec[i][k];
        }
    }
    
    return 0;
}




