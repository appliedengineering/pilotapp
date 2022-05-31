#ifndef MAP_WIDGET_H_
#define MAP_WIDGET_H_

#include <vector>
#include <QWidget>
#include <QHBoxLayout>
#include <QString>
#include <QResizeEvent>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkDiskCache>
#include <QGeoView/QGVMap.h>
#include <QGeoView/QGVMapQGView.h>
#include <QGeoView/QGVCamera.h>
#include <QGeoView/QGVWidget.h>
#include <QGeoView/QGVImage.h>
#include <QGeoView/QGVLayerGoogle.h>
#include <QGeoView/QGVWidgetZoom.h>

class mapWidget : public QWidget{
    Q_OBJECT

private:

    QHBoxLayout* hBoxLayout = nullptr;

    QGVMap* mapView = nullptr;
    QGVLayer* mapLayer = nullptr;
    QGVWidgetZoom* mapViewZoomWidget = nullptr;
    QToolButton* mapCenterButton = nullptr;
    bool shouldCenterBoat = true;

    const int boatMarkerSize = 15;
    QGVImage* boatMarker = nullptr;

    QNetworkAccessManager* mapNet = nullptr;

    const QString mapCachePath = "mapCache";
    QNetworkDiskCache* mapCache = nullptr;

    double boatMapScale = 1.0;
    double boatLat = 0;
    double boatLon = 0;

    //

    void resizeEvent(QResizeEvent*);

    void setupMapView();
    void setupMapWidgets();
    void setupBoatMarker();
    void setDefaultMapCamera();
    void setBoatMapCamera();

    void handleCenterMapButton();
    void centerMap();
    void updateBoatMarker();

    bool isBoatDataValid();

    QString readMapFile();
    void parseMapData(QString raw, QGVCameraActions* camera);

    /*void setupMapFromMmpk();

    void renderGraphics(Esri::ArcGISRuntime::GraphicsOverlay* overlay, bool shouldOnlyRenderBoat = false);
    Esri::ArcGISRuntime::Graphic* drawPoint(Esri::ArcGISRuntime::GraphicsOverlay* overlay, double lat, double lon, QColor pointColor = Qt::blue, QColor outlineColor = Qt::white);

    std::vector<std::pair<double, double>> loadBuoyCoordinates();*/

public:
    mapWidget(QWidget* parent = nullptr);
    ~mapWidget();

public slots:
    void updateBoatLocation(double lat, double lon);
};

#endif