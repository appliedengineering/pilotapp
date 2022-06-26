#ifndef TOUCH_NUMERICAL_LINE_EDIT_H_
#define TOUCH_NUMERICAL_LINE_EDIT_H_

#include <QLineEdit>

class TouchNumericalLineEdit : public QLineEdit{
    Q_OBJECT
private:
public:
    TouchNumericalLineEdit(QWidget* parent = nullptr);
};

#endif