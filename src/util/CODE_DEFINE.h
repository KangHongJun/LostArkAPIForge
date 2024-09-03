#pragma once

const int nMinCount = -0x01;
#include <iostream>

enum class RESULT_CODE
{
    ERROR_FAIL_OPEN_CONFIGFILE = nMinCount,
    OK,
};

struct MarketItem
{
    std::string Name = "";
    int BundleCount = 0;
    int CurrentMinPrice = 0;
    float YDayAvgPrice = 0.f;

};