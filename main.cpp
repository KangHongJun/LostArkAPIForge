#include "src/API/CurlTest.h"
#include "src/util/ReadConfig.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    CurlTest curlTest;
    ReadConfig ReadConfig;

    int nRet  = 0;
    std::string APIBearer = "None";
    nRet = ReadConfig.GetAPIBearer(APIBearer);

    switch (nRet)
    {
    case static_cast<int>(RESULT_CODE::OK):
//        std::cout << "APIBearer : " << APIBearer << std::endl;
        break;
    case static_cast<int>(RESULT_CODE::ERROR_FAIL_OPEN_CONFIGFILE):
        std::cout << "[ERROR_FAIL_OPEN_CONFIGFILE] APIBearer : " << APIBearer << std::endl;
        break;
    }

    nRet = curlTest.APITest(APIBearer);
    return 0;
}
