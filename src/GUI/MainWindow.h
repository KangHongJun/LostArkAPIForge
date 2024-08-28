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

