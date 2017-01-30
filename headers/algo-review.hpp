#ifndef ALGO_REVIEW_HPP
#define ALGO_REVIEW_HPP

#include "review.hpp"
#include <string>
#include <vector>

class AlgoReview: public Review {
  public:
    AlgoReview() {}
    AlgoReview(std::string a, int b, int c) : Review(a, b, c) {}

    void start();
    void test();
    void end();

    ~AlgoReview() {}

  private:
    std::vector<void (AlgoReview::*)()> tests;

    void test1();
    void test2();
    void test3();
    void test4();
    void test5();

    int euclid_gcd1(int a, int b);
    int euclid_gcd2(int a, int b);
    int binary_gcd(int a, int b);
    std::vector<int> fibonacci(int n);
    std::vector<int> eratosthenes(int n);
};

#endif
