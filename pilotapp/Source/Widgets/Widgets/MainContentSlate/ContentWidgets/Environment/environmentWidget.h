#ifndef ENVIRONMENT_WIDGET_H_
#define ENVIRONMENT_WIDGET_H_

#include <QWidget>
#include "../../contentWidget.h"

class environmentWidget : public ContentWidget{
    Q_OBJECT

private:

public:
    environmentWidget(QWidget* parent = nullptr);
    ~environmentWidget();

};

#endif