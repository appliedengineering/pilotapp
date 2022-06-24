#include "touchNumericalLineEdit.h"

#include "../../TouchKeypad/touchKeypad.h"

TouchNumericalLineEdit::TouchNumericalLineEdit(QWidget* parent) : QLineEdit(parent){    
    this->installEventFilter(touchKeypad::getInstance());
}