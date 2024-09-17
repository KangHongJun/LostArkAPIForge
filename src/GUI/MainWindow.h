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

    void DisplayItemInfo(QListWidgetItem* item);


    CurlTest curlTest;
    ReadConfig ReadConfig;

    std::vector<MarketItem> vecItemList;
    std::vector<std::pair<std::string,std::string>> vecItemCMP;

    QListWidget *category_listWidget;
    QPushButton *button1;
    QVBoxLayout *layout;

    QLabel *ItemInfoLabel;
    QLabel *nameLabel;
    QLineEdit *editDC;
};

