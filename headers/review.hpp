#ifndef REVIEW_HPP
#define REVIEW_HPP

#include <string>

// Parent class
class Review {
  public:
    Review() {}
    Review(std::string a, int b, int c) : title(a), initValue(b),
      checkValue(c) {}

    virtual void start() = 0;
    virtual void test() = 0;
    virtual void end() = 0;

    virtual ~Review() {}

  protected:
    std::string title;
    int initValue;
    int checkValue;

    void printData();
};

#endif
