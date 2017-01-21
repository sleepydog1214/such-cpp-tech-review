#ifndef PARSE_JSON_HPP
#define PARSE_JSON_HPP

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ParseJson {
  public:
    ParseJson();
    ~ParseJson();

  private:
    static const string jsonName;
    ifstream jsonFile;
};

#endif
