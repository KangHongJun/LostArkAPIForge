#pragma once
#include "curl/curl.h"
#include "../../thirdparty/json.hpp"
#include "../util/CODE_DEFINE.h"
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>

class CurlTest
{
public:
    CurlTest();
    ~CurlTest();

public:
    int LoadMarketItem(const std::string& strAPIBearer, const std::string& strCategory,
                       std::map<std::string, MarketItem>& mapItemList);
    int GetMarketItem(std::vector<MarketItem>* pVecItemList);

private:
    CURL *curl;
    CURLcode Curlres;
    std::string readBuffer;
    std::string APIurl;
    std::string filename = "./config.cfg";
    bool bEndPage = false;
    int page = 1;

    std::map<std::string, MarketItem> ItemMap;

public:

};
