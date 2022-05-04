#ifndef POWER_WIDGET_H_
#define POWER_WIDGET_H_

#include <QWidget>
#include "../../contentWidget.h"

#include <QHBoxLayout>

class powerWidget : public ContentWidget{
    Q_OBJECT

private:
    QHBoxLayout* hLayout = nullptr;

    

    void renderContent();

public:
    powerWidget(QWidget* parent = nullptr);
    ~powerWidget();
};

#endif