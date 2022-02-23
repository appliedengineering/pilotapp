#include "leftContentSlate.h"

#include "../../../Utilities/utilities.h"

leftContentSlateWidget::leftContentSlateWidget(QWidget* parent) {
	
	this->setMaximumWidth(parent->width() * widthRatio);

	//

	utilities::setBackgroundColor(this, Qt::white);

}

leftContentSlateWidget::~leftContentSlateWidget() {

}