#include "src/API/CurlTest.h"
#include "src/GUI/MainWindow.h"

#include <iostream>
#include <fstream>
#include <string>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("MainWindow Example");
    window.show();
    return app.exec();
}
