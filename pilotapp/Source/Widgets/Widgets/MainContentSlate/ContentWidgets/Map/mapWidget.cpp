#include "mapWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"
#include "../../../../../Backend/boatKernel.h"

#include <QDir>
#include <QFile>
#include <vector>
#include <sstream>
#include <string>

#include <ArcGISRuntimeEnvironment.h>
#include <Map.h>
#include <MapGraphicsView.h>
#include <Viewpoint.h>
#include <Point.h>
#include <MobileMapPackage.h>
#include <Error.h>

#include <GraphicsOverlay.h>
#include <PolylineBuilder.h>
#include <PolygonBuilder.h>
#include <SimpleMarkerSceneSymbol.h>
#include <SimpleFillSymbol.h>
#include <SimpleMarkerSymbol.h>

using namespace Esri::ArcGISRuntime;

mapWidget::mapWidget(QWidget* parent){
	utilities::setPaletteColor(this, QPalette::Background, Qt::black);

	//

	hBoxLayout = new QHBoxLayout(this);
	hBoxLayout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(hBoxLayout);

	//arcGISMap = new Map(Basemap::imageryWithLabels(this), this);
	arcGISMapView = new MapGraphicsView(nullptr, this);

	hBoxLayout->addWidget(arcGISMapView);

	//

	//setMapCenter(parseMapData(readMapFile()));
	setupMapFromMmpk();

	//

	arcGISOverlay = new GraphicsOverlay(this);
	renderGraphics(arcGISOverlay);
	arcGISMapView->graphicsOverlays()->append(arcGISOverlay);

	connect(boatKernel::getInstance(), &boatKernel::locationUpdateSignal, this, &mapWidget::updateBoatLocation);
}

mapWidget::~mapWidget(){
}

//

void mapWidget::updateBoatLocation(double lat, double lon){
	boatLat = lat;
	boatLon = lon;
	//qInfo() << "update boat location - " << lat << " " << lon;
	renderGraphics(arcGISOverlay);
}

//

/*QString mapWidget::readMapFile(){
	QFile mapFile("navcenter.txt");
	
	if (mapFile.open(QIODevice::ReadOnly | QIODevice::Text)){
		QString data = mapFile.readAll();
	   	qDebug() << "Opened map data file (navcenter.txt) - " << data;
	   	return data;
	}
	
	qInfo() << "No map data file found (navcenter.txt)";
	return "";
}

Viewpoint mapWidget::parseMapData(QString raw){
	std::string r = raw.toStdString();
	
	std::vector<std::string> sArray;
	std::stringstream stream(r);

	while (stream.good()){
		std::string substr;
		getline(stream, substr, ',');
		sArray.push_back(substr);
	}


	if (sArray.size() != 3){
		qFatal("Map data is invalid");
		return Viewpoint();
	}

	double latitude = std::stod(sArray[0]), longitude = std::stod(sArray[1]), scale = std::stod(sArray[2]); // default scale is 100000.0
	
	Point centerPoint(longitude, latitude, SpatialReference::wgs84());

	return Viewpoint(centerPoint, scale);
}

void mapWidget::setMapCenter(Viewpoint center){
	this->arcGISMapView->setViewpoint(center);
}*/

void mapWidget::setupMapFromMmpk(){
	QString mmpkPath = QDir::currentPath() + "/map.mmpk";

	//qDebug() << mmpkPath;

	MobileMapPackage* mappackage = new MobileMapPackage(mmpkPath, this);

	connect(mappackage, &MobileMapPackage::doneLoading, this, [mappackage, this](Error error){
		if (!error.isEmpty()){
			qDebug() << "Error: " << error.message() << error.additionalMessage();
			return;
		}

		arcGISMapView->setMap(mappackage->maps().at(0));
	});

	mappackage->load();
}

void mapWidget::renderGraphics(Esri::ArcGISRuntime::GraphicsOverlay* overlay){
	overlay->graphics()->clear();

	//

	drawPoint(overlay, boatLat, boatLon);
}

void mapWidget::drawPoint(Esri::ArcGISRuntime::GraphicsOverlay* overlay, double lat, double lon, QColor pointColor, QColor outlineColor){
	Point p(lon, lat, SpatialReference::wgs84());

  	SimpleLineSymbol* pOutline = new SimpleLineSymbol(SimpleLineSymbolStyle::Solid, outlineColor, 7, this);
	SimpleMarkerSymbol* pSymb = new SimpleMarkerSymbol(SimpleMarkerSymbolStyle::Circle, pointColor, 10, this);
	pSymb->setOutline(pOutline);

	Graphic* pGraphic = new Graphic(p, pSymb, this);
	overlay->graphics()->append(pGraphic);
}