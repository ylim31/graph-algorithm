#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "string"
#include "iostream"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

TEST_CASE(" Test 1 ", "[weight=1]") {
  int i = 3;
  REQUIRE( i == 3 );
}

TEST_CASE(" Test 2 ", "[weight=2]") {
  int i = 6;
  REQUIRE( i == 6 );
}

TEST_CASE(" Test 3 ", "[weight=3]") {
  int i = 9;
  REQUIRE( i == 9 );
}
