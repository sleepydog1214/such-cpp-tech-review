#ifndef REVIEW_HPP
#define REVIEW_HPP

// Parent class
class Review {
  public:
    Review();

    virtual void start() = 0;
    virtual void test() = 0;
    virtual void end() = 0;

    ~Review();
};

#endif
