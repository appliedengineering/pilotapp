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

/* List of features
 - Connection Status with Groundstation
 - Acceptable Heading Error
 - Manual Heading Setting
 - Servo Speed Setting (0.0 to 1.0)
 - Voice Settings (once its done)
*/

#endif