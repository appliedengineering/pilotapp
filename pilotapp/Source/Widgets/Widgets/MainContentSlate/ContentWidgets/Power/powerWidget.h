#ifndef POWER_WIDGET_H_
#define POWER_WIDGET_H_

#include <QWidget>
#include "../../contentWidget.h"

class powerWidget : public ContentWidget{
    Q_OBJECT

private:

public:
    powerWidget(QWidget* parent = nullptr);
    ~powerWidget();
};

#endif