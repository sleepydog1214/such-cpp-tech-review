#ifndef LIST_REVIEW_HPP
#define LIST_REVIEW_HPP

#include "review.hpp"

class ListReview: public Review {
  public:
    ListReview() {}
    ListReview(std::string a, int b, int c) : Review(a, b, c) {}

    void start();
    void test();
    void end();

    ~ListReview() {}
};

#endif
