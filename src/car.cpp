#include "car.hpp"
#include <fstream>
#include <iostream>
#include <json/json.h>

Car::Car(const std::string &_name) : name(_name) {}
Car::Car() : Car("N/A") {}

Car Car::FromFile(std::string path) {
  Json::Value root;
  std::ifstream config_doc(path, std::ifstream::binary);
  config_doc >> root;
  std::string name = root.get("carName", "FAIL").asString();
  if (name == "FAIL") {
    throw CarException("carName parameter not found");
  }
  return Car(name);
}
void Car::printInfo() const{
  std::cout << "Car 1.2 " << name << " status: " << status << '\n';
}
void Car::start() { status = "running"; }