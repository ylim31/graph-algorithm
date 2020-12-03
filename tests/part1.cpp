#define CATCH_CONFIG_MAIN
#include "catch.hpp"


#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "../dijkstra.h"
#include <vector>
#include <iostream>

using namespace std;

#include <iostream>
#include <string>

using namespace std;


TEST_CASE("example", "[weight=1]") {
  
  Dijkstra test("lastfm_node.csv", "lastfm_neighbor.csv");
  Vertex start = to_string(0);
  Vertex end = to_string(4557);
  vector<Vertex> result = test.find_shortest_path(start, end);
  for (unsigned i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }
  vector<Vertex> expected;
  REQUIRE(result == expected);
}