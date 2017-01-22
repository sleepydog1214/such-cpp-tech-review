#ifndef PARSE_JSON_HPP
#define PARSE_JSON_HPP

#include <string>
#include <fstream>
#include <map>
#include <vector>

class ParseJSON {
  public:
    ParseJSON();

    void getJSON();
    std::map< std::string,
      std::vector< std::map< std::string,
        std::vector< std::map< std::string, std::string > > > > > & getData() {
          return jsonData;
        };

    ~ParseJSON();

  private:
    static const std::string jsonName;
    std::ifstream jsonFile;

    // jsonData:
    // map<string, vector>
    //  - the vector<map>
    //    - the map<string, vector>
    //      - the vector<map>
    //        - the map<string, string>
    std::map< std::string,
      std::vector< std::map< std::string,
        std::vector< std::map< std::string, std::string > > > > > jsonData;

    std::string getStringFromLine(std::string);
};

#endif
