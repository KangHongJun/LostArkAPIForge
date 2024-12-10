#include "MainWindow.h"

MainWindow::MainWindow()
{
    int nRet = 0;
    fCurrentPrice = 0.0f;
    fBundleCount = 0.0f;
    nSelectedItemPrice = 0;

    mapFusionItemBundle = {
            {"아비도스 융화 재료", 10},
            {"최상급 오레하 융화 재료", 15},
            {"상급 오레하 융화 재료", 20},
            {"오레하 융화 재료", 30}
    };

    category_listWidget = new QListWidget(this);
    ItemNameLabel = new QLabel(this);
    ItemNameLabel->hide();

    ItemPriceLabel = new QLabel(this);
    ItemPriceLabel->hide();

    TotalPricesLabel = new QLabel(this);
    TotalPricesLabel->hide();

    nRet = SetMarketItem();
    nRet = MakeCategoryListWidget();

    layout = new QVBoxLayout;
    button1 = new QPushButton("새로고침", this);
    layout->addWidget(button1);
    layout->addWidget(category_listWidget);
    layout->addWidget(ItemNameLabel);
    layout->addWidget(ItemPriceLabel);
    layout->addWidget(TotalPricesLabel);
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

    nRet = curlTest.LoadMarketItem(APIBearer, "90000", "", mapLifeItem);
    nRet = curlTest.LoadMarketItem(APIBearer, "50010", "융화", mapFusionItem);

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

void MainWindow::GetItemFee(int &nItemPrice)
{
    if (nItemPrice != 1)
        nItemPrice -= static_cast<int>(std::ceil(nItemPrice * 0.05));
}

void MainWindow::GetItemRecipe(std::string strSelectedItemName)
{
    QString qstrTotalInfo = "";
    std::ifstream fItemRecipe("C:/ToyProjects/LostArkAPIForge/ItemRecipe.json");
    if (!fItemRecipe.is_open())
    {
        std::cerr << "Recipe File Open Error\n";
    }

    nlohmann::json jsonItemRecipe;
    fItemRecipe >> jsonItemRecipe;

    auto jsonItemRecipeCategory = jsonItemRecipe[strSelectedItemName.c_str()];

    for (auto& [keyItemRecipeCategory, valueItemRecipeCategory] : jsonItemRecipeCategory.items())
    {
        fTotalPrice = 0.0f;
        for (auto& [strItemName, intItemCount] : valueItemRecipeCategory.items())
        {
            MarketItem mMarkgetItem = mapLifeItem[strItemName];
//            // 제작비 할인 생략
            if (strItemName == "조합비")
            {
                fBundleCount = 1;
                fCurrentPrice = 1;
            }
            else
            {
                fBundleCount = mMarkgetItem.BundleCount;
                fCurrentPrice = mMarkgetItem.CurrentMinPrice;
            }
            fTotalPrice += static_cast<float>(intItemCount) * (fCurrentPrice / fBundleCount);
        }
        QString totalPriceText = QString("%1: %2").arg(QString::fromStdString(keyItemRecipeCategory)).arg(fTotalPrice);

        qstrTotalInfo += "\n" + totalPriceText + "\n";
    }

    MarketItem mMarkgetItem = mapFusionItem[strSelectedItemName];
    nSelectedItemPrice = mMarkgetItem.CurrentMinPrice;
    int nSelectedItemTotalPrice = nSelectedItemPrice * mapFusionItemBundle[strSelectedItemName];
    GetItemFee(nSelectedItemTotalPrice);

    ItemPriceLabel->setText(std::to_string(nSelectedItemTotalPrice).c_str());
    ItemNameLabel->show();
    ItemPriceLabel->show();

    TotalPricesLabel->setText(qstrTotalInfo);
    TotalPricesLabel->show();

}

void MainWindow::DisplayItemInfo(QListWidgetItem* item)
{
    QString selectedItemName = item->text();
    ItemNameLabel->setText(selectedItemName);
    GetItemRecipe(selectedItemName.toStdString());
}