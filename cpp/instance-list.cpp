#include <vector>

#include "review.hpp"
#include "instance-list.hpp"

ReviewList::ReviewList() {
  // Need to read JSON file to initialize each review instance-list
  jsonFile.getJSON();
  std::map< std::string,
    std::vector< std::map< std::string,
      std::vector< std::map< std::string, std::string > > > > > data =
                                                    jsonFile.getData();

  //iterate through the parsed JSON data to initialize the reviews

  algoReview   = new AlgoReview;
  hashReview   = new HashReview;
  ioReview     = new IOReview;
  listReview   = new ListReview;
  stringReview = new StringReview;
  treeReview   = new TreeReview;

  instanceList.push_back(static_cast<Review *>(algoReview));
  instanceList.push_back(static_cast<Review *>(hashReview));
  instanceList.push_back(static_cast<Review *>(ioReview));
  instanceList.push_back(static_cast<Review *>(listReview));
  instanceList.push_back(static_cast<Review *>(stringReview));
  instanceList.push_back(static_cast<Review *>(treeReview));
}

  std::vector<Review *> & ReviewList::getList() {
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
