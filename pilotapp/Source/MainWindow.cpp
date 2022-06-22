#include "MainWindow.h"

#include "Source/Backend/Communication/communicationThread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    this->setFixedSize(800, 480); // size of offical raspberry pi display

    //

    displayFilter = new displayControlEventFilter(this);

    //

    home = new homePage(this);

    setCentralWidget(home);
}

MainWindow::~MainWindow(){
}

//

void MainWindow::closeApplication() {
    communicationThread::getInstance()->stop();
    QApplication::quit();
}

void MainWindow::closeEvent(QCloseEvent* event){
    closeApplication();
}

homePage* MainWindow::getHomePageWidget(){
    return home;
}

displayControlEventFilter* MainWindow::getDisplayFilter(){
    return displayFilter;
}

