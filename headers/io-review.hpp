#ifndef IO_REVIEW_HPP
#define IO_REVIEW_HPP

#include "review.hpp"

class IOReview: public Review {
  public:
    IOReview() {}
    IOReview(std::string a, int b, int c) : Review(a, b, c) {}

    void start();
    void test();
    void end();

    ~IOReview() {}
};

#endif
