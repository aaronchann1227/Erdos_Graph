#include "../Catch/catch.hpp"
#include "../Graph.h"
#include "../Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>

std::vector<std::vector<std::string>> readErdos() {
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

    out[0].erase(0,1);

    out.push_back("end123");

    std::vector< std::vector<std::string> > erdosVec;
    erdosVec.resize(513, std::vector<std::string> (0));

    unsigned count = 0;
    for (std::vector<std::string>::const_iterator i = out.begin(); i != out.end(); ++i) {
        while (*i != "end123") {
            erdosVec[count].push_back(*i);
            ++i;
        }
        count++;
    }

    return erdosVec;
}

std::unordered_map<std::string, unsigned int> createAuthorToPaper() {
  std::ifstream text("Publications.csv");
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

  std::string authors = strStream.str();

  std::vector<std::string> out;
  std::string delimiter = ":";

  size_t pos = 0;
  std::string token;
  while ((pos = authors.find(delimiter)) != std::string::npos) {
      token = authors.substr(0, pos);
      out.push_back(token);
      authors.erase(0, pos + delimiter.length());
  }
  std::unordered_map<std::string , unsigned int> authorToPaper;
  for (size_t i = 0; i < out.size(); i += 2) {
      authorToPaper[out[i]] = std::stoi(out[i + 1]); 
  }
  return authorToPaper;
}

Graph makeGraph() {
  Graph graph(readErdos(), createAuthorToPaper());
  return graph;
}


TEST_CASE("Check number of Erdos’s neighbors", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  REQUIRE (512 == root->getEdge().size());
}

TEST_CASE("Check num of LACAMPAGNE, CAROLE BAKER neighbors == 8", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* baker = graph.getVertex("LACAMPAGNE, CAROLE BAKER");

  REQUIRE (8 == baker->getEdge().size());
}