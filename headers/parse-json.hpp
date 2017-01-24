#ifndef PARSE_JSON_HPP
#define PARSE_JSON_HPP

#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "json-data-structures.hpp"

class ParseJSON {
  public:
    ParseJSON();

    // Read and store the JSON data
    void readJSON();

    // Return the JSON data
    MainJSONMap& getData() {
          return jsonData;
    };

    ~ParseJSON();

  private:
    static const std::string jsonName;
    std::ifstream jsonFile;
    MainJSONMap jsonData;

    std::string getStringFromLine(std::string);
};

#endif
