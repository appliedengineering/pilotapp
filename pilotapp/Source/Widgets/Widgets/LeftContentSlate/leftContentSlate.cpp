#include "leftContentSlate.h"

#include "../../../Utilities/utilities.h"

const float leftContentSlateWidget::widthRatio = 0.35;

leftContentSlateWidget::leftContentSlateWidget(QWidget* parent) {
	
	this->setFixedWidth(parent->width() * leftContentSlateWidget::widthRatio);

	//

	utilities::setPaletteColor(this, QPalette::Background, Qt::white);

}

leftContentSlateWidget::~leftContentSlateWidget() {

}