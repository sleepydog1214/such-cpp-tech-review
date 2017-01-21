#ifndef TREE_REVIEW_HPP
#define TREE_REVIEW_HPP

#include "review.hpp"

class TreeReview: public Review {
  public:
    TreeReview();

    void start();
    void test();
    void end();

    ~TreeReview();
};

#endif
