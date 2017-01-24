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
};

#endif
