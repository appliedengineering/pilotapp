#include "mapWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"
#include "../../../../../Backend/boatKernel.h"

#include <QDir>
#include <QFile>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

/*#include <ArcGISRuntimeEnvironment.h>
#include <Map.h>
#include <Basemap.h>
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
#include <SimpleMarkerSymbol.h>*/

//using namespace Esri::ArcGISRuntime;

mapWidget::mapWidget(QWidget* parent){
	utilities::setPaletteColor(this, QPalette::Background, Qt::gray);

	//
	
	hBoxLayout = new QHBoxLayout(this);
	hBoxLayout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(hBoxLayout);

	//

	mapView = new QQuickView();

	mapViewContainer = QWidget::createWindowContainer(mapView, this);
	hBoxLayout->addWidget(mapViewContainer);

	mapView->setSource(QUrl("qrc:/Source/Widgets/Widgets/MainContentSlate/ContentWidgets/Map/mapView.qml"));
	
	//

	QWidget* w = new QWidget(this);
	utilities::setPaletteColor(w, QPalette::Background, Qt::black);
	w->setGeometry(0, 0, 100, 100);


    /*
	//arcGISMap = new Map(Basemap::imageryWithLabels(this), this);
	arcGISMapView = new MapGraphicsView(nullptr, this);

	hBoxLayout->addWidget(arcGISMapView);

	//

	setupMapFromMmpk();
	//setMapCenter(parseMapData(readMapFile()));

	//arcGISMapView->map()->basemap()->

	//

	arcGISOverlay = new GraphicsOverlay(this);
	renderGraphics(arcGISOverlay);
	arcGISMapView->graphicsOverlays()->append(arcGISOverlay);*/

	connect(boatKernel::getInstance(), &boatKernel::locationUpdateSignal, this, &mapWidget::updateBoatLocation);
}

mapWidget::~mapWidget(){
}

//

void mapWidget::updateBoatLocation(double lat, double lon){
	boatLat = lat;
	boatLon = lon;
	//qInfo() << "update boat location - " << lat << " " << lon;
	//renderGraphics(arcGISOverlay, true);
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
}

void mapWidget::setupMapFromMmpk(){
	QString mmpkPath = QDir::currentPath() + "/map.mmpk";

	//qDebug() << "mmpk path" << mmpkPath;

	MobileMapPackage* mappackage = new MobileMapPackage(mmpkPath, this);

	connect(mappackage, &MobileMapPackage::doneLoading, this, [mappackage, this](Error error){
		if (!error.isEmpty()){
			qDebug() << "Error: " << error.message() << error.additionalMessage();
			return;
		}

		//qDebug() << "finished loading mmpk - " << mappackage->maps().size() << " ";

		arcGISMapView->setMap(mappackage->maps().at(0));
		
		//qDebug() << arcGISMapView->map() << " " << arcGISMapView->map()->basemap();
	});

	//qDebug() << "starting to load mmpk";

	mappackage->load();
}

void mapWidget::renderGraphics(Esri::ArcGISRuntime::GraphicsOverlay* overlay, bool shouldOnlyRenderBoat){
	if (!shouldOnlyRenderBoat)
		overlay->graphics()->clear();

	//

	if (boatPoint != nullptr){
		//qInfo() << "existing boatPoint";
		for (int i = 0; i < overlay->graphics()->size(); i++){
			if (overlay->graphics()->at(i) == boatPoint){
				//qInfo() << "found boatPoint -> " << overlay->graphics()->size();
				overlay->graphics()->removeAt(i);
				break;
			}
		}
	}

	boatPoint = drawPoint(overlay, boatLat, boatLon);

	//

	if (!shouldOnlyRenderBoat){

		std::vector<std::pair<double, double>> c = loadBuoyCoordinates();

		for (std::pair<double, double> i : c)
			drawPoint(overlay, i.first, i.second, Qt::red, Qt::black);

		//qInfo() << "after loading buoys -> " << overlay->graphics()->size();

	}
}

Esri::ArcGISRuntime::Graphic* mapWidget::drawPoint(Esri::ArcGISRuntime::GraphicsOverlay* overlay, double lat, double lon, QColor pointColor, QColor outlineColor){

	Point p(lon, lat, SpatialReference::wgs84());

  	SimpleLineSymbol* pOutline = new SimpleLineSymbol(SimpleLineSymbolStyle::Solid, outlineColor, 7, this);
	SimpleMarkerSymbol* pSymb = new SimpleMarkerSymbol(SimpleMarkerSymbolStyle::Circle, pointColor, 10, this);
	pSymb->setOutline(pOutline);

	Graphic* point = new Graphic(p, pSymb, this);
	overlay->graphics()->append(point);
	return point;
}

std::vector<std::pair<double, double>> mapWidget::loadBuoyCoordinates(){
	std::ifstream coordinateFile("buoycoords.txt");

	std::vector<std::pair<double, double>> c;

	if (!coordinateFile.is_open()){
		qInfo() << "No buoy coordinate file";
		return c;
	}

	std::string fileLine;
	while (std::getline(coordinateFile, fileLine)){
		if (fileLine.empty())
			continue;
		
		std::istringstream iss(fileLine);
		double x, y;
		if (!(iss >> x >> y)){
			qDebug() << "error parsing line " << QString::fromStdString(fileLine) << " in buoycoords.txt"; 
			continue;
		}

		c.push_back({x, y});
	}

	return c;
}*/