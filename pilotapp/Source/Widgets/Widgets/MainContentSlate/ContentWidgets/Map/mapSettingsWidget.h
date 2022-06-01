#ifndef MAP_SETTINGS_WIDGET_H_
#define MAP_SETTINGS_WIDGET_H_

#include "../../contentWidget.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QFile>

class mapSettingsWidget : public ContentWidget{
    Q_OBJECT

private:
    QHBoxLayout* hBoxLayout = nullptr; 

    QLabel* titleLabel = nullptr;
    QLabel* coordinateLabel = nullptr;

    QPushButton* saveCoordinateButton = nullptr;

    const int coordinateDecimalPrecision = 6;

    const QString coordinateLogPath = "savedcoords.txt";

    void setupContent();
    void saveCurrentCoordinates();

public:
    mapSettingsWidget(QWidget* parent = nullptr);
    ~mapSettingsWidget();

public slots:
    void updateBoatLocation(double lat, double lon);
};

#endif