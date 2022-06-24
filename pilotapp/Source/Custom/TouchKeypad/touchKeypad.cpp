#include "touchKeypad.h"

#include <QLineEdit>
#include <QDebug>

//

touchKeypad* touchKeypad::instance = nullptr;

touchKeypad::touchKeypad(){
    
}

touchKeypad::~touchKeypad(){

}

touchKeypad* touchKeypad::getInstance(){
    if (touchKeypad::instance == nullptr){
        touchKeypad::instance = new touchKeypad();
    }
    return touchKeypad::instance;
}

//

bool touchKeypad::eventFilter(QObject* obj, QEvent* event){
    if (qobject_cast<QLineEdit*>(obj) && event->type() == QEvent::FocusIn){
        qInfo() << "keypad open";
    }
    return QWidget::eventFilter(obj, event);
}

void touchKeypad::buttonPressed(int num){

}

//



