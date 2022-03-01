#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    this->setFixedSize(800, 480); // size of offical raspberry pi display

    //

    home = new homePage(this);

    setCentralWidget(home);
}

MainWindow::~MainWindow(){
}

//

void MainWindow::closeApplication() {
    //qInfo() << "exit";
    QApplication::quit();
}

