#ifndef ALGO_REVIEW_HPP
#define ALGO_REVIEW_HPP

#include "review.hpp"

class AlgoReview: public Review {
  public:
    AlgoReview();

    void start();
    void test();
    void end();

    ~AlgoReview();
};

#endif
