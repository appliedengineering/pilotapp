#include "mapSettingsWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

mapSettingsWidget::mapSettingsWidget(QWidget* parent){
    //this->widgetType = fullscreen;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    const int mapSettingsWidgetWidth = parent->width() * 0.6;
    const int mapSettingsWidgetHeight = parent->height() * 0.15;
    this->setGeometry((parent->width()/2) - (mapSettingsWidgetWidth/2), parent->height() - mapSettingsWidgetHeight, mapSettingsWidgetWidth, mapSettingsWidgetHeight);
}

mapSettingsWidget::~mapSettingsWidget(){

}

//