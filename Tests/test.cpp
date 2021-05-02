#include "../catch/catch.hpp"
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

//0. Test BFS

/* TEST_CASE("BFS maintains the correct point on top", "[weight=0][part=1][part=1b]") {
  Graph graph=makeGraph();
  Vertex* Erdos = graph.getRoot();
  Traversal Traversal(graph, Erdos);

  /* bfs.add( Arthur Benjamin );
  bfs.add( Manjul Bhargava );
  bfs.add( Bruce Reznick );

  REQUIRE( *Traversal == Erdos );
} */

// 1. Check number of Edros’s neighbors == 512
TEST_CASE("Check number of Erdos’s neighbors", "[weight=1][part=1]") {

  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  REQUIRE (512 == root->getEdge().size());

}

// 2. Check num of LACAMPAGNE, CAROLE BAKER neighbors == 8
TEST_CASE("Check num of LACAMPAGNE, CAROLE BAKER neighbors == 8", "[weight=1][part=1]") {
  
  Graph graph = makeGraph();
  Vertex* baker = graph.getVertex("LACAMPAGNE, CAROLE BAKER");

  REQUIRE (8 == baker->getEdge().size());
}

// 3. Check num of LARSON, JEAN ANN neighbors == 17
TEST_CASE("Check num of LARSON, JEAN ANN neighbors == 17", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* ann = graph.getVertex("LARSON, JEAN ANN");

  REQUIRE (17 == ann->getEdge().size());
}

// 4. Check num of Steprans, Juris neighbors == 4?
TEST_CASE("Check num of Steprans, Juris neighbors == 4", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* juris = graph.getVertex("Steprans, Juris");

  REQUIRE (4 == juris->getEdge().size());
}

// 5. Check num of Drake, Nathan neighbors == 2?
TEST_CASE("Check num of Drake, Natha neighbors == 2", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* natha = graph.getVertex("Drake, Natha");

  REQUIRE (2 == natha->getEdge().size());
}

// 6. (Erdos find leaf) case1: try the path Erdos -> ABBOTT, HARVEY LESLIE -> Zhou, Bing
TEST_CASE("Erdos to leaf case 1", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Vertex* leslie = graph.getVertex("ABBOTT, HARVEY LESLIE");
  Vertex* bing = graph.getVertex("Zhou, Bing");

  //first edge
  REQUIRE (root->isNeighbor("ABBOTT, HARVEY LESLIE") == true);
  REQUIRE (leslie->isNeighbor("Erdos") == true);

  //second edge
  REQUIRE (leslie->isNeighbor("Zhou, Bing") == true);
  REQUIRE (bing->isNeighbor("ABBOTT, HARVEY LESLIE") == true);
}

// 7. (Erdos find leaf) case2: try the path Erdos -> ASHBACHER, CHARLES D. -> Neirynck, Lori
TEST_CASE("Erdos to leaf case 2", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Vertex* charles = graph.getVertex("ASHBACHER, CHARLES D.");
  Vertex* lori = graph.getVertex("Neirynck, Lori");

  //first edge
  REQUIRE (root->isNeighbor("ASHBACHER, CHARLES D.") == true);
  REQUIRE (charles->isNeighbor("Erdos") == true);

  //second edge
  REQUIRE (charles->isNeighbor("Neirynck, Lori") == true);
  REQUIRE (lori->isNeighbor("ASHBACHER, CHARLES D.") == true);
}

// 8. (Leaf find Erdos) case1: try the path  Fraley, Chris -> BABU, GUTTI JOGESH -> Erdos
TEST_CASE("Leaf to Erdos 1", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Vertex* chris = graph.getVertex("Fraley, Chris");
  Vertex* jogesh = graph.getVertex("BABU, GUTTI JOGESH");

  //first edge
  REQUIRE (chris->isNeighbor("BABU, GUTTI JOGESH") == true);
  REQUIRE (jogesh->isNeighbor("Fraley, Chris") == true);

  //second edge
  REQUIRE (jogesh->isNeighbor("Erdos") == true);
  REQUIRE (root->isNeighbor("BABU, GUTTI JOGESH") == true);
}

// 9. (Leaf find Erdos) case2:  try the path  Bannai, Eiichi ->CAMERON, PETER JEPHSON -> Erdos
TEST_CASE("Leaf to Erdos 2", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Vertex* eiichi = graph.getVertex("Bannai, Eiichi");
  Vertex* jephson = graph.getVertex("CAMERON, PETER JEPHSON");

  //first edge
  REQUIRE (eiichi->isNeighbor("CAMERON, PETER JEPHSON") == true);
  REQUIRE (jephson->isNeighbor("Bannai, Eiichi") == true);

  //second edge
  REQUIRE (jephson->isNeighbor("Erdos") == true);
  REQUIRE (root->isNeighbor("CAMERON, PETER JEPHSON") == true);
}

// 10. (Cross path find leaf): try Erdos -> CANFIELD, EARL RODNEY -> GRANVILLE, ANDREW JAMES -> Cai, Tian Xin
TEST_CASE("Cross path find leaf", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Vertex* rodney = graph.getVertex("CANFIELD, EARL RODNEY");
  Vertex* james = graph.getVertex("GRANVILLE, ANDREW JAMES");
  Vertex* xin = graph.getVertex("Cai, Tian Xin");

  //first edge
  REQUIRE (root->isNeighbor("CANFIELD, EARL RODNEY") == true);
  REQUIRE (rodney->isNeighbor("Erdos") == true);

  //second edge
  REQUIRE (rodney->isNeighbor("GRANVILLE, ANDREW JAMES") == true);
  REQUIRE (james->isNeighbor("CANFIELD, EARL RODNEY") == true);

  //third edge
  REQUIRE (james->isNeighbor("Cai, Tian Xin") == true);
  REQUIRE (xin->isNeighbor("GRANVILLE, ANDREW JAMES") == true);
}

// 11. (Complicated Cross path Erdos cycle): Erdos -> GUNDERSON, DAVID SHANE -> HINDMAN, NEIL BRUCE -> Farah, Ilijas -> MAGIDOR, MENACHEM -> Erdos
TEST_CASE("Cross path find leaf", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Vertex* shane = graph.getVertex("GUNDERSON, DAVID SHANE");
  Vertex* bruce = graph.getVertex("HINDMAN, NEIL BRUCE");
  Vertex* ilijas = graph.getVertex("Farah, Ilijas");
  Vertex* menachem = graph.getVertex("MAGIDOR, MENACHEM");

  //first edge
  REQUIRE (root->isNeighbor("GUNDERSON, DAVID SHANE") == true);
  REQUIRE (shane->isNeighbor("Erdos") == true);

  //second edge
  REQUIRE (shane->isNeighbor("HINDMAN, NEIL BRUCE") == true);
  REQUIRE (bruce->isNeighbor("GUNDERSON, DAVID SHANE") == true);

  //third edge
  REQUIRE (bruce->isNeighbor("Farah, Ilijas") == true);
  REQUIRE (ilijas->isNeighbor("HINDMAN, NEIL BRUCE") == true);

  //fourth edge
  REQUIRE (ilijas->isNeighbor("MAGIDOR, MENACHEM") == true);
  REQUIRE (menachem->isNeighbor("Farah, Ilijas") == true);

  //fifth edge
  REQUIRE (root->isNeighbor("MAGIDOR, MENACHEM") == true);
  REQUIRE (menachem->isNeighbor("Erdos") == true);
}

// 12. Check weight of HALL, RICHARD ROXBY == formula(14)
TEST_CASE("Check weight 1", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Edge* roxbyEdge = root->getEdge("HALL, RICHARD ROXBY");
  REQUIRE (roxbyEdge->weight == 1 / (2 * 14));
}

// 13. Check weight of SZEMEREDI, ENDRE == formula(29)
TEST_CASE("Check weight 2", "[weight=1][part=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Edge* endreEdge = root->getEdge("SZEMEREDI, ENDRE");
  REQUIRE (endreEdge->weight == 1 / (2 * 29));
}