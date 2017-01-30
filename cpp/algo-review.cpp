#include "algo-review.hpp"

#include <iostream>
#include <vector>

//*****************************************************************************
//*****************************************************************************
void AlgoReview::start() {
  printData();

  // build a vector of pointers to each test function
  tests.push_back(&AlgoReview::test1);
  tests.push_back(&AlgoReview::test2);
  tests.push_back(&AlgoReview::test3);
  tests.push_back(&AlgoReview::test4);
  tests.push_back(&AlgoReview::test5);
}

//*****************************************************************************
//*****************************************************************************
void AlgoReview::test() {
  std::vector<void (AlgoReview::*)()>::iterator it = tests.begin();
  for( ; it < tests.end(); it++) {
    void (AlgoReview::* f)() = *it;
    (this->*f)();
  }
}

//*****************************************************************************
//*****************************************************************************
void AlgoReview::test1() {
  int a = getRandInt(1, 1000);
  int b = getRandInt(1000, 2000);
  int r = euclid_gcd1(a, b);
  std::cout << "euclid gcd 1(" << a << "," << b << ")" << " = " << r << std::endl;
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void AlgoReview::test2() {
  int a = getRandInt(-1000, 1000);
  int b = getRandInt(1000, 3000);
  int r = euclid_gcd2(a, b);
  std::cout << "euclid gcd 2(" << a << "," << b << ")" << " = " << r << std::endl;
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void AlgoReview::test3() {
  int a = getRandInt(4000, 7000);
  int b = getRandInt(1000, 4000);
  int r = binary_gcd(a, b);
  std::cout << "binary gcd(" << a << "," << b << ")" << " = " << r << std::endl;
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void AlgoReview::test4() {
  int a = getRandInt(20, 40); // avoid going past INT_MAX
  std::vector<int> v = fibonacci(a);
  std::cout << "fibonacci sequence to " << a << ": " << std::endl;
  std::vector<int>::iterator it = v.begin();
  for(; it != v.end(); it++) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void AlgoReview::test5() {
  int n = getRandInt(1000, 3000);
  std::vector<int> v = eratosthenes(n);
  std::cout << "All primes to " << n << ": " << std::endl;
  std::vector<int>::iterator it = v.begin();
  for(; it != v.end(); it++) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;
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

//*****************************************************************************
//*****************************************************************************
std::vector<int> AlgoReview::fibonacci(int n) {
  std::vector<int> sequence;

  if (n < 0) return sequence;

  sequence.push_back(1);
  sequence.push_back(1);

  if (n == 1) return sequence;

  for (int i = 2; i <= n; i++) {
    int j = sequence[i - 2];
    int k = sequence[i - 1];
    sequence.push_back(j + k);
  }

  return sequence;
}

//*****************************************************************************
//*****************************************************************************
std::vector<int> AlgoReview::eratosthenes(int n) {
  std::vector<bool> arr (n + 1, true);
  std::vector<int> results;

  for (int i = 2; i * i <= n; i++) {
    if (arr[i]){
      for (int j = i * i; j < n; j += i) {
        arr[j] = false;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (arr[i])
      results.push_back(i);
  }

  return results;
}
