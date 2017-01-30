#include "hash-review.hpp"

#include <iostream>
#include <typeinfo>
#include <cmath>
#include <exception>

//*****************************************************************************
//*****************************************************************************
void HashReview::start() {
  printData();

  // build a vector of pointers to each test function
  tests.push_back(&HashReview::test1);
  tests.push_back(&HashReview::test2);
  tests.push_back(&HashReview::test3);
  tests.push_back(&HashReview::test4);
}

//*****************************************************************************
//*****************************************************************************
void HashReview::test() {
  std::vector<void (HashReview::*)()>::iterator it = tests.begin();
  for( ; it < tests.end(); it++) {
    void (HashReview::* f)() = *it;
    (this->*f)();
  }
}

//*****************************************************************************
//*****************************************************************************
void HashReview::test1() {
  std::cout << "hash table test1" << std::endl;

  int size = getRandInt(75, 150);
  testTable = new HashTable<std::string>(size);

  int tmp = size;
  for (int i = 0; i < tmp; i++) {
    std::string s;
    for (int j = 0; j < 5; j++) {
      char c = static_cast<char>(getRandInt(65,90));
      s.push_back(c);
      c = static_cast<char>(getRandInt(97,122));
      s.push_back(c);
    }
    values.push_back(s);
  }

  std::vector<std::string>::iterator it = values.begin();
  for ( ; it < values.end(); it++) {
    int key = testTable->insert(*it);
    std::cout << "insert into table: " << *it << " at key: " << key << std::endl;
  }
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void HashReview::test2() {
  std::cout << "hash table test2" << std::endl;

  std::vector<std::string>::iterator it = values.begin();
  for( ; it < values.end(); it++) {
    int k = testTable->find(*it);
    keys.push_back(k);
    std::cout << "found " << *it << " at key " << k << std::endl;
  }
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void HashReview::test3() {
  std::cout << "hash table test3" << std::endl;

  std::vector<int>::iterator it = keys.begin();
  for( ; it < keys.end(); it++) {
    std::string s = testTable->find(*it);
    std::cout << "found " << s << " at key " << *it << std::endl;
  }
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void HashReview::test4() {
  std::cout << "hash table test4" << std::endl;
  std::cout << "hash table size: " << testTable->length() << std::endl;
  std::cout << "hash table number of items: " << testTable->count() << std::endl;

  int l = values.size();
  int a = l >> 1;
  int b = l >> 2;
  int c = l >> 3;
  testTable->remove(values[a]);
  testTable->remove(values[b]);
  testTable->remove(values[c]);
  std::cout << "remove from table: " << values[a] << ", "
            << values[b] << ", " << values[c] << std::endl;
  std::cout << "hash table size: " << testTable->length() << std::endl;
  std::cout << "hash table number of items: " << testTable->count() << std::endl;

  std::vector<int>::iterator it = keys.begin();
  a = *it; it++;
  b = *it; it++;
  c = *it; it++;
  testTable->remove(a);
  testTable->remove(b);
  testTable->remove(c);
  std::cout << "remove from table: " << a << ", " << b << ", " << c << std::endl;
  std::cout << "hash table size: " << testTable->length() << std::endl;
  std::cout << "hash table number of items: " << testTable->count() << std::endl;

  testTable->dumpTable();
  initValue++;
}

//*****************************************************************************
//*****************************************************************************
void HashReview::end() {
  printResults();
}

//*****************************************************************************
//*****************************************************************************
template <class T> HashTable<T>::HashTable(int size) {
  getLargestPrimes(size);
  tableSize = primeMap["largest"];
  tableSizePrime = primeMap["next-largest"];
  tableRehashSize = static_cast<int>(floor(static_cast<double>(tableSize) * 0.7));
  tableCount = 0;
  table.resize(tableSize);
  std::cout << "create table of size: " << tableSize << std::endl;
}

//*****************************************************************************
//*****************************************************************************
template <class T> int HashTable<T>::insert(T& value) {
  // rehash if table is more than 70% full
  if (tableCount > tableRehashSize)
    rehash();

  //need to convert T value into an int
  int k = getIntVal(value);
  int try1 = h1(k);

  // if first hash location is empty, insert there
  if (table[try1].length() == 0) {
    table[try1] = value;
    tableCount++;
    return try1;
  }

  // otherwise, try h2 offsets
  else {
    int try2 = h2(k);
    int offset = try1 + try2;

    if (offset >= tableSize)
      offset = offset % tableSize;

    int count = 0;
    while (table[offset].length() != 0 && count < tableSize) {
      offset += try2;
      if (offset >= tableSize)
        offset = offset % tableSize;
      count++;
    }

    if (count < tableSize) {
      table[offset] = value;
      tableCount++;
      return offset;
    }
    else
      throw std::invalid_argument("Table error, cannot insert value");
  }
}

//*****************************************************************************
//*****************************************************************************
template <class T> T& HashTable<T>::find(int key) {
  if (key < 0 || key >= tableSize)
    throw std::invalid_argument("Invalid key to find");
  else
    return table[key];
}

//*****************************************************************************
//*****************************************************************************
template <class T> int HashTable<T>::find(T& value) {
  //need to convert T value into an int
  int k = getIntVal(value);
  int try1 = h1(k);

  // assume type T has a compare() routine that returns 0 when equal
  if (table[try1].length() != 0 && table[try1].compare(value) == 0)
     return try1;

  int try2 = h2(k);
  int offset = try1 + try2;

  if (offset >= tableSize)
    offset = offset % tableSize;

  int count = 0;
  while (count < tableSize) {
    if (table[offset].length() != 0 && table[offset].compare(value) == 0)
      return offset;

    offset += try2;
    if (offset >= tableSize)
        offset = offset % tableSize;
    count++;
  }

  return 0;
}

//*****************************************************************************
//*****************************************************************************
template <class T> void HashTable<T>::remove(int key) {
  if (key < 0 || key >= tableSize)
    throw std::invalid_argument("Invalid key to delete");
  else {
    T x; //assume creating an empty object of type T
    table[key] = x;
    tableCount--;
  }
}

//*****************************************************************************
//*****************************************************************************
template <class T> void HashTable<T>::remove(T& value) {
  int k = find(value);
  remove(k);
}

//*****************************************************************************
//*****************************************************************************
template <class T> void HashTable<T>::rehash() {
  // copy table elements to a temp table
  std::vector<T> tmpTable;
  typename std::vector<T>::iterator it = table.begin();
  for( ; it < table.end(); it++) {
    if (getIntVal(*it) != 0) {
      tmpTable.push_back(*it);
    }
  }

  // empty the hash table
  table.clear();

  //now double the size of the table
  getLargestPrimes(tableSize * 2);

  // reset the table values
  tableSize = primeMap["largest"];
  tableSizePrime = primeMap["next-largest"];
  tableRehashSize = static_cast<int>(floor(static_cast<double>(tableSize) * 0.7));
  tableCount = 0;
  table.resize(tableSize);

  // now rebuild table
  for (it = tmpTable.begin(); it < tmpTable.end(); it++) {
    insert(*it);
  }

  std::cout << "rehash table to size: " << tableSize << std::endl;
}

//*****************************************************************************
//*****************************************************************************
template <class T> int HashTable<T>::getIntVal(T& value){
  if (typeid(value) == typeid(std::string)) {
    int x = 0;
    for (unsigned int i = 0; i < value.length(); i++) {
      x += static_cast<int>(value[i]);
    }

    return x;
  }

  return 0;
}

//*****************************************************************************
//*****************************************************************************
template <class T> void HashTable<T>::getLargestPrimes(int n) {
  primeMap["largest"] = 0;
  primeMap["next-largest"] = 0;

  std::vector<bool> arr(n, true);

  for (int i = 2; i * i < n; i++) {
    if (arr[i]) {
      for (int j = i * i; j < n; j += i) {
        arr[j] = false;
      }
    }
  }

  for (int i = n - 1; i > 0; i--) {
    if (arr[i] && primeMap["largest"] == 0)
      primeMap["largest"] = i;
    else if (arr[i] && primeMap["next-largest"] == 0) {
      primeMap["next-largest"] = i;
      break;
    }
  }
}

//*****************************************************************************
//*****************************************************************************
template <class T> void HashTable<T>::dumpTable() {
  int key = 0;
  typename std::vector<T>::iterator it = table.begin();
  for ( ; it < table.end(); it++) {
    std::cout << "key: " << key << " value: " << *it << std::endl;
    key++;
  }
}
