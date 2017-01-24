#ifndef STRING_REVIEW_HPP
#define STRING_REVIEW_HPP

#include "review.hpp"

class StringReview: public Review {
  public:
    StringReview() {}
    StringReview(std::string a, int b, int c) : Review(a, b, c) {}

    void start();
    void test();
    void end();

    ~StringReview() {}
};

#endif
