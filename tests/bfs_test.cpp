#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "string"
#include "iostream"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "../bfs.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

TEST_CASE(" Test 1 ", "[weight=1]") {
  BFS test("bfs_baby_test_node.csv", "bfs_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);

  /**for (unsigned i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  } **/
  
  vector<Vertex> expected;
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("1"));
    
  REQUIRE(result == expected);
}

TEST_CASE(" Test 2 ", "[weight=2]") {
  int i = 6;
  REQUIRE( i == 6 );
}

TEST_CASE(" Test 3 ", "[weight=3]") {
  int i = 9;
  REQUIRE( i == 9 );
}

