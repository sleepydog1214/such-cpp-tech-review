#ifndef STRING_REVIEW_HPP
#define STRING_REVIEW_HPP

#include "review.hpp"

class StringReview: public Review {
  public:
    StringReview();

    void start();
    void test();
    void end();

    ~StringReview();
};

#endif
