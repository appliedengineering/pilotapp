#include "mapSettingsWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

mapSettingsWidget::mapSettingsWidget(QWidget* parent){
    this->widgetType = fullscreen;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);
}

mapSettingsWidget::~mapSettingsWidget(){

}

//