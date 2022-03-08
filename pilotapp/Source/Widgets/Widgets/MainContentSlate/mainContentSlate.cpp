#include "mainContentSlate.h"

#include "../../../Utilities/utilities.h"

#include "ContentWidgets/Environment/environmentWidget.h"
#include "ContentWidgets/Map/mapWidget.h"
#include "ContentWidgets/Power/powerWidget.h"
#include "ContentWidgets/Screen/screenWidget.h"
#include "ContentWidgets/Settings/settingsWidget.h"
#include "ContentWidgets/Telemetry/telemetryWidget.h"
#include "ContentWidgets/Voice/voiceWidget.h"

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
	
}

//

void mainContentSlateWidget::createContentWidgetForIndex(int index){
	
	if (contentWidget != nullptr){
		hideContentWidget();
	}

	switch (index)
	{
	case 1:
		contentWidget = new voiceWidget(this);
		break;

	case 2:
		contentWidget = new screenWidget(this);
		break;

	case 3:
		contentWidget = new powerWidget(this);
		break;

	case 4:
		contentWidget = new environmentWidget(this);
		break;

	case 5:
		contentWidget = new telemetryWidget(this);
		break;

	case 6:
		contentWidget = new settingsWidget(this);
		break;
	
	default:
		qWarning() << "invalid index for content widget creation";
		break;
	}

	contentWidget->setParent(this);
}

void mainContentSlateWidget::showContentWidget(int index){
	qInfo() << "show";

	createContentWidgetForIndex(index);

	//

	if (contentWidget->getContentWidgetType() == fullscreen){ // size is determined by widget unless its fullscreen
		contentWidget->move(contentWidgetHorizontalPadding, contentWidgetVerticalPadding);	
		contentWidget->setFixedSize(this->width() - 2*contentWidgetHorizontalPadding, this->height() - contentWidgetVerticalPadding);
		
		utilities::setWidgetRoundedCorner(contentWidget, 10, {utilities::bottomLeft, utilities::bottomRight});
	}

	contentWidget->show();
}

void mainContentSlateWidget::hideContentWidget(){

	if (contentWidget == nullptr){
		return;
	}

	qInfo() << "hide";

	contentWidget->hide();

	delete contentWidget;

	contentWidget = nullptr;
}

void mainContentSlateWidget::updateToWidgetIndex(int index){
	//qInfo() << "index " << index;

	if (index > 6 || index < 0){
		qWarning() << "Invalid updateWidget index called " << index;
		return;
	}

	if (!index){ // index  == 0

		hideContentWidget();

	}
	else{

		showContentWidget(index);

	}
}
