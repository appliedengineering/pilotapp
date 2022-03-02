#include "settingsWidget.h"

#include "../../../../../Utilities/utilities.h"

settingsWidget::settingsWidget(QWidget* parent){
    qInfo() << "settings - " << parent->size();

    this->setFixedSize(20, 20);

	utilities::setPaletteColor(this, QPalette::Background, Qt::black);
}

settingsWidget::~settingsWidget(){

}

//