#include "MainWindow.h"

#include <QQuickItem>

#include "Source/Backend/Communication/communicationThread.h"
#include "Source/Backend/Utilities/utilities.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    this->setFixedSize(800, 480); // size of offical raspberry pi display

    //

    displayFilter = new displayControlEventFilter(this);

    //

    home = new homePage(this);

    setCentralWidget(home);

    //

    virtualKeyboardWidget = new QQuickWidget(this);

    virtualKeyboardWidget->setSource(QUrl("qrc:/Source/virtualkeyboard.qml"));
    virtualKeyboardWidget->setAttribute(Qt::WA_AcceptTouchEvents);
    virtualKeyboardWidget->setFocusPolicy(Qt::NoFocus);
    virtualKeyboardWidget->setGeometry(0, this->height() / 2, this->width(), this->height() / 2);

    qInfo() << QApplication::inputMethod() << " : " << virtualKeyboardWidget->rootObject()->children();
    //virtualKeyboardWidget->raise();
    //virtualKeyboardWidget->show();
}

MainWindow::~MainWindow(){
}

//

void MainWindow::displayVirtualKeyboard(){

    virtualKeyboardWidget = new QQuickWidget(this);

    virtualKeyboardWidget->setSource(QUrl("qrc:/Source/virtualkeyboard.qml"));
    virtualKeyboardWidget->setAttribute(Qt::WA_AcceptTouchEvents);
    virtualKeyboardWidget->setFocusPolicy(Qt::NoFocus);
    virtualKeyboardWidget->setGeometry(0, this->height() / 2, this->width(), this->height() / 2);
    virtualKeyboardWidget->raise();
    virtualKeyboardWidget->show();

    /*virtualKeyboardView = new QQuickView();

    virtualKeyboardViewContainer = QWidget::createWindowContainer(virtualKeyboardView, this);
    //virtualKeyboardViewContainer = new QWidget(this);
    virtualKeyboardViewContainer->setGeometry(0, this->height() / 2, this->width(), this->height() / 2);
    //virtualKeyboardViewContainer->raise();

    virtualKeyboardView->setSource(QUrl("qrc:/Source/virtualkeyboard.qml"));
    virtualKeyboardView->setFocusPolicy(Qt::NoFocus);

    qInfo() << QApplication::inputMethod();

    //utilities::setPaletteColor(virtualKeyboardViewContainer, QPalette::Background, Qt::white);

    virtualKeyboardViewContainer->show();*/
}

void MainWindow::hideVirtualKeyboard(){
    if (virtualKeyboardWidget){
        virtualKeyboardWidget->hide();
        delete virtualKeyboardWidget;
        virtualKeyboardWidget = nullptr;
    }
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

void MainWindow::mousePressEvent(QMouseEvent* e){
    qInfo() << "mouse press event";
    /*hideVirtualKeyboard();
    displayVirtualKeyboard();*/
}

homePage* MainWindow::getHomePageWidget(){
    return home;
}

displayControlEventFilter* MainWindow::getDisplayFilter(){
    return displayFilter;
}

