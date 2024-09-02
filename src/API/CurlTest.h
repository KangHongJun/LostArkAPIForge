#pragma once
#include "curl/curl.h"
#include "../../thirdparty/json.hpp"
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
    int APITest(const std::string& APIBearer);

private:
    CURL *curl;
    CURLcode Curlres;
    std::string readBuffer;
    std::string APIurl;
    std::string filename = "./config.cfg";
    bool bEndPage = false;
    int page = 1;

struct MarketItem
{
    std::string Name = "";
    int BundleCount = 0;
    int CurrentMinPrice = 0;
    float YDayAvgPrice = 0.f;
};

public:
    std::map<std::string, MarketItem> ItemMap;
};
