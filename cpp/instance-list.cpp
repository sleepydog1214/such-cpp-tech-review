#include <iostream>
#include <vector>

#include "review.hpp"
#include "instance-list.hpp"
#include "json-data-structures.hpp"

ReviewList::ReviewList() {
  // Need to read JSON file to initialize each review instance-list
  jsonFile.readJSON();
  MainJSONMap data = jsonFile.getData();

  //iterate through the parsed JSON data to initialize the reviews
  MainJSONVector jvect = data["reviewList"];

  for (std::size_t i = 0; i < jvect.size(); i++) {
    DataMap imap = jvect[i];
    std::string reviewTitle = imap.key();

    std::cout << "json: " << reviewTitle << std::endl;

    // Now loop through the inner vector
    DataVector r_vect = imap.value();

    std::string init_value;
    std::string init_string;
    std::string check_value;
    for (std::size_t j = 0; j < r_vect.size(); j++) {
      DataPairMap t_map = r_vect[j];

      switch (j) {
        case 0:
          init_value = t_map["init-value"];
          break;
        case 1:
          init_string = t_map["init-string"];
          break;
        case 2:
          check_value = t_map["check-value"];
          break;
      }
    }
    std::cout << " " << init_value << " " << init_string << " " <<
        check_value << std::endl;
  }

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
