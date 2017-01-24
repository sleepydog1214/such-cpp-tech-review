#include "review.hpp"
#include <iostream>

void Review::printData() {
  std::cout << "review title: " << title << std::endl;
  std::cout << "init value: " << initValue << std::endl;
  std::cout << "check value: " << checkValue << std::endl;
}
