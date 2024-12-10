#include "../API/CurlTest.h"
#include "../util/CODE_DEFINE.h"
#include "../util/ReadConfig.h"

#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class MainWindow : public QWidget{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

private:
    int MakeCategoryListWidget();
    int SetMarketItem();
    void GetItemRecipe(std::string strSelectedItemName);
    void DisplayItemInfo(QListWidgetItem* item);
    void GetItemFee(int &nItemPrice);



    CurlTest curlTest;
    ReadConfig ReadConfig;

    std::map<std::string, MarketItem> mapFusionItem;
    std::map<std::string, MarketItem> mapLifeItem;
    std::vector<std::pair<std::string,std::string>> vecItemCMP;

    std::map<std::string, int> mapFusionItemBundle;

    int nSelectedItemPrice;

    float fTotalPrice;
    float fCurrentPrice;
    float fBundleCount;

    QListWidget *category_listWidget;
    QPushButton *button1;
    QVBoxLayout *layout;

    QLabel *ItemNameLabel;
    QLabel *ItemPriceLabel;
    QLabel *TotalPricesLabel;
};

