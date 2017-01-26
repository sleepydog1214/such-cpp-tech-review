#include "algo-review.hpp"

#include <iostream>

//*****************************************************************************
//*****************************************************************************
void AlgoReview::start() {
  printData();
}

//*****************************************************************************
//*****************************************************************************
void AlgoReview::test() {
  int a = getRandInt(1, 1000);
  int b = getRandInt(1000, 2000);
  int r = euclid_gcd1(a, b);
  std::cout << "gcd(" << a << "," << b << ")" << " = " << r << std::endl;
  initValue++;

  a = getRandInt(-1000, 1000);
  b = getRandInt(1000, 3000);
  r = euclid_gcd2(a, b);
  std::cout << "gcd(" << a << "," << b << ")" << " = " << r << std::endl;
  initValue++;

  a = getRandInt(4000, 7000);
  b = getRandInt(1000, 4000);
  r = binary_gcd(a, b);
  std::cout << "gcd(" << a << "," << b << ")" << " = " << r << std::endl;
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void AlgoReview::end() {
  printResults();
}

//*****************************************************************************
//*****************************************************************************
int AlgoReview::euclid_gcd1(int a, int b) {
  if (a == b)
    return a;
  else if (a > b)
    return euclid_gcd1(a - b, b);
  else
    return euclid_gcd1(a, b - a);
}

//*****************************************************************************
//*****************************************************************************
int AlgoReview::euclid_gcd2(int a, int b) {
  if (b == 0)
    return a;
  else
    return euclid_gcd2(b, a % b);
}

//*****************************************************************************
//*****************************************************************************
int AlgoReview::binary_gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;

  // Set shift as the greatest power of 2 dividing both a and b
  int shift;
  for (shift = 0; ((a | b) & 1) == 0; shift++) {
    a >>= 1;
    b >>= 1;
  }

  // divide a by 2 until a is odd
  while ((a & 1) == 0)
    a >>= 1;

  while (b != 0) {
    //divide b by 2 until odd
    while ((b & 1) == 0)
      b >>= 1;

    // now both a and b are odd. Swap if necessary so a <= b, then set
    // b = b - a, which is even
    if (a > b) {
      int t = b;
      b = a;
      a = t;
    }
    b = b - a;
  }

  // restore the common factors of 2
  return a << shift;
}
