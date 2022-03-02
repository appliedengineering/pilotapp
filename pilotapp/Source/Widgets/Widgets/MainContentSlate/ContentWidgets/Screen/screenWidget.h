#ifndef SCREEN_WIDGET_H_
#define SCREEN_WIDGET_H_

#include <QWidget>

class screenWidget : public QWidget{
    Q_OBJECT

private:

public:
    screenWidget(QWidget* parent = nullptr);
    ~screenWidget();
};

#endif