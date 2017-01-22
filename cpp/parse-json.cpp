#include "parse-json.hpp"
#include <iostream>
#include <cstddef>

const std::string ParseJSON::jsonName = "./json/review-init.json";

ParseJSON::ParseJSON() {
  jsonFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    jsonFile.open(jsonName.c_str(), std::ifstream::in);
  }
  catch(std::ifstream::failure& e) {
    std::cerr << "Cannot open file: " << jsonName << std::endl;
  }
}

void ParseJSON::getJSON() {
  std::string line;
  std::size_t found;
  std::vector<std::map<std::string,
      std::vector<std::map<std::string, std::string> > > > bvect;

  jsonFile.exceptions(std::ifstream::goodbit);

  // get the main key for the jsonData map
  std::getline(jsonFile, line);
  std::string mainKey = getStringFromLine(line);

  //loop through all jsonData map values
  std::getline(jsonFile, line);
  std::string valueKey = getStringFromLine(line);
  while (true) {
    std::vector<std::map<std::string, std::string> > avect;

    // loop through all jsonData inner string: string pairs
    while (std::getline(jsonFile, line)) {
      found = line.find("}}");
      if (found != std::string::npos)
        break;

      std::string ik = getStringFromLine(line);
      std::size_t x = line.find(ik);
      std::size_t y = ik.length();
      std::string iv = line.substr(x + y + 1);
      iv = getStringFromLine(iv);

      std::map<std::string, std::string> amap;
      amap[ik] = iv;
      avect.push_back(amap);
    }

    std::map<std::string,
      std::vector<std::map<std::string, std::string> > > bmap;
    bmap[valueKey] = avect;
    bvect.push_back(bmap);
    std::getline(jsonFile, line);

    found = line.find("]}");
    if (found != std::string::npos)
      break;
    else
      valueKey = getStringFromLine(line);
  }

  jsonData[mainKey] = bvect;
}

std::string ParseJSON::getStringFromLine(std::string line) {
  std::string tmp;

  std::size_t x = line.find_first_of("\"");
  std::size_t y = line.find_first_of("\"", x + 1);

  tmp = line.substr(x + 1, y - x - 1);
  return tmp;
}

ParseJSON::~ParseJSON() {
  jsonFile.close();
}
