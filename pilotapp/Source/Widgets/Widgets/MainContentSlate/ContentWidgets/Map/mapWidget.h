#ifndef MAP_WIDGET_H_
#define MAP_WIDGET_H_

#include <QWidget>
#include <QHBoxLayout>

namespace Esri{
    namespace ArcGISRuntime{
        class Map;
        class MapGraphicsView;
    }
}

class mapWidget : public QWidget{
    Q_OBJECT

private:
    QHBoxLayout* hBoxLayout = nullptr;
    Esri::ArcGISRuntime::Map* arcGISMap = nullptr;
    Esri::ArcGISRuntime::MapGraphicsView* arcGISMapView = nullptr;
public:
    mapWidget(QWidget* parent = nullptr);
    ~mapWidget();
};

#endif