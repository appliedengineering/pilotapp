#include "touchKeypad.h"

#include "../TouchInputWidgets/TouchNumericalLineEdit/touchNumericalLineEdit.h"
#include "../../Backend/Utilities/utilities.h"
#include "../../MainWindow.h"

#include <QDebug>
#include <QPushButton>
#include <QKeyEvent>

//

touchKeypad* touchKeypad::instance = nullptr;

touchKeypad::touchKeypad(QWidget* parent) : QWidget(parent){
    utilities::setPaletteColor(this, QPalette::Background, Qt::blue);
    this->hide();

    //

    renderContent();
}

touchKeypad::~touchKeypad(){
}

touchKeypad* touchKeypad::getInstance(){
    if (touchKeypad::instance == nullptr){
        touchKeypad::instance = new touchKeypad(utilities::findMainWindow());
    }
    return touchKeypad::instance;
}

//

void touchKeypad::renderContent(){
    gridLayout = new QGridLayout(this);

    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setSpacing(0);

    //

    QPushButton* b = new QPushButton(this);

    b->setText("Close");

    connect(b, &QPushButton::clicked, this, &touchKeypad::closeKeypad);

    gridLayout->addWidget(b);
}

void touchKeypad::closeKeypad(){
    this->hide();
    if (inputWidget)
        inputWidget->clearFocus();
}

//

bool touchKeypad::eventFilter(QObject* obj, QEvent* event){
    if (qobject_cast<TouchNumericalLineEdit*>(obj) && event->type() == QEvent::FocusIn){
        //qInfo() << "keypad open";
        utilities::findMainWindow()->showTouchKeypad();
        inputWidget = qobject_cast<QWidget*>(obj);
    }
    return QWidget::eventFilter(obj, event);
}

// https://stackoverflow.com/a/11185022/

void touchKeypad::mouseMoveEvent(QMouseEvent* event){
    if (event->buttons() & Qt::LeftButton){
        this->move(mapToParent(event->pos() - mouseEventOffset));
        
        // to ensure pad stays within bounds

        QPoint p = this->pos();
        p.setX(p.x() + (width / 2));
        p.setY(p.y() + (height / 2));

        //qInfo() << "pos = " << p; 

        p.setX(std::max(std::min(p.x(), MainWindow::windowWidth), 0));
        p.setY(std::max(std::min(p.y(), MainWindow::windowHeight), 0));

        //qInfo() << "adj pos = " << p;
        
        p.setX(p.x() - (width / 2));
        p.setY(p.y() - (height / 2));
        this->move(p);
    }
}

void touchKeypad::mousePressEvent(QMouseEvent* event){
    mouseEventOffset = event->pos();
}

//

void touchKeypad::buttonPress(int num){

}

QSize touchKeypad::getSize(){
    return QSize(width, height);
}
