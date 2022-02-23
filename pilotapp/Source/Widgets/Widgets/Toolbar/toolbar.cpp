#include "toolbar.h"

#include "../../../Utilities/utilities.h"

toolbarWidget::toolbarWidget(QWidget* parent) {

	this->setMaximumHeight(parent->height() * heightRatio);

	//

	utilities::setBackgroundColor(this, Qt::black);

}

toolbarWidget::~toolbarWidget() {

}