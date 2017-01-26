#ifndef ALGO_REVIEW_HPP
#define ALGO_REVIEW_HPP

#include "review.hpp"
#include <string>

class AlgoReview: public Review {
  public:
    AlgoReview() {}
    AlgoReview(std::string a, int b, int c) : Review(a, b, c) {}

    void start();
    void test();
    void end();

    ~AlgoReview() {}

  private:
    int euclid_gcd1(int a, int b);
    int euclid_gcd2(int a, int b);
    int binary_gcd(int a, int b);
};

#endif
