#include "telemetryWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

telemetryWidget::telemetryWidget(QWidget* parent){
    this->widgetType = fullscreen;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);
}

telemetryWidget::~telemetryWidget(){

}

//