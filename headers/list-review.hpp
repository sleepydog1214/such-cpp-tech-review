#ifndef LIST_REVIEW_HPP
#define LIST_REVIEW_HPP

#include "review.hpp"

class ListReview: public Review {
  public:
    ListReview();

    void start();
    void test();
    void end();

    ~ListReview();
};

#endif
