#ifndef MAP_WIDGET_H_
#define MAP_WIDGET_H_

#include <QWidget>
#include <QHBoxLayout>
#include <QString>

namespace Esri{
    namespace ArcGISRuntime{
        class Map;
        class MapGraphicsView;
        class Viewpoint;
    }
}

class mapWidget : public QWidget{
    Q_OBJECT

private:
    QHBoxLayout* hBoxLayout = nullptr;
    Esri::ArcGISRuntime::Map* arcGISMap = nullptr;
    Esri::ArcGISRuntime::MapGraphicsView* arcGISMapView = nullptr;

    QString readMapFile();
    Esri::ArcGISRuntime::Viewpoint parseMapData(QString raw);
    void setMapCenter(Esri::ArcGISRuntime::Viewpoint center);
public:
    mapWidget(QWidget* parent = nullptr);
    ~mapWidget();
};

#endif