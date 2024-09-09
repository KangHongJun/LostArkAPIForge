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

    CurlTest curlTest;
    ReadConfig ReadConfig;

    std::vector<MarketItem> vecItemList;
    std::vector<std::pair<std::string,std::string>> vecItemCMP;

    QListWidget *category_listWidget;
    QPushButton *button1;
    QVBoxLayout *layout;
    QLabel *nameLabel;
    QLineEdit *editDC;
};

