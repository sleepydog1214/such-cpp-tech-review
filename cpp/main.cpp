#include <iostream>
#include <vector>
using namespace std;

#include "review.hpp"
#include "instance-list.hpp"

int main() {
  ReviewList aList;
  //Review **instanceArr = aList.getList();
  vector<Review *> instanceArr = aList.getList();

  for (int i = 0; i < 6; i++) {
    instanceArr[i]->start();
    instanceArr[i]->test();
    instanceArr[i]->end();
  }

  return 0;
}
