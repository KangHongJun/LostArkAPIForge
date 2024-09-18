#include "CurlTest.h"

CurlTest::CurlTest()
{
    APIurl = "https://developer-lostark.game.onstove.com/markets/items";

}

CurlTest::~CurlTest()
{
    APIurl = "";
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int CurlTest::GetMarketItem(std::vector<MarketItem>* pVecItemList)
{
    int nRet = 0;

    if (pVecItemList == nullptr)
    {
        nRet = -1;
        return nRet;
    }

    for (const auto& pair : ItemMap)
    {
        pVecItemList->push_back(pair.second);
    }

    return nRet;
}

int CurlTest::LoadMarketItem(const std::string& strAPIBearer, const std::string& strCategory,
                             std::map<std::string, MarketItem>& mapItemList)
{
    int nRet = 0;
    std::string strpage = std::to_string(page);
    std::string Authorization = "Authorization: Bearer " + strAPIBearer;

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
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, strCategory.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        Curlres = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        nlohmann::json json_obj = nlohmann::json::parse(readBuffer);
        auto ItemsData = json_obj["Items"];

        for (const auto& ItemData : ItemsData)
        {
            MarketItem MarketItem;
            MarketItem.Name = ItemData["Name"];
            MarketItem.BundleCount = ItemData["BundleCount"];
            MarketItem.CurrentMinPrice = ItemData["CurrentMinPrice"];
            MarketItem.YDayAvgPrice = ItemData["YDayAvgPrice"];

            ItemMap[MarketItem.Name] = MarketItem;

            mapItemList[MarketItem.Name] = MarketItem;
        }
    }
    return nRet;
}
