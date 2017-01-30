#ifndef HASH_REVIEW_HPP
#define HASH_REVIEW_HPP

#include "review.hpp"
#include <vector>
#include <string>
#include <map>

template <class T> class HashTable {
  public:
    HashTable() : tableSize(0), tableSizePrime(0) {}
    HashTable(int size);
    ~HashTable() { }

    int insert(T& value);
    T& find(int key);
    int find(T& value);
    void remove(int key);
    void remove(T& value);
    int length() { return tableSize; }
    int count() { return tableCount; }
    void dumpTable();

  private:
    std::vector<T> table;
    int tableSize;
    int tableSizePrime;
    int tableRehashSize;
    int tableCount;
    std::map<std::string, int> primeMap;

    int h1(int k) { return k % tableSize; }
    int h2(int k) { return 1 + (k % tableSizePrime); }

    void rehash();
    int getIntVal(T& value);
    void getLargestPrimes(int n);
};

class HashReview: public Review {
  public:
    HashReview() {}
    HashReview(std::string a, int b, int c) : Review(a, b, c) {}

    void start();
    void test();
    void end();

    ~HashReview() { delete testTable; }

  private:
    std::vector<void (HashReview::*)()> tests;
    HashTable<std::string> *testTable;
    std::vector<std::string> values;
    std::vector<int> keys;

    void test1();
    void test2();
    void test3();
    void test4();
};

#endif
