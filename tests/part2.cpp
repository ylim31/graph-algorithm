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

TEST_CASE("shortest", "[weight=1]") {
  //INITIALIZING LANDMARK WITH BABY FILE USE test AS VARIABLE
  LandMark test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = to_string(0);
  Vertex landmark = to_string(1);
  Vertex end = to_string(4);
  
  vector<Vertex> mark;
  mark.push_back(to_string(1));
  vector<Vertex> result = test.find_shortest_path(start, end, mark);
  vector<Vertex> expected;
 
  REQUIRE(result == expected);
}