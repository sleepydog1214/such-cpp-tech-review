#ifndef INSTANCE_LIST_HPP
#define INSTANCE_LIST_HPP

#include "review.hpp"
#include "algo-review.hpp"
#include "hash-review.hpp"
#include "io-review.hpp"
#include "list-review.hpp"
#include "string-review.hpp"
#include "tree-review.hpp"

#include <vector>
using namespace std;

class ReviewList {
  public:
    ReviewList();
    //Review** getList();
    vector<Review *> & getList();

    ~ReviewList();

  private:
    //Review **instanceList;
    vector<Review *> instanceList;

    AlgoReview   *algoReview;
    HashReview   *hashReview;
    IOReview     *ioReview;
    ListReview   *listReview;
    StringReview *stringReview;
    TreeReview   *treeReview;
};

#endif
