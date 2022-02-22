#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    home = new homePage(this);

    setCentralWidget(home);

    setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow(){

}

//

void MainWindow::closeApplication() {
    //qInfo() << "exit";
    QApplication::quit();
}

