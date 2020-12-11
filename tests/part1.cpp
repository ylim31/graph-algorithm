#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../dijkstra.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("Find shortest path on itself", "[part1]") {
  Dijkstra test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = to_string(2);
  Vertex end = to_string(2);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
}

TEST_CASE("Test invalid start", "[part1]") {
  //When the start vertex is not in the graph
  Dijkstra g("tests_folder/dijkstra_baby_test2.json", "tests_folder/dijkstra_baby_target2.csv");
  Vertex start = to_string(10);
  Vertex end = to_string(3);
  vector<Vertex> result = g.find_shortest_path(start, end);
  vector<Vertex> expected;
  REQUIRE(result == expected);
} 

TEST_CASE("Test invalid end", "[part1]") {
  //When the end vertex is not in the graph
  Dijkstra g("tests_folder/dijkstra_baby_test2.json", "tests_folder/dijkstra_baby_target2.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(19);
  vector<Vertex> result = g.find_shortest_path(start, end);
  vector<Vertex> expected;
  REQUIRE(result == expected);
} 

TEST_CASE("Test disconnected graph", "[part1]") {
  //If the start and end is in different component of the graph
  Dijkstra test("tests_folder/dijkstra_disconnected_test.json", "tests_folder/dijkstra_disconnected_target.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(4);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("Find shortest path 1", "[part1]") {
  Dijkstra test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(2);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
}

TEST_CASE("Find shortest path 2", "[part1]") {
  Dijkstra test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = to_string(4);
  Vertex end = to_string(0);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("0"));
  REQUIRE(result == expected);
}

TEST_CASE("Find shortest path 3", "[part1]") {
  //Check if the algorthirm correctly chooses the path that visits more nodes with shorter weight rather than path that visits less nodes with higher weight.
  Dijkstra g("tests_folder/dijkstra_baby_test2.json", "tests_folder/dijkstra_baby_target2.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(3);
  vector<Vertex> result = g.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("5"));
  expected.push_back(Vertex("3"));
  REQUIRE(result == expected);
} 

TEST_CASE("Find shortest path letter graph", "[part1]") {
  //Test on graph with letters as vertex
  Dijkstra g("tests_folder/dijkstra_baby_test3.json", "tests_folder/dijkstra_baby_target3.csv");
  Vertex start = "A";
  Vertex end = "D";
  vector<Vertex> result = g.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back(Vertex("A"));
  expected.push_back(Vertex("B"));
  expected.push_back(Vertex("C"));
  expected.push_back(Vertex("D"));
  REQUIRE(result == expected);
} 

TEST_CASE("Find shortest path large", "[part1]") {
  //Find the shortest path on our chosen dataset
  Dijkstra test("lastfm_asia_features.json", "lastfm_asia_target.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(2);
  vector<Vertex> result = test.find_shortest_path(start, end);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("1209"));
  expected.push_back(Vertex("1262"));
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
} 









