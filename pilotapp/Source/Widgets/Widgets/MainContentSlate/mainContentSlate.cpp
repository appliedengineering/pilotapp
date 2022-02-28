#include "mainContentSlate.h"

#include "../../../Utilities/utilities.h"

mainContentSlateWidget::mainContentSlateWidget(QWidget* parent) {

	this->setFixedHeight(parent->height() * (1.0 - toolbarWidget::heightRatio) + 1);
	this->setFixedWidth(parent->width() * (1.0 - leftContentSlateWidget::widthRatio));
	
	//
	
	utilities::setPaletteColor(this, QPalette::Background, Qt::gray);

	//

	setupMapWidget();
}

mainContentSlateWidget::~mainContentSlateWidget() {

}

//

void mainContentSlateWidget::setupMapWidget(){
	mapLayout = new QHBoxLayout(this);
	mapLayout->setContentsMargins(0, 0, 0, 0);

	//

	map = new mapWidget(this);
	mapLayout->addWidget(map);

	map->resize(QSize(this->width(), this->height()));
	map->setFixedSize(QSize(this->width(), this->height()));

	//
	
}

void mainContentSlateWidget::updateToWidgetIndex(int index){
	//qInfo() << "index " << index;

	if (index > 6 || index < 0){
		qWarning() << "Invalid updateWidget index called " << index;
		return;
	}


}
