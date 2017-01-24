#ifndef JSON_DATA_STRUCTURES
#define JSON_DATA_STRUCTURES

#include <vector>
#include <map>
#include <string>

//*****************************************************************************
// The innermost map of the JSON file
//*****************************************************************************
class DataPairMap {
  public:
    DataPairMap () {}

    DataPairMap( std::map< std::string, std::string > amap) {
      dataPairMap = amap;
    }

    std::string& operator[] (std::string s) {
      return dataPairMap[s];
    }

    std::string key() {
      std::map< std::string, std::string >::iterator it = dataPairMap.begin();
      return it->first;
    }

    std::string value() {
      std::map< std::string, std::string >::iterator it = dataPairMap.begin();
      return it->second;
    }

  private:
    std::map< std::string, std::string > dataPairMap;
};

//*****************************************************************************
// The vector of innermost JSON maps
//*****************************************************************************
class DataVector {
  public:
    DataVector() {}

    DataVector( std::vector< DataPairMap >& avect) {
      dataVector = avect;
    }

    void push_back(DataPairMap& amap) {
      dataVector.push_back(amap);
    }

    DataPairMap& operator[] (int index) {
      return dataVector[index];
    }

    std::size_t size() {
      return dataVector.size();
    }

  private:
    std::vector< DataPairMap > dataVector;
};

//*****************************************************************************
// Map each innermost vector to a review title
//*****************************************************************************
class DataMap {
  public:
    DataMap() {}

    DataMap(std::map< std::string, DataVector >& amap) {
        dataMap = amap;
      }
    DataVector& operator[] (std::string s) {
      return dataMap[s];
    }

    std::string key() {
      std::map< std::string, DataVector >::iterator it = dataMap.begin();
      return it->first;
    }

    DataVector& value() {
      std::map< std::string, DataVector >::iterator it = dataMap.begin();
      return it->second;
    }

  private:
    std::map< std::string, DataVector > dataMap;
};

//*****************************************************************************
// A vector of review data
//*****************************************************************************
class MainJSONVector {
  public:
    MainJSONVector() {}

    MainJSONVector(std::vector< DataMap >& avect) {
        mainJSONVector = avect;
      }

    void push_back(DataMap& amap) {
      mainJSONVector.push_back(amap);
    }

    DataMap& operator[] (int index) {
      return mainJSONVector[index];
    }

    std::size_t size() {
      return mainJSONVector.size();
    }

  private:
    std::vector< DataMap > mainJSONVector;
};

//*****************************************************************************
// The complete JSON object, with a "reviewList" title
//*****************************************************************************
class MainJSONMap {
  public:
    MainJSONMap() {}

    MainJSONMap(std::map< std::string, MainJSONVector >& amap) {
          mainJSONMap = amap;
    }

    MainJSONVector& operator[] (std::string s) {
      return mainJSONMap[s];
    }

    std::string key() {
      std::map< std::string, MainJSONVector >::iterator it =
          mainJSONMap.begin();
      return it->first;
    }

    MainJSONVector& value() {
      std::map< std::string, MainJSONVector >::iterator it =
          mainJSONMap.begin();
      return it->second;
    }

  private:
    std::map< std::string, MainJSONVector > mainJSONMap;
};

#endif
