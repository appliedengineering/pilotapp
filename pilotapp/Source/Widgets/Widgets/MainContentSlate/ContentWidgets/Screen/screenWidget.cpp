#include "screenWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

screenWidget::screenWidget(QWidget* parent){
    this->widgetType = fullscreen;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);
}

screenWidget::~screenWidget(){

}