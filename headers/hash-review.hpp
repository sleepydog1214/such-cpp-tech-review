#ifndef HASH_REVIEW_HPP
#define HASH_REVIEW_HPP

#include "review.hpp"

class HashReview: public Review {
  public:
    HashReview();

    void start();
    void test();
    void end();

    ~HashReview();
};

#endif
