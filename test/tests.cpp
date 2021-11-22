#include <catch2/catch.hpp>

#include "car.hpp"
TEST_CASE("Car nominal", "[Car]") {
  auto car = Car("TestCar");
  REQUIRE(car.getName() == "TestCar");
}

TEST_CASE("Car from file", "[Car]") {
  auto car = Car::FromFile("../../data/otherCar.json");
  REQUIRE(car.getName() == "Ford");
}