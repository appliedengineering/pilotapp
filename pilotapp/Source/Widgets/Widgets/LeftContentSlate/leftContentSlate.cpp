#include "leftContentSlate.h"

#include "../../../Utilities/utilities.h"

leftContentSlateWidget::leftContentSlateWidget(QWidget* parent) {
	
	this->setMaximumWidth(parent->width() * widthRatio);

	//

	utilities::setPaletteColor(this, QPalette::Background, Qt::white);

}

leftContentSlateWidget::~leftContentSlateWidget() {

}