#ifndef INSTANCE_LIST_HPP
#define INSTANCE_LIST_HPP

#include "review.hpp"
#include "algo-review.hpp"
#include "hash-review.hpp"
#include "io-review.hpp"
#include "list-review.hpp"
#include "string-review.hpp"
#include "tree-review.hpp"
#include "parse-json.hpp"

#include <vector>

class ReviewList {
  public:
    ReviewList();

    std::vector<Review *> & getList() { return instanceList; }

    ~ReviewList();

  private:
    // Initialize each review instance
    ParseJSON jsonFile;

    std::vector<Review *> instanceList;

    AlgoReview   *algoReview;
    HashReview   *hashReview;
    IOReview     *ioReview;
    ListReview   *listReview;
    StringReview *stringReview;
    TreeReview   *treeReview;

    void setInitValues(DataVector& v, std::string& s, int& a, int& b);
};

#endif
