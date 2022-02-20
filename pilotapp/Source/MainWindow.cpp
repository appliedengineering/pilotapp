#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

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

