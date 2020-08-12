#include <iostream>
#include <string>


std::string greet(std::string name) {
  std::cout << "C++: greet()" << std::endl;
  return "Hello " + name;
}

double add(double arg0, double arg1) {
  std::cout << "C++: add()" << std::endl;
  return arg0 + arg1;
}
