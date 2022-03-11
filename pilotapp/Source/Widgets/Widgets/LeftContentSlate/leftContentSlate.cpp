#include "leftContentSlate.h"

#include "../../../Utilities/utilities.h"

const float leftContentSlateWidget::widthRatio = 0.35;

leftContentSlateWidget::leftContentSlateWidget(QWidget* parent) {
	
	this->setFixedWidth(parent->width() * leftContentSlateWidget::widthRatio);
	utilities::setPaletteColor(this, QPalette::Background, Qt::white);

	//

	setupLayout();

	renderTopContent();
	renderBottomContent();

}

leftContentSlateWidget::~leftContentSlateWidget() {
}

//

void leftContentSlateWidget::setupLayout(){
	mainVBoxLayout = new QVBoxLayout(this);
	mainVBoxLayout->setContentsMargins(0, 0, 0, 0);
	mainVBoxLayout->setSpacing(0);

	//

	const int topContentStretchFactor = 20;
	topContent = new QWidget(this);
	//utilities::setPaletteColor(topContent, QPalette::Background, Qt::black);

	mainVBoxLayout->addWidget(topContent, topContentStretchFactor); // 30 percent stretch

	//

	const int lineContentStretchFactor = 1;
	const int lineContentHorizontalPadding = 10;
	dividerLine = new QFrame(this);

	//utilities::setPaletteColor(dividerLine, QPalette::, Qt::black);
	dividerLine->setContentsMargins(lineContentHorizontalPadding, 0, lineContentHorizontalPadding, 0);
	dividerLine->setFrameShape(QFrame::HLine);
	dividerLine->setFrameShadow(QFrame::Sunken);

	mainVBoxLayout->addWidget(dividerLine, lineContentStretchFactor);

	//

	bottomContent = new QWidget(this);

	mainVBoxLayout->addWidget(bottomContent, 100-lineContentStretchFactor-topContentStretchFactor);

	//

}

void leftContentSlateWidget::renderTopContent(){

	topContentVBoxLayout = new QVBoxLayout(topContent);

	topContentVBoxLayout->setContentsMargins(0, 0, 0, 0);
	topContentVBoxLayout->setSpacing(0);

	//

	const int speedometerLabelStretchFactor = 70;
	speedometerLabel = new QLabel(topContent);

	speedometerLabel->setText("50");
	speedometerLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	speedometerLabel->setContentsMargins(0, 0, 0, 0);

	QFont speedometerLabelFont = speedometerLabel->font();
	speedometerLabelFont.setBold(true);
	speedometerLabelFont.setPointSize(45);
	speedometerLabelFont.setStyleStrategy(QFont::PreferAntialias);
	//speedometerLabelFont.setLetterSpacing(QFont::AbsoluteSpacing, 0.5);
	speedometerLabel->setFont(speedometerLabelFont);

	utilities::setPaletteColor(speedometerLabel, QPalette::Text, Qt::black);
	utilities::setPaletteColor(speedometerLabel, QPalette::Background, Qt::white);

	topContentVBoxLayout->addWidget(speedometerLabel, speedometerLabelStretchFactor);

	//

	topContentBottomHBoxLayout = new QHBoxLayout();
	topContentBottomHBoxLayout->setContentsMargins(0, 0, 0, 0);

	topContentVBoxLayout->addLayout(topContentBottomHBoxLayout, 100 - speedometerLabelStretchFactor);

	//

	speedometerUnitLabel = new QLabel(topContent);

	speedometerUnitLabel->setText("MPH");
	speedometerUnitLabel->setAlignment(Qt::AlignCenter);

	utilities::setPaletteColor(speedometerLabel, QPalette::Text, Qt::gray);

	QFont speedometerUnitLabelFont = speedometerUnitLabel->font();
	//speedometerUnitLabelFont.setBold(true);
	speedometerUnitLabelFont.setPointSize(10);
	speedometerUnitLabel->setFont(speedometerUnitLabelFont);

	topContentBottomHBoxLayout->addWidget(speedometerUnitLabel);

	//

	
	
}

void leftContentSlateWidget::renderBottomContent(){

}