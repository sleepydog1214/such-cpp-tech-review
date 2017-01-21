#include "parse-json.hpp"

const string ParseJson::jsonName = "./json/review-init.json";

ParseJson::ParseJson() {
  jsonFile.exceptions(ifstream::failbit | ifstream::badbit);

  try {
    jsonFile.open(jsonName.c_str(), ifstream::in);
  }
  catch(ifstream::failure& e) {
    cerr << "Cannot open file: " << jsonName << endl;
  }
}

ParseJson::~ParseJson() {
  jsonFile.close();
}
