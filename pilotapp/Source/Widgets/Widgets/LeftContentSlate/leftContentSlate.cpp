#include "leftContentSlate.h"

#include "../../../Utilities/utilities.h"

const float leftContentSlateWidget::widthRatio = 0.38;

leftContentSlateWidget::leftContentSlateWidget(QWidget* parent) {
	
	this->setFixedWidth(parent->width() * leftContentSlateWidget::widthRatio);

	//

	utilities::setPaletteColor(this, QPalette::Background, Qt::white);

}

leftContentSlateWidget::~leftContentSlateWidget() {

}