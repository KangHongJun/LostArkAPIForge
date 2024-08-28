#include "MainWindow.h"

MainWindow::MainWindow()
{
    layout = new QVBoxLayout;
    button1 = new QPushButton("Button 1", this);
    layout->addWidget(button1);

    setLayout(layout);
}

MainWindow::~MainWindow()
{
}