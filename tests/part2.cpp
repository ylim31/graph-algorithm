#include "catch.hpp"

#include "../landmark.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;


TEST_CASE("landmark baby 1", "[weight=1]") {
  //INITIALIZING LANDMARK WITH BABY FILE USE test AS VARIABLE
  LandMark test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = to_string(0);
  Vertex landmark = to_string(1);
  Vertex end = to_string(4);
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("1"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("1"));
  expected.push_back(Vertex("4"));
  REQUIRE(result == expected);
}

TEST_CASE("landmark baby 2", "[weight=1]") {
  //INITIALIZING LANDMARK WITH BABY FILE USE test AS VARIABLE
  LandMark test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(2);
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

TEST_CASE("landmark baby 3", "[weight=1]") {
  //INITIALIZING LANDMARK WITH BABY FILE USE test AS VARIABLE
  LandMark test("tests_folder/dijkstra_baby_test.json", "tests_folder/dijkstra_baby_target.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(2);
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("4"));
  //landmark_vector.push_back(to_string(1));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("3"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("2"));
  REQUIRE(result == expected);
}

TEST_CASE("landmark baby 4", "[weight=1]") {
  //INITIALIZING LANDMARK WITH BABY FILE USE test AS VARIABLE
  LandMark test("tests_folder/landmark_baby.json", "tests_folder/landmark_baby_target.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(5);
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex"2");
  //landmark_vector.push_back(to_string(1));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  expected.push_back(Vertex("0"));
  expected.push_back(Vertex("2"));
  expected.push_back(Vertex("4"));
  expected.push_back(Vertex("5"));
  REQUIRE(result == expected);
}

TEST_CASE("landmark to itself", "[weight=1]") {
  //INITIALIZING LANDMARK WITH BABY FILE USE test AS VARIABLE
  LandMark test("tests_folder/landmark_baby.json", "tests_folder/landmark_baby_target.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(0);
  vector<Vertex> landmark_vector;
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("2", "[weight=1]") {
  LandMark test("tests_folder/dijkstra_baby_test2.json", "tests_folder/dijkstra_baby_target2.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(5);
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("4"));
  landmark_vector.push_back(Vertex("1"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

TEST_CASE("23", "[weight=1]") {
  LandMark test("tests_folder/dijkstra_baby_test2.json", "tests_folder/dijkstra_baby_target2.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(5);
  vector<Vertex> landmark_vector;
  landmark_vector.push_back(Vertex("1"));
  landmark_vector.push_back(Vertex("2"));
  landmark_vector.push_back(Vertex("4"));
  vector<Vertex> result = test.find_shortest_path(start, end,landmark_vector);
  vector<Vertex> expected;
  REQUIRE(result == expected);
}

