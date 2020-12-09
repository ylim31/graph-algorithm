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
  BFS test("BFS-csv/bfs_baby_test_neighbor.csv", "BFS-csv/bfs_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);

  REQUIRE(result[0] == "2");
}

TEST_CASE(" Test 2 ", "[weight=1]") {
  BFS test("BFS-csv/bfs_baby_test_neighbor.csv", "BFS-csv/bfs_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);
  int length = result.size();
 
  REQUIRE(result[length - 1] == "0");
}

TEST_CASE(" Test 3 ", "[weight=1]") {
  BFS test("BFS-csv/bfs_baby_test_neighbor.csv", "BFS-csv/bfs_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);

  vector<Vertex> expected;
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("0"));
    
  REQUIRE(result == expected);
}

TEST_CASE(" Test 4 ", "[weight=2]") {
  BFS test("BFS-csv/bfs_baby_test_neighbor 2.csv", "BFS-csv/bfs_baby_test_neighbor 2.csv");
  Vertex start = to_string(0);
  vector<Vertex> result = test.traversal(start);
  
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("4"));
    
  REQUIRE(result == expected);
} 


