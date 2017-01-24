#ifndef HASH_REVIEW_HPP
#define HASH_REVIEW_HPP

#include "review.hpp"

class HashReview: public Review {
  public:
    HashReview() {}
    HashReview(std::string a, int b, int c) : Review(a, b, c) {}

    void start();
    void test();
    void end();

    ~HashReview() {}
};

#endif
