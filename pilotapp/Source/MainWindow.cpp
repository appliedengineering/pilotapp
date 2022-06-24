#include "MainWindow.h"

#include "Source/Backend/Communication/communicationThread.h"
#include "Source/Custom/TouchKeypad/touchKeypad.h"

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
    displayFilter->commitBrightness(displayFilter->getAbsoluteMaxBrightness());
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

void MainWindow::showTouchKeypad(){
    touchKeypad* keypad = touchKeypad::getInstance();
    keypad->show();
    keypad->setGeometry(0, 0, 100, 100);
}