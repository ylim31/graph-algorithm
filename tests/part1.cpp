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
  Vertex end = to_string(1);
  test.g_.setEdgeWeight(to_string(0),to_string(1),6);
  test.g_.setEdgeWeight(to_string(0),to_string(3),1);
  test.g_.setEdgeWeight(to_string(1),to_string(3),2);
  test.g_.setEdgeWeight(to_string(1),to_string(4),2);
  test.g_.setEdgeWeight(to_string(1),to_string(2),5);
  test.g_.setEdgeWeight(to_string(2),to_string(4),5);
  test.g_.setEdgeWeight(to_string(3),to_string(4),1);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("1"));
  REQUIRE(result == expected);
}

TEST_CASE("baby find shortest path on itself", "[weight=1]") {
  Dijkstra test("d_baby_test_node.csv", "d_baby_test_neighbor.csv");
  Vertex start = to_string(2);
  Vertex end = to_string(2);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("baby find shortest path 2", "[weight=1]") {
  Dijkstra test("d_baby_test_node.csv", "d_baby_test_neighbor.csv");
  Vertex start = to_string(3);
  Vertex end = to_string(2);
  test.g_.setEdgeWeight(to_string(0),to_string(1),6);
  test.g_.setEdgeWeight(to_string(0),to_string(3),1);
  test.g_.setEdgeWeight(to_string(1),to_string(3),2);
  test.g_.setEdgeWeight(to_string(1),to_string(4),2);
  test.g_.setEdgeWeight(to_string(1),to_string(2),5);
  test.g_.setEdgeWeight(to_string(2),to_string(4),5);
  test.g_.setEdgeWeight(to_string(3),to_string(4),1);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
}

TEST_CASE("lastfm shortest path to itself", "[weight=1]") {
  
  Dijkstra test("lastfm_node.csv", "lastfm_neighbor.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(0);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("shortest path baby 1 (landmark)", "[weight=1]") {
  //INITIALIZING LANDMARK WITH BABY FILE USE test AS VARIABLE
  Vertex start = to_string(0);
  Vertex landmark = to_string(1);
  Vertex end = to_string(2);
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
  expected.push_back("2");
  //REQUIRE(result == expected);
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


TEST_CASE("example", "[weight=1]") {
  Dijkstra test("lastfm_node.csv", "lastfm_neighbor.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(3);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("2", "[weight=1]") {
  Dijkstra test("different_component.csv", "different_component_neighbor.csv");
  Vertex start = to_string(1);
  Vertex end = to_string(4);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
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
    cout << result[i] << endl;
  }
  vector<Vertex> expected;
  REQUIRE(result == expected);
} 