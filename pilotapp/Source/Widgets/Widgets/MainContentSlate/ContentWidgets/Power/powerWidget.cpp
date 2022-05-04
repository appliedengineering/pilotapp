#include "powerWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

powerWidget::powerWidget(QWidget* parent){
    //this->widgetType = windowed;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    const int powerWidgetWidth = parent->width() * 0.6;
    const int powerWidgetHeight = parent->height() * 0.15;
    this->setGeometry((parent->width()/2) - (powerWidgetWidth/2), parent->height() - powerWidgetHeight, powerWidgetWidth, powerWidgetHeight);
    utilities::setWidgetRoundedCorner(this, 10, {utilities::bottomLeft, utilities::bottomRight});

    
}

powerWidget::~powerWidget(){
}

//

