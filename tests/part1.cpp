#define CATCH_CONFIG_MAIN
#include "catch.hpp"


#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "../dijkstra.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("baby find shortest path 1", "[weight=1]") {
  Dijkstra test("d_baby_test_node.csv", "d_baby_test_neighbor.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(3);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    //cout << result[i] << endl;
  }
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
}

TEST_CASE("baby find shortest path on itself", "[weight=1]") {
  Dijkstra test("d_baby_test_node.csv", "d_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  Vertex end = to_string(2);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    //cout << result[i] << endl;
  }
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("baby find shortest path 2", "[weight=1]") {
  Dijkstra test("d_baby_test_node.csv", "d_baby_test_neighbor.csv");
  Vertex start = to_string(3);
  Vertex end = to_string(2);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    //cout << result[i] << endl;
  }
  vector<Vertex> expected;
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
}


TEST_CASE("example", "[weight=1]") {
  
  Dijkstra test("lastfm_node.csv", "lastfm_neighbor.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(3);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    //cout << result[i] << endl;
  }
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("2", "[weight=1]") {
  
  Dijkstra test("different_component.csv", "different_component_neighbor.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(2);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    //cout << result[i] << endl;
  }
  vector<Vertex> expected;
  REQUIRE(result == expected);
}


TEST_CASE("23", "[weight=1]") {
  
  Dijkstra test("t.csv", "tn.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(3);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    //cout << result[i] << endl;
  }
  vector<Vertex> expected;
  REQUIRE(result == expected);
}