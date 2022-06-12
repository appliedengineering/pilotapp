#ifndef TELEMETRY_WIDGET_H_
#define TELEMETRY_WIDGET_H_

#include <QWidget>
#include <QVBoxLayout>
#include "../../contentWidget.h"

class telemetryWidget : public ContentWidget{
    Q_OBJECT

private:
    QVBoxLayout* vBoxLayout = nullptr;

    void renderLayout();

public:
    telemetryWidget(QWidget* parent = nullptr);
    ~telemetryWidget();

};


#endif