#include "ReadConfig.h"

ReadConfig::ReadConfig()
{
}

ReadConfig::~ReadConfig()
{
}

int ReadConfig::GetAPIBearer(std::string& APIBearer)
{
    int nRet = 0;
    std::ifstream configFile("C:/ToyProjects/LostArkAPIForge/config.cfg");
    std::string line;
    std::string bearerToken;

    if (configFile.is_open())
    {
        while (std::getline(configFile, line))
        {
            if (line.find("[Bearer]") != std::string::npos)
            {
                if (std::getline(configFile, line))
                {
                    bearerToken = line;
                    APIBearer = bearerToken;
                    break;

                }
            }
            configFile.close();
        }
    }
    else
    {
        nRet = static_cast<int>(RESULT_CODE::ERROR_FAIL_OPEN_CONFIGFILE);
    }
    return nRet;
}