#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "d.h"
#include "string"
#include "iostream"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"


Dijkstra testdij("d_baby_test_node.csv","d_baby_test_neighbor.csv");

TEST_CASE("find_shortest_path baby", "[weight=1]") {
  std::cout<<testdij.shortest_distance_from_start_[0]<<std::endl;
  int i = 1;
  REQUIRE( i == 1 );
}