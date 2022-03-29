#include "mapWidget.h"

#include "../../../../../Utilities/utilities.h"

#include <ArcGISRuntimeEnvironment.h>
#include <Map.h>
#include <MapGraphicsView.h>

using namespace Esri::ArcGISRuntime;

mapWidget::mapWidget(QWidget* parent){
	utilities::setPaletteColor(this, QPalette::Background, Qt::black);

	//

	hBoxLayout = new QHBoxLayout(this);
	hBoxLayout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(hBoxLayout);

	arcGISMap = new Map(BasemapStyle::ArcGISImagery, this);
	arcGISMapView = new MapGraphicsView(arcGISMap, this);

	hBoxLayout->addWidget(arcGISMapView);

}

mapWidget::~mapWidget(){
    
}