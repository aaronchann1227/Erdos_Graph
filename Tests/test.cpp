#include "../catch/catch.hpp"
#include "../Graph.h"
#include "../ErdosRead.hpp"
#include "../ErdosRead.cpp"
#include "../Traversal.h"
#include "../Traversal.cpp"
#include "../cs225/PNG.h"

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
using namespace std;

Graph makeGraph() {
  Graph graph(readErdos(), createAuthorToPaper());
  return graph;
}

//////////////////////////////////////////////////////////////////////////////////////////////
/////TESTS for Graph Structure

//1. Check number of Edros’s neighbors == 512
TEST_CASE("Check number of Erdos’s neighbors", "[weight=1]") {

  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  REQUIRE (512 == root->getEdge().size());
}

// 2. Check num of LACAMPAGNE, CAROLE BAKER neighbors == 8
TEST_CASE("Check num of LACAMPAGNE, CAROLE BAKER neighbors == 8", "[weight=1]") {
  
  Graph graph = makeGraph();
  Vertex* baker = graph.getVertex("LACAMPAGNE, CAROLE BAKER");

  REQUIRE (12 == baker->getEdge().size());
}

// 3. Check num of LARSON, JEAN ANN neighbors == 17
TEST_CASE("Check num of LARSON, JEAN ANN neighbors == 17", "[weight=1]") {
  Graph graph = makeGraph();
  Vertex* ann = graph.getVertex("LARSON, JEAN ANN");

  REQUIRE (26 == ann->getEdge().size());
}

// 4. Check num of Steprans, Juris neighbors == 4?
TEST_CASE("Check num of Steprans, Juris neighbors == 4", "[weight=1]") {
  Graph graph = makeGraph();
  Vertex* juris = graph.getVertex("Steprans, Juris");

  REQUIRE (4 == juris->getEdge().size());
}

// 5. Check num of Drake, Nathan neighbors == 2?
TEST_CASE("Check num of Drake, Nathan neighbors == 2", "[weight=1]") {
  Graph graph = makeGraph();
  Vertex* natha = graph.getVertex("Drake, Nathan");
  REQUIRE (2 == natha->getEdge().size());
}

// 6. (Erdos find leaf) case1: try the path Erdos -> ABBOTT, HARVEY LESLIE -> Zhou, Bing
TEST_CASE("Erdos to leaf case 1", "[weight=1]") {
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
TEST_CASE("Erdos to leaf case 2", "[weight=1]") {
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
TEST_CASE("Leaf to Erdos 1", "[weight=1]") {
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
TEST_CASE("Leaf to Erdos 2", "[weight=1]") {
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
TEST_CASE("Cross path find leaf", "[weight=1]") {
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
TEST_CASE("Cross path find leaf2", "[weight=1]") {
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
TEST_CASE("Check weight 1", "[weight=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Edge* roxbyEdge = root->getEdge("HALL, RICHARD ROXBY");
  REQUIRE (roxbyEdge->weight == 1.0 / (2.0 * 14.0));
}

// 13. Check weight of SZEMEREDI, ENDRE == formula(29)
TEST_CASE("Check weight 2", "[weight=1]") {
  Graph graph = makeGraph();
  Vertex* root = graph.getRoot();
  Edge* endreEdge = root->getEdge("SZEMEREDI, ENDRE");
  REQUIRE (endreEdge->weight == 1.0 / (2.0  * 29.0 ));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////TESTS for BFS

TEST_CASE("BFS maintains the correct point on top", "[weight=1]") {
  Graph graph = makeGraph();

  Vertex* erdos = graph.getRoot();
  Traversal traversal(graph, erdos);

  REQUIRE( erdos->getAuthor() == (*traversal)->getAuthor());
}

TEST_CASE("BFS operator++", "[weight=1]") {
  Graph graph=makeGraph();
  Vertex* Erdos = graph.getRoot();
  Traversal Traversal(graph, Erdos);

  REQUIRE( *Traversal == Erdos );
  ++Traversal;
  REQUIRE( (*Traversal)->getAuthor() == "ABBOTT, HARVEY LESLIE" );
}

TEST_CASE("BFS operator++ (Checking if Erdos is visited twice)", "[weight=1][part=1b]") {
  Graph graph=makeGraph();
  Vertex* Erdos = graph.getRoot();
  Traversal Traversal(graph, Erdos);
  bool check=false;


  REQUIRE( (*Traversal) == Erdos );
  //BFS traversal on the whole graph (over 13000 vertices)
  int count=0;
  while (!Traversal.T_done()){
    ++Traversal;
    if ((*Traversal)==Erdos){
      check=true;
    }
    count+=1;
  }
  REQUIRE( check == false );
}

TEST_CASE("BFS operator++ (Checking if every node is visited exactly once)", "[weight=1]") {
  Graph graph=makeGraph();
  Vertex* Erdos = graph.getRoot();
  Traversal Traversal(graph, Erdos);
  //
  int count = -1;
  while (!Traversal.T_done()){
    count += 1;
    ++Traversal;
  }
  REQUIRE( count == graph.getSize() );
}

TEST_CASE("print 10 BFSvisited", "[weight=1]") {
  Graph graph=makeGraph();
  Vertex* Erdos = graph.getRoot();
  Traversal Traversal(graph, Erdos);
  int count = -1;
  while (!Traversal.T_done()){
    count += 1;
    ++Traversal;
  }
  // A vector of names that BFS traversed.
  vector<string> BFSvisited = Traversal.getBFSvisited();

  // print out the first 10 names that BFS traversed.
  Traversal.printBFSvisited(10);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////TESTS for Kruskal

TEST_CASE("Check num of Edges Kruskal return", "[weight=1]") {
  Graph graph = makeGraph();
  std::vector<Edge*> KruskalEdgeVec = graph.KruskalMST();

  REQUIRE( graph.getSize() - 1 == KruskalEdgeVec.size() );
}

TEST_CASE("Test Kruskal on small Erdos graph", "[weight=1]") {
  std::vector< std::vector<std::string> > testErdosVec;

  testErdosVec.push_back(vector<string> {"ANDRASFAI, BELA","SOS, VERA TURAN"});
  testErdosVec.push_back(vector<string> {"SOS, VERA TURAN","ANDRASFAI, BELA","Artstein-Avidan, Shiri", "BABAI, LASZLO","Balogh, Jozsef","Beck, Jozsef"});
  testErdosVec.push_back(vector<string> {"BABAI, LASZLO","Abert, Miklos","Adams, Michael E.","AJTAI, MIKLOS"});

  Graph testGraph(testErdosVec, createAuthorToPaper());
  // manually calculate Kruskal total weight (the minimum weight)
  float expected_weight= (1.0/2.0)*(1.0/35.0 + 1.0/3.0 + 1.0) + 6.0;

  // the output of Kruskal algorithm
  std::vector<Edge*> KruskalEdgeVec = testGraph.KruskalMST();
  float sum1 = 0.0;
  for (Edge* edge : KruskalEdgeVec){
    sum1+=edge->weight;
  }

  REQUIRE( testGraph.getSize() - 1 == KruskalEdgeVec.size() );
  REQUIRE( (abs(sum1-expected_weight)) < 0.0001);
}

TEST_CASE("Test Kruskal on small Erdos graph (2)", "[weight = 1]") {
  std::vector< std::vector<std::string> > testErdosVec2;

  testErdosVec2.push_back(vector<string> {"ABBOTT, HARVEY LESLIE","Charles Edward", "HANSON, DENIS"});
  testErdosVec2.push_back(vector<string> {"CHUNG, KAI-LAI","Balkema, August"});
  testErdosVec2.push_back(vector<string> {"HANSON, DENIS","Alspach, Brian Roger&Ao, Suqin","ABBOTT, HARVEY LESLIE"});

  Graph testGraph2(testErdosVec2, createAuthorToPaper());

  // manually calculate Kruskal total weight (the minimum weight)
  float expected_weight2= (1.0/2.0)*(1.0 + 1.0 + 1.0/4.0) + 3.0;

  // the output of Kruskal algorithm
  std::vector<Edge*> KruskalEdgeVec2 = testGraph2.KruskalMST();
  
  float sum2 = 0.0;
  for (Edge* edge : KruskalEdgeVec2){
    sum2+=edge->weight;
  }

  REQUIRE( testGraph2.getSize() - 1 == KruskalEdgeVec2.size() );
  REQUIRE( (abs(sum2-expected_weight2)) < 0.0001);
}

TEST_CASE("Test Kruskal on small Erdos graph (3)", "[weight=1]") {
  std::vector< std::vector<std::string> > testErdosVec3;

  testErdosVec3.push_back(vector<string> {"ABBOTT, HARVEY LESLIE","MOON, JOHN WESLEY", "SAUER, NORBERT W."});
  testErdosVec3.push_back(vector<string> {"MOON, JOHN WESLEY","ABBOTT, HARVEY LESLIE"});
  testErdosVec3.push_back(vector<string> {"SAUER, NORBERT W.","ABBOTT, HARVEY LESLIE"});

  Graph testGraph3(testErdosVec3, createAuthorToPaper());
  float expected_weight3= (1.0/2.0)*(1.0 + 1.0/4.0 + 1.0);

  std::vector<Edge*> KruskalEdgeVec3 = testGraph3.KruskalMST();
  float sum3=0.0000;
  for (Edge* edge : KruskalEdgeVec3){
    sum3+=edge->weight;
  }

  REQUIRE( testGraph3.getSize() - 1 == KruskalEdgeVec3.size() );
  REQUIRE( (abs(sum3-expected_weight3)) < 0.0001);
}

TEST_CASE("Testing Kruskal on the entire Graph", "[weight=1]") {
  Graph graph = makeGraph();
  float expectedTotalWeight = 0.0;
  unsigned int numOfErdos1 = 0;
  for (Edge* edge: graph.getRoot()->getEdge()) {
    expectedTotalWeight += edge->weight;
    numOfErdos1++;
  }
  float totalWeightErdos2 = (float) graph.getSize() - numOfErdos1 - 1;
  expectedTotalWeight += totalWeightErdos2;

  std::vector<Edge*> minimalSpanningTree = graph.KruskalMST();
  float resultEdgeWeight = 0.0;
  for (Edge* edge: minimalSpanningTree) {
    resultEdgeWeight += edge->weight;
  }
  REQUIRE (abs(expectedTotalWeight - resultEdgeWeight) < 0.0001 );
}

