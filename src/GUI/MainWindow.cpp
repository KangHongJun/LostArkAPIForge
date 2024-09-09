#include "MainWindow.h"

MainWindow::MainWindow()
{
    int nRet = 0;
    nRet = SetMarketItem();
    nRet = MakeCategoryListWidget();
    category_listWidget = new QListWidget(this);

    for (const auto& marketItem : vecItemList) {
        category_listWidget->addItem(QString::fromStdString(marketItem.Name));
    }

    layout = new QVBoxLayout;
    button1 = new QPushButton("새로고침", this);
    layout->addWidget(button1);
    layout->addWidget(category_listWidget);
    setLayout(layout);
}

MainWindow::~MainWindow()
{
}

int MainWindow::SetMarketItem()
{
    int nRet = 0;
    std::string APIBearer = "None";
    nRet = ReadConfig.GetAPIBearer(APIBearer);

    switch (nRet)
    {
        case static_cast<int>(RESULT_CODE::OK):
            break;
        case static_cast<int>(RESULT_CODE::ERROR_FAIL_OPEN_CONFIGFILE):
            std::cout << "[ERROR_FAIL_OPEN_CONFIGFILE] APIBearer : " << APIBearer << std::endl;
            break;
    }

    nRet = curlTest.LoadMarketItem(APIBearer);
    nRet = curlTest.GetMarketItem(&vecItemList);

    for (const auto& marketItem : vecItemList) {
        std::cout << "Item Name: " << marketItem.Name << std::endl;
        std::cout << "Bundle Count: " << marketItem.BundleCount << std::endl;
        std::cout << "Current Min Price: " << marketItem.CurrentMinPrice << std::endl;
        std::cout << "Yesterday's Avg Price: " << marketItem.YDayAvgPrice << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    return nRet;
}


int MainWindow::MakeCategoryListWidget()
{
    int nRet = 0;


    return nRet;
}