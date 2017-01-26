#include "review.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

//*****************************************************************************
//*****************************************************************************
void Review::printData() {
  std::cout << "review title: " << title << std::endl;
  std::cout << "init value: " << initValue << std::endl;
  std::cout << "check value: " << checkValue << std::endl;
}

//*****************************************************************************
//*****************************************************************************
void Review::printResults() {
  if (initValue == checkValue)
    std::cout << "PASSED: " << title << std::endl;
  else {
    std::cout << "FAILED: " << title << std::endl;
    std::cout << "\tinitValue = " << initValue << ", should be "
              << checkValue << std::endl;
  }
}

//*****************************************************************************
//*****************************************************************************
int Review::getRandInt(int min, int max) {
  srand(time(NULL));

  double x = static_cast<double>(min);
  double y = static_cast<double>(max);
  double z;

  int r1 = rand();
  int r2 = rand();

  double tmp1 = static_cast<double>(r1);
  double tmp2 = static_cast<double>(r2);

  if (r1 > r2) {
    z = (tmp1 - tmp2) / tmp1;
  }
  else {
    z = (tmp2 - tmp1) / tmp2;
  }

  z = floor((z * (y - x + 1.0)) + min);

  return static_cast<int>(z);
}
