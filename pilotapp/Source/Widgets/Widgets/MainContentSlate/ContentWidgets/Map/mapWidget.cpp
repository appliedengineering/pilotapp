#include "mapWidget.h"

#include "../../../../../Utilities/utilities.h"

mapWidget::mapWidget(QWidget* parent){
	utilities::setPaletteColor(this, QPalette::Background, Qt::gray);
}

mapWidget::~mapWidget(){
    
}