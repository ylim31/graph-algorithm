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

TEST_CASE(" Test Simple Graph - Beginning", "[weight=1]") {
  BFS test("BFS-csv/bfs_baby_test_neighbor.csv", "BFS-csv/bfs_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);

  REQUIRE(result[0] == "2");
}

TEST_CASE(" Test Graph with Cycle - End", "[weight=1]") {
  BFS test("BFS-csv/bfs_baby_test_neighbor.csv", "BFS-csv/bfs_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);
  int length = result.size();
 
  REQUIRE(result[length - 1] == "0");
}

TEST_CASE(" Test Graph with Cycle - Traversal ", "[weight=1]") {
  BFS test("BFS-csv/bfs_baby_test_neighbor.csv", "BFS-csv/bfs_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);

  vector<Vertex> expected;
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("0"));
  
  REQUIRE(result.size() == expected.size());
  REQUIRE(result == expected);
}

TEST_CASE(" Test Graph - Traversal ", "[weight=2]") {
  BFS test("BFS-csv/bfs_baby_test_neighbor 2.csv", "BFS-csv/bfs_baby_test_neighbor 2.csv");
  Vertex start = to_string(0);
  vector<Vertex> result = test.traversal(start);
  
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("4"));
  
  REQUIRE(result.size() == expected.size());
  REQUIRE(result == expected);
} 

TEST_CASE(" Test Different Components Graph - Traversal ", "[weight=2]") {
  BFS test("BFS-csv/different_component_neighbor.csv", "BFS-csv/different_component.csv");
  Vertex start = to_string(1);
  vector<Vertex> result = test.traversal(start);
  
  vector<Vertex> expected;
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("4"));
  
 // REQUIRE(result.size() == expected.size());
  REQUIRE(result == expected);
} 
