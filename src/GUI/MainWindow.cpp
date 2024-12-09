#include "MainWindow.h"

MainWindow::MainWindow()
{
    int nRet = 0;
    fCurrentPrice = 0.0f;
    fBundleCount = 0.0f;
    nSelectedItemPrice = 0;

    mapFusionItemBundle = {
            {"아비도스 융화 재료", 15},
            {"최상급 오레하 융화 재료", 20},
            {"상급 오레하 융화 재료", 20},
            {"오레하 융화 재료", 30}
    };

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

void MainWindow::GetItemRecipe(std::string strSelectedItemName)
{
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

        std::cout << "SelectedItem: " << nSelectedItemPrice * mapFusionItemBundle[strSelectedItemName] << "-" << keyItemRecipeCategory << ": " << fTotalPrice << std::endl;
    }
}

void MainWindow::DisplayItemInfo(QListWidgetItem* item)
{
    QString selectedItemName = item->text();
    ItemNameLabel->setText(selectedItemName);
    MarketItem mMarkgetItem = mapFusionItem[selectedItemName.toStdString()];
    nSelectedItemPrice = mMarkgetItem.CurrentMinPrice;
    ItemPriceLabel->setText(std::to_string(nSelectedItemPrice).c_str());
    ItemNameLabel->show();
    ItemPriceLabel->show();
    GetItemRecipe(selectedItemName.toStdString());
}