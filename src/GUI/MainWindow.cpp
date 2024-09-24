#include "MainWindow.h"

MainWindow::MainWindow()
{
    int nRet = 0;
    int nCurrentPrice = 0;

    category_listWidget = new QListWidget(this);
    ItemNameLabel = new QLabel(this);
    ItemNameLabel->hide();

    ItemPriceLabel = new QLabel(this);
    ItemPriceLabel->hide();



    nRet = SetMarketItem();
    nRet = MakeCategoryListWidget();

    layout = new QVBoxLayout;
    button1 = new QPushButton("새로고침", this);
    layout->addWidget(button1);
    layout->addWidget(category_listWidget);
    layout->addWidget(ItemNameLabel);
    layout->addWidget(ItemPriceLabel);
    setLayout(layout);

    connect(category_listWidget, &QListWidget::itemClicked, this, &MainWindow::DisplayItemInfo);
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

    std::string strLifeCategory = "{\"CategoryCode\":90000,"
                           "\"PageNo\": 0" + std::string("}");

    std::string strFusionCategory = "{\"CategoryCode\":50010, \"ItemName\":\"융화\","
                                  "\"PageNo\": 0" + std::string("}");

    nRet = curlTest.LoadMarketItem(APIBearer, strLifeCategory, mapLifeItem);
    nRet = curlTest.LoadMarketItem(APIBearer, strFusionCategory, mapFusionItem);

    return nRet;
}


int MainWindow::MakeCategoryListWidget()
{
    int nRet = 0;

    for (const auto& marketItem : mapFusionItem)
    {
        category_listWidget->addItem(QString::fromStdString(marketItem.first));
    }

    return nRet;
}

void MainWindow::DisplayItemInfo(QListWidgetItem* item)
{
    QString selectedItemName = item->text();
    ItemNameLabel->setText(selectedItemName);
    MarketItem mMarkgetItem = mapFusionItem[selectedItemName.toStdString()];
    nCurrentPrice = mMarkgetItem.CurrentMinPrice;
    ItemPriceLabel->setText(std::to_string(nCurrentPrice).c_str());
    ItemNameLabel->show();
    ItemPriceLabel->show();
}