#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../di.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

#include <iostream>
#include <string>

using namespace std;


TEST_CASE("example", "[weight=1]") {
  int i = 1;
  REQUIRE( i == 1 );
}


TEST_CASE("find_shortest_path baby", "[weight=1]") {
  std::string nodename = "d_baby_test_node.csv";
  std::string neighborname = "d_baby_test_neightbor.csv";
  Dijkstra testdij(nodename,neighborname);
  Vertex start = to_string(0);
  Vertex end = to_string(4);
  vector<Vertex> result = testdij.find_shortest_path(start,end);
  for(int i = 0; i < (int)result.size(); i++){
    cout<< result[i]<<endl;
  }
  vector<Vertex> expected;
  REQUIRE(result == expected);
}