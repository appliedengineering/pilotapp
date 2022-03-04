#ifndef TELEMETRY_WIDGET_H_
#define TELEMETRY_WIDGET_H_

#include <QWidget>
#include "../../contentWidget.h"

class telemetryWidget : public ContentWidget{
    Q_OBJECT

private:

public:
    telemetryWidget(QWidget* parent = nullptr);
    ~telemetryWidget();

};


#endif