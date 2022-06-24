#ifndef TOUCH_KEYPAD_H_
#define TOUCH_KEYPAD_H_

#include <QWidget>
#include <QEvent>
#include <QObject>

class touchKeypad : public QWidget{
    Q_OBJECT

private:    
    touchKeypad();
    ~touchKeypad();
    
    static touchKeypad* instance;

    void buttonPressed(int num);

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

public:
    static touchKeypad* getInstance();
};

#endif