#ifndef MAP_WIDGET_H_
#define MAP_WIDGET_H_

#include <QWidget>

class mapWidget : public QWidget{
    Q_OBJECT

private:

public:
    mapWidget(QWidget* parent = nullptr);
    ~mapWidget();
};

#endif