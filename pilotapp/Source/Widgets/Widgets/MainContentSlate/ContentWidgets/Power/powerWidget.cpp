#include "powerWidget.h"

#include "../../../../../Utilities/utilities.h"

powerWidget::powerWidget(QWidget* parent){
    this->widgetType = fullscreen;
    utilities::setPaletteColor(this, QPalette::Background, Qt::blue);
}

powerWidget::~powerWidget(){

}