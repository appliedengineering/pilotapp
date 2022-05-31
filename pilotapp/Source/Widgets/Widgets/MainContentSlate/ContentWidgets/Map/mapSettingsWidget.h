#ifndef MAP_SETTINGS_WIDGET_H_
#define MAP_SETTINGS_WIDGET_H_

#include <QWidget>
#include "../../contentWidget.h"

class mapSettingsWidget : public ContentWidget{
    Q_OBJECT

private:

public:
    mapSettingsWidget(QWidget* parent = nullptr);
    ~mapSettingsWidget();
};

#endif