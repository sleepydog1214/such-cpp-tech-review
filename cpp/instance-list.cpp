#include <iostream>
#include <vector>
#include <cstdlib>

#include "review.hpp"
#include "instance-list.hpp"
#include "json-data-structures.hpp"

//*****************************************************************************
// Constructor() - get data from the JSON file and initialize each review
//*****************************************************************************
ReviewList::ReviewList() {
  // Need to read JSON file to initialize each review instance-list
  jsonFile.readJSON();
  MainJSONMap data = jsonFile.getData();

  //iterate through the parsed JSON data to initialize the reviews
  MainJSONVector jvect = data["reviewList"];

  for (std::size_t i = 0; i < jvect.size(); i++) {
    DataMap imap = jvect[i];
    std::string reviewTitle = imap.key();

    // Now loop through the inner vector
    DataVector r_vect = imap.value();

    std::string init_string;
    int init_value;
    int check_value;
    setInitValues(r_vect, init_string, init_value, check_value);

    if (reviewTitle == "algo-review") {
      algoReview = new AlgoReview(init_string, init_value, check_value);
    }
    else if (reviewTitle == "hash-review") {
      hashReview = new HashReview(init_string, init_value, check_value);
    }
    else if (reviewTitle == "io-review") {
      ioReview = new IOReview(init_string, init_value, check_value);
    }
    else if (reviewTitle == "list-review") {
      listReview = new ListReview(init_string, init_value, check_value);
    }
    else if (reviewTitle == "string-review") {
      stringReview = new StringReview(init_string, init_value, check_value);
    }
    else if (reviewTitle == "tree-review") {
      treeReview = new TreeReview(init_string, init_value, check_value);
    }
  }

  instanceList.push_back(static_cast<Review *>(algoReview));
  instanceList.push_back(static_cast<Review *>(hashReview));
  instanceList.push_back(static_cast<Review *>(ioReview));
  instanceList.push_back(static_cast<Review *>(listReview));
  instanceList.push_back(static_cast<Review *>(stringReview));
  instanceList.push_back(static_cast<Review *>(treeReview));
}

//*****************************************************************************
// Read the initialization values from the JSON data
//*****************************************************************************
void ReviewList::setInitValues(DataVector& v, std::string& s, int& a, int& b) {
  for (std::size_t i = 0; i < v.size(); i++) {
    DataPairMap t_map = v[i];

    switch (i) {
      case 0:
        a = atoi(t_map["init-value"].c_str());
        break;
      case 1:
        s = t_map["init-string"];
        break;
      case 2:
        b = atoi(t_map["check-value"].c_str());
        break;
    }
  }
}

//*****************************************************************************
// Destructor - free review memory
//*****************************************************************************
ReviewList::~ReviewList() {
  instanceList.erase(instanceList.begin());

  delete algoReview;
  delete hashReview;
  delete ioReview;
  delete listReview;
  delete stringReview;
  delete treeReview;
}
