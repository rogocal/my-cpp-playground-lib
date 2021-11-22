#pragma once
#include <exception>
#include <string>

/**
 * @brief Car exceptions
 *
 */
class CarException : public std::exception {
public:
  explicit CarException(const std::string &msg) : m_msg(msg) {}
  ~CarException() = default;
  virtual const char *what() const throw() { return m_msg.c_str(); }
  const std::string m_msg;
};

/**
 * @brief Car class, handle all cars
 *
 */
class Car {
public:
  Car();
  explicit Car(const std::string &_name);
  static Car FromFile(std::string path);
  void printInfo() const;
  void start();

  std::string getName() const { return name; }

private:
  const std::string name;
  std::string status{"stopped"};
};
