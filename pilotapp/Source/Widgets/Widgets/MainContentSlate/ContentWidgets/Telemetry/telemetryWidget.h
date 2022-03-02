#ifndef TELEMETRY_WIDGET_H_
#define TELEMETRY_WIDGET_H_

#include <QWidget>

class telemetryWidget : public QWidget{
    Q_OBJECT

private:

public:
    telemetryWidget(QWidget* parent = nullptr);
    ~telemetryWidget();

};


#endif