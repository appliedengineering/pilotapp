#ifndef SCREEN_WIDGET_H_
#define SCREEN_WIDGET_H_

#include <QWidget>
#include "../../contentWidget.h"

class screenWidget : public ContentWidget{
    Q_OBJECT

private:

public:
    screenWidget(QWidget* parent = nullptr);
    ~screenWidget();
};

#endif