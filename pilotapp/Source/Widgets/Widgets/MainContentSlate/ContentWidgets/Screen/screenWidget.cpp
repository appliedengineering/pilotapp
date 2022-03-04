#include "screenWidget.h"

#include "../../../../../Utilities/utilities.h"

screenWidget::screenWidget(QWidget* parent){
    this->widgetType = fullscreen;
    utilities::setPaletteColor(this, QPalette::Background, Qt::red);
}

screenWidget::~screenWidget(){

}