#include "MainWindow.h"

MainWindow::MainWindow()
{
    int nRet = 0;

    CurlTest curlTest;
    ReadConfig ReadConfig;

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

    std::vector<MarketItem> vecItemList;
    nRet = curlTest.LoadMarketItem(APIBearer);
    nRet = curlTest.GetMarketItem(&vecItemList);


    layout = new QVBoxLayout;
    button1 = new QPushButton("Button 1", this);
    layout->addWidget(button1);

    setLayout(layout);

}

MainWindow::~MainWindow()
{
}
