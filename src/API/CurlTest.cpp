#include "CurlTest.h"

CurlTest::CurlTest()
{
    APIurl = "https://developer-lostark.game.onstove.com/markets/items";
}

CurlTest::~CurlTest()
{
    APIurl = "";
}

int CurlTest::APITest(const std::string& APIBearer)
{
    std::string strpage = std::to_string(page);
    std::string Authorization = "Authorization: Bearer " + APIBearer;
    std::string category = "{\"CategoryCode\":90000,"
                           "\"PageNo\":" + strpage + std::string("}");

    struct curl_slist *headerlist = nullptr;
    headerlist = curl_slist_append(headerlist, "Accept: application/json");
    headerlist = curl_slist_append(headerlist, "Content-Type: application/json");
    headerlist = curl_slist_append(headerlist, "charset=UTF-8");
    headerlist = curl_slist_append(headerlist, Authorization.c_str());

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, APIurl.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);


        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, category.c_str());
        Curlres = curl_easy_perform(curl);

        std::cout << Curlres << std::endl;
    }
    return 0;
}
