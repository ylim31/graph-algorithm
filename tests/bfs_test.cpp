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
  BFS test("BFS-tests/bfs_test_cycle.json");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);

  REQUIRE(result[0] == "2");
}

TEST_CASE(" Test Graph with Cycle - End", "[weight=1]") {
  BFS test("BFS-tests/bfs_test_cycle.json");
  Vertex start = to_string(2);
  vector<Vertex> result = test.traversal(start);
  int length = result.size();
 
  REQUIRE(result[length - 1] == "0");
}

TEST_CASE(" Test Graph with Cycle - Traversal ", "[weight=1]") {
  BFS test("BFS-tests/bfs_test_cycle.json");
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

TEST_CASE(" Test Graph with 2 Cycles - Traversal ", "[weight=1]") {
  BFS test("BFS-tests/bfs_test_cycle_complex.json");
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
  BFS test("BFS-tests/bfs_test_graph.json");
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
  BFS test("BFS-tests/bfs_test_component.json");
  Vertex start = to_string(0);
  vector<vector<Vertex>> result = test.connectedComp();
  
  vector<vector<Vertex>> expected;
  vector<Vertex> expected1;
  expected1.push_back("2");
  expected1.push_back("1");
  expected1.push_back("0");
  //sort(expected1.begin(), expected1.end());

  vector<Vertex> expected2;
  expected2.push_back("4");
  expected2.push_back("3");
  //sort(expected2.begin(), expected2.end());

  expected.push_back(expected2);
  expected.push_back(expected1);
  
  REQUIRE(result.size() == expected.size());
  REQUIRE(result == expected);
} 


TEST_CASE(" Test Different Components Complex Graph - Traversal ", "[weight=2]") {
  BFS test("BFS-tests/bfs_test_component_complex.json");
  Vertex start = to_string(2);
  vector<vector<Vertex>> result = test.connectedComp();
  
  vector<vector<Vertex>> expected;
  vector<Vertex> expected1;
  expected1.push_back("1");
  expected1.push_back("0");
  //sort(expected1.begin(), expected1.end());

  vector<Vertex> expected2;
  expected2.push_back("4");
  expected2.push_back("5");
  expected2.push_back("3");
  expected2.push_back("2");
  //sort(expected2.begin(), expected2.end());

  expected.push_back(expected2);
  expected.push_back(expected1);
  
  REQUIRE(result.size() == expected.size());
  REQUIRE(result == expected);
} 