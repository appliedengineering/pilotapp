#ifndef SCREEN_WIDGET_H_
#define SCREEN_WIDGET_H_

#include <QWidget>

class powerWidget : public QWidget{
    Q_OBJECT

private:

public:
    powerWidget(QWidget* parent = nullptr);
    ~powerWidget();
};

#endif