#include "catch.hpp"

#include "../landmark.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("Landmark to itself", "[part2]") {
  LandMark test("tests_folder/landmark_baby.json", "tests_folder/landmark_baby_target.csv");
  Vertex start = Vertex("0");
  Vertex end = Vertex("0");
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("1"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("0"));
  REQUIRE(result == expected);
}

TEST_CASE("Test invalid landmark", "[part2]") {
  //When the the landmark vertex is not in the graph
  LandMark test("tests_folder/landmark_baby.json", "tests_folder/landmark_baby_target.csv");
  Vertex start = Vertex("0");
  Vertex end = Vertex("3");
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("90"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("Test landmark baby", "[part2]") {
  LandMark test("tests_folder/landmark_baby.json", "tests_folder/landmark_baby_target.csv");
  Vertex start = Vertex("0");
  Vertex end = Vertex("5");
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("2"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("5"));
  REQUIRE(result == expected);
}

TEST_CASE("Test landmark baby 2", "[part2]") {
  LandMark test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = Vertex("0");
  Vertex end = Vertex("2");
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("3"));
  landmark_vector.push_back(Vertex("1"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
}

TEST_CASE("Test landmark baby 3", "[part2]") {
  LandMark test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = Vertex("0");
  Vertex end = Vertex("2");
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("4"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
}

TEST_CASE("Test landmark test medium", "[part2]") {
  LandMark test("tests_folder/dijkstra_baby_test2.json", "tests_folder/dijkstra_baby_target2.csv");
  Vertex start = Vertex("0");
  Vertex end = Vertex("5");
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("4"));
  landmark_vector.push_back(Vertex("1"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("5"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("5"));
  REQUIRE(result == expected);
}

TEST_CASE("Test landmark test medium 2", "[part2]") {
  //Three landmark vertices. Correctly finds the shortest path that visits all of them.
  LandMark test("tests_folder/dijkstra_baby_test2.json", "tests_folder/dijkstra_baby_target2.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(5);
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("1"));
  landmark_vector.push_back(Vertex("2"));
  landmark_vector.push_back(Vertex("4"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("5"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("5"));
  REQUIRE(result == expected);
}

TEST_CASE("landmark test large", "[weight=1]") {
  LandMark test("lastfm_asia_features.json", "lastfm_asia_target.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(4);
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("3"));
  landmark_vector.push_back(Vertex("2"));

  vector<Vertex> result = test.find_shortest_path(start, end, landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("1209"));
  expected.push_back(Vertex("1262"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("1951"));
  expected.push_back(Vertex("1462"));
  expected.push_back(Vertex("1362"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("1118"));
  expected.push_back(Vertex("1079"));
  expected.push_back(Vertex("4"));
  REQUIRE(result == expected);
}

