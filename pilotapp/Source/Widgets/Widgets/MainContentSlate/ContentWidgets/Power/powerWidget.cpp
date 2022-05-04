#include "powerWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

powerWidget::powerWidget(QWidget* parent){
    //this->widgetType = windowed;
    utilities::setPaletteColor(this, QPalette::Background, Qt::blue);

    //

    //qInfo() << parent->size();
    const int powerWidgetWidth = parent->width() * 0.6;
    const int powerWidgetHeight = parent->height() * 0.15;
    this->setGeometry((parent->width()/2) - (powerWidgetWidth/2), parent->height() - powerWidgetHeight, powerWidgetWidth, powerWidgetHeight);
}

powerWidget::~powerWidget(){

}