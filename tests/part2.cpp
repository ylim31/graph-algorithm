#include "catch.hpp"

#include "../landmark.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;


TEST_CASE("part2", "[weight=1]") {
    int i = 2;
    REQUIRE(i == 3);
}

TEST_CASE("shortest path baby 2 (landmark)", "[weight=1]") {
  //INITIALIZING LANDMARK WITH BABY FILE USE test AS VARIABLE
  
  Vertex start = to_string(0);
  Vertex landmark = to_string(1);
  Vertex end = to_string(4);
  
  test.g_.setEdgeWeight(to_string(0),to_string(1),6);
  test.g_.setEdgeWeight(to_string(0),to_string(3),1);
  test.g_.setEdgeWeight(to_string(1),to_string(3),2);
  test.g_.setEdgeWeight(to_string(1),to_string(4),2);
  test.g_.setEdgeWeight(to_string(1),to_string(2),5);
  test.g_.setEdgeWeight(to_string(2),to_string(4),5);
  test.g_.setEdgeWeight(to_string(3),to_string(4),1);
  
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back("0");
  expected.push_back("3");
  expected.push_back("1");
  expected.push_back("4");
  //REQUIRE(result == expected);
}