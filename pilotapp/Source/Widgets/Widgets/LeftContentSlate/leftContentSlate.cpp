#include "leftContentSlate.h"

#include "../../../Utilities/utilities.h"

const float leftContentSlateWidget::widthRatio = 0.35;

leftContentSlateWidget::leftContentSlateWidget(QWidget* parent) {
	
	this->setFixedWidth(parent->width() * leftContentSlateWidget::widthRatio);
	utilities::setPaletteColor(this, QPalette::Background, Qt::white);

	//

	setupLayout();

}

leftContentSlateWidget::~leftContentSlateWidget() {
}

//

void leftContentSlateWidget::setupLayout(){
	mainVBoxLayout = new QVBoxLayout(this);
	mainVBoxLayout->setContentsMargins(0, 0, 0, 0);
	mainVBoxLayout->setSpacing(0);

	//

	const int topContentStretchFactor = 30;
	topContent = new QWidget(this);
	utilities::setPaletteColor(topContent, QPalette::Background, Qt::black);

	mainVBoxLayout->addWidget(topContent, topContentStretchFactor); // 30 percent stretch

	//

	bottomContent = new QWidget(this);
	
	mainVBoxLayout->addWidget(bottomContent, 100-topContentStretchFactor);

	//

}