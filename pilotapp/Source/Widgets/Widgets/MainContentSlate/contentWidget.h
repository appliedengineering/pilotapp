#ifndef CONTENT_WIDGET_H_
#define CONTENT_WIDGET_H_

#include <QWidget>

enum ContentWidgetType{
    fullscreen,
    windowed
};

class ContentWidget : public QWidget{
    Q_OBJECT

private:
    ContentWidgetType widgetType;

public:

};

#endif