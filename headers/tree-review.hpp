#ifndef TREE_REVIEW_HPP
#define TREE_REVIEW_HPP

#include "review.hpp"

class TreeReview: public Review {
  public:
    TreeReview() {}
    TreeReview(std::string a, int b, int c) : Review(a, b, c) {}

    void start();
    void test();
    void end();

    ~TreeReview() {}
};

#endif
