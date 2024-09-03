#include "../API/CurlTest.h"
#include "../util/CODE_DEFINE.h"
#include "../util/ReadConfig.h"

#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>


class MainWindow : public QWidget{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

private:
    QListWidget *category_listWidget;
    QPushButton *button1;
    QVBoxLayout *layout;
};

