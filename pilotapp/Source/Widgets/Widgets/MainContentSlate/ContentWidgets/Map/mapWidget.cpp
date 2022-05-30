#include "mapWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"
#include "../../../../../Backend/boatKernel.h"

#include <QDir>
#include <QFile>
#include <QDebug>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

mapWidget::mapWidget(QWidget* parent){
	utilities::setPaletteColor(this, QPalette::Background, Qt::white);

	//
	
	hBoxLayout = new QHBoxLayout(this);
	hBoxLayout->setContentsMargins(0, 0, 0, 0);
	hBoxLayout->setSpacing(0);
	this->setLayout(hBoxLayout);

	//

	setupMapView();

	//

	connect(boatKernel::getInstance(), &boatKernel::locationUpdateSignal, this, &mapWidget::updateBoatLocation);
}

mapWidget::~mapWidget(){
}

void mapWidget::setupMapView(){

	mapView = new QGVMap(this);
	mapView->setContentsMargins(0, 0, 0, 0);
	mapView->layout()->setContentsMargins(0, 0, 0, 0);
	mapView->geoView()->setContentsMargins(0, 0, 0, 0);
	hBoxLayout->addWidget(mapView);

	//utilities::setPaletteColor(mapView, QPalette::Background, Qt::red);

	//

	QDir(mapCachePath).removeRecursively();

	mapCache = new QNetworkDiskCache(this);
	mapCache->setCacheDirectory(mapCachePath);

	//
	
	mapNet = new QNetworkAccessManager(this);
	mapNet->setCache(mapCache);
	QGV::setNetworkManager(mapNet);

	//

	mapLayer = new QGVLayerGoogle(QGV::TilesType::Satellite);
	mapView->addItem(mapLayer);
	mapLayer->setVisible(true);

	//

	setDefaultMapCamera();
}

//

void mapWidget::updateBoatLocation(double lat, double lon){
	boatLat = lat;
	boatLon = lon;
	//qInfo() << "update boat location - " << lat << " " << lon;
	//renderGraphics(arcGISOverlay, true);
}

//

void mapWidget::setDefaultMapCamera(){
	// set mapview zoom to view entire world
	/*auto t = mapView->getProjection()->boundaryGeoRect();
	mapView->cameraTo(QGVCameraActions(mapView).scaleTo(t));*/

	/*QGVCameraActions mapViewArea(mapView);
	mapViewArea.moveTo(QGV::GeoPos(38.335253, -121.091880));
	mapViewArea.scaleTo(0.6);*/

	QString mapFileRaw = readMapFile();
	QGVCameraActions camera(mapView);

	if (!mapFileRaw.isEmpty()){
		parseMapData(mapFileRaw, &camera);
	}
	
	mapView->cameraTo(camera);
}

QString mapWidget::readMapFile(){
	QFile mapFile("navcenter.txt");
	
	if (mapFile.open(QIODevice::ReadOnly | QIODevice::Text)){
		QString data = mapFile.readAll();
	   	qDebug() << "Opened map data file (navcenter.txt) - " << data;
	   	return data;
	}
	
	qInfo() << "No map data file found (navcenter.txt)";
	return "";
}

void mapWidget::parseMapData(QString raw, QGVCameraActions* camera){
	std::string r = raw.toStdString();
	
	std::vector<std::string> sArray;
	std::stringstream stream(r);

	while (stream.good()){
		std::string substr;
		getline(stream, substr, ',');
		sArray.push_back(substr);
	}

	if (sArray.size() != 3){
		qInfo() << ("Map data is invalid");
		return;
	}

	double latitude = std::stod(sArray[0]), longitude = std::stod(sArray[1]), scale = std::stod(sArray[2]); // default scale is 100000.0
	
	/*Point centerPoint(longitude, latitude, SpatialReference::wgs84());

	return Viewpoint(centerPoint, scale);*/

	camera->moveTo(QGV::GeoPos(latitude, longitude));
	camera->scaleTo(scale);
}

/*void mapWidget::setupMapFromMmpk(){
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