#include "settingsWidget.h"

#include "../../../../../Utilities/utilities.h"

settingsWidget::settingsWidget(QWidget* parent){
    this->widgetType = fullscreen;
	utilities::setPaletteColor(this, QPalette::Background, Qt::black);
}

settingsWidget::~settingsWidget(){

}

//