#include "mapWidget.h"

#include "../../../../../Utilities/utilities.h"

#include <ArcGISRuntimeEnvironment.h>

mapWidget::mapWidget(QWidget* parent){
	utilities::setPaletteColor(this, QPalette::Background, Qt::green);

	qDebug() << "map widget size - " << this->size();
}

mapWidget::~mapWidget(){
    
}