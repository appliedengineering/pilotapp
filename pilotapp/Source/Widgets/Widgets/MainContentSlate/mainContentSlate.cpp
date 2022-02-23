#include "mainContentSlate.h"

#include "../../../Utilities/utilities.h"

mainContentSlateWidget::mainContentSlateWidget(QWidget* parent) {
	
	this->setMaximumWidth(parent->width() * widthRatio);

	//
	
	utilities::setBackgroundColor(this, Qt::gray);
}

mainContentSlateWidget::~mainContentSlateWidget() {

}