#ifndef IO_REVIEW_HPP
#define IO_REVIEW_HPP

#include "review.hpp"

class IOReview: public Review {
  public:
    IOReview();

    void start();
    void test();
    void end();

    ~IOReview();
};

#endif
