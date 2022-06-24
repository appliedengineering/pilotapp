#ifndef TOUCH_KEYPAD_H_
#define TOUCH_KEYPAD_H_

#include <QWidget>
#include <QEvent>
#include <QObject>
#include <QPushButton>
#include <QGridLayout>
#include <QMouseEvent>
#include <QPoint>
#include <QSize>

class touchKeypad : public QWidget{
    Q_OBJECT

private:    
    touchKeypad(QWidget* parent = nullptr);
    ~touchKeypad();
    
    static touchKeypad* instance;
    
    const int width = 180;
    const int height = 220;
    const int cornerRadius = 10;
    const int fontSize = 12;
    const int padding = 10;

    const QColor backgroundColor = QColor(25, 25, 25);
    
    QWidget* inputWidget = nullptr; // widget that calls the touchpad
    QPoint mouseEventOffset;

    //

    QGridLayout* gridLayout = nullptr;

    void renderContent();
    void closeKeypad();
    void afterShowSetup(QObject* inputobj);

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

public:
    static touchKeypad* getInstance();
    void buttonPress(int num);

    QSize getSize();
};

#endif