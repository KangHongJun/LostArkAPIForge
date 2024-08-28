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

};
