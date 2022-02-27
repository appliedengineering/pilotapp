#include "mainContentSlate.h"

#include "../../../Utilities/utilities.h"

mainContentSlateWidget::mainContentSlateWidget(QWidget* parent) {

	//
	
	utilities::setPaletteColor(this, QPalette::Background, Qt::gray);

	//

	setupMapWidget();
}

mainContentSlateWidget::~mainContentSlateWidget() {

}

//

void mainContentSlateWidget::setupMapWidget(){
	map = new mapWidget(this);

	//

	map->move(0, 0);
	map->resize(QSize(this->width(), this->height()));
	map->setFixedSize(QSize(this->width(), this->height()));
	
}

