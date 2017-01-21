#include <iostream>
using namespace std;

#include "review.hpp"
#include "instance-list.hpp"

ReviewList::ReviewList() {
    algoReview   = new AlgoReview;
    hashReview   = new HashReview;
    ioReview     = new IOReview;
    listReview   = new ListReview;
    stringReview = new StringReview;
    treeReview   = new TreeReview;

  instanceList.push_back(algoReview);
  instanceList.push_back(static_cast<Review *>(hashReview));
}

vector<Review *> & ReviewList::getList() {
  return instanceList;
}

ReviewList::~ReviewList() {
  instanceList.erase(instanceList.begin());

  delete algoReview;
  delete hashReview;
  delete ioReview;
  delete listReview;
  delete stringReview;
  delete treeReview;
}
