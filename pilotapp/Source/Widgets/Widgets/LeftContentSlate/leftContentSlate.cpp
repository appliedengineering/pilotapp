#include "leftContentSlate.h"

#include "../../../Backend/Utilities/utilities.h"
#include "../../../Backend/boatKernel.h"

#include <QDebug>
#include <cmath>

const float leftContentSlateWidget::widthRatio = 0.35;

leftContentSlateWidget::leftContentSlateWidget(QWidget* parent) {
	
	this->setFixedWidth(parent->width() * leftContentSlateWidget::widthRatio);
	utilities::setPaletteColor(this, QPalette::Background, Qt::white);

	//

	setupLayout();

	renderTopContent();
	renderBottomContent();

	//
	
	connect(boatKernel::getInstance(), &boatKernel::throttleUpdateSignal, this, &leftContentSlateWidget::updateThrottle);
	connect(boatKernel::getInstance(), &boatKernel::dutyUpdateSignal, this, &leftContentSlateWidget::updateDuty);
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

	speedometerLabel->setText("0");
	speedometerLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
	speedometerLabel->setContentsMargins(0, 0, 0, 0);

	QFont speedometerLabelFont = speedometerLabel->font();
	speedometerLabelFont.setBold(true);
	//speedometerLabelFont.setPointSize(45);
	speedometerLabelFont.setPixelSize(45);
	speedometerLabelFont.setStyleStrategy(QFont::PreferAntialias);
	//speedometerLabelFont.setLetterSpacing(QFont::AbsoluteSpacing, 0.5);
	speedometerLabel->setFont(speedometerLabelFont);

	//utilities::setPaletteColor(speedometerLabel, QPalette::Text, Qt::black, true);
	//utilities::setPaletteColor(speedometerLabel, QPalette::Background, Qt::black, true);
	utilities::setPaletteColor(speedometerLabel, QPalette::Foreground, Qt::black, true);

	topContentVBoxLayout->addWidget(speedometerLabel, speedometerLabelStretchFactor);

	//

	topContentBottomHBoxLayout = new QHBoxLayout();
	topContentBottomHBoxLayout->setContentsMargins(0, 0, 0, 0);

	topContentVBoxLayout->addLayout(topContentBottomHBoxLayout, 100 - speedometerLabelStretchFactor);

	//

	speedometerUnitLabel = new QLabel(topContent);

	speedometerUnitLabel->setText("knots");
	speedometerUnitLabel->setAlignment(Qt::AlignCenter);

	//utilities::setPaletteColor(speedometerUnitLabel, QPalette::Text, Qt::gray, true);
	//utilities::setPaletteColor(speedometerUnitLabel, QPalette::Background, Qt::gray, true);
	utilities::setPaletteColor(speedometerUnitLabel, QPalette::Foreground, Qt::gray, true);

	QFont speedometerUnitLabelFont = speedometerUnitLabel->font();
	//speedometerUnitLabelFont.setBold(true);
	//speedometerUnitLabelFont.setPointSize(10);
	speedometerUnitLabelFont.setPixelSize(10);
	speedometerUnitLabel->setFont(speedometerUnitLabelFont);

	topContentBottomHBoxLayout->addWidget(speedometerUnitLabel);

	//

	topContentBatteryWidget = new QWidget(topContent);

	topContentBatteryWidget->setContentsMargins(0, 0, 0, 0);

	renderBatteryWidget();

	//utilities::setPaletteColor(topContentBatteryWidget, QPalette::Background, Qt::white);

	//topContentHBoxLayout->addWidget(topContentBatteryWidget, topContentBatteryWidgetStretchFactor);*/
	
}

void leftContentSlateWidget::renderBottomContent(){
	//utilities::setPaletteColor(this->bottomContent, QPalette::Background, Qt::gray);
	bottomContentHBoxLayout = new QHBoxLayout(bottomContent);

	int contentPadding = 10;

	bottomContentHBoxLayout->setContentsMargins(contentPadding, contentPadding, contentPadding, contentPadding);
	bottomContentHBoxLayout->setSpacing(contentPadding);

	///

	int bottomContentBarWidth = 32;

	bottomContentBarVBoxLayout = new QVBoxLayout();

	bottomContentBarVBoxLayout->setContentsMargins(0, 0, 0, 0);
	bottomContentBarVBoxLayout->setSpacing(0);

	bottomContentHBoxLayout->addLayout(bottomContentBarVBoxLayout);

	//

	// Bar labels go here

	bottomContentBarLabelHBoxLayout = new QHBoxLayout();

	bottomContentBarLabelHBoxLayout->setContentsMargins(0, 0, 0, 0);
	bottomContentBarLabelHBoxLayout->setSpacing(contentPadding);

	bottomContentBarVBoxLayout->addLayout(bottomContentBarLabelHBoxLayout);

	const int bottomContentBarLabelSize = 13;

	//

	throttleBarLabel = new QLabel(bottomContent);

	throttleBarLabel->setText("T");
	utilities::setPaletteColor(throttleBarLabel, QPalette::Foreground, Qt::black, true);
	throttleBarLabel->setAlignment(Qt::AlignCenter);
	throttleBarLabel->setFixedWidth(35);

	QFont throttleBarLabelFont = throttleBarLabel->font();
	throttleBarLabelFont.setBold(true);
	throttleBarLabelFont.setPixelSize(bottomContentBarLabelSize);
	throttleBarLabelFont.setStyleStrategy(QFont::PreferAntialias);
	throttleBarLabel->setFont(throttleBarLabelFont);

	//utilities::setPaletteColor(throttleBarLabel, QPalette::Background, Qt::gray);

	bottomContentBarLabelHBoxLayout->addWidget(throttleBarLabel);

	//

	dutyBarLabel = new QLabel(bottomContent);

	dutyBarLabel->setText("D");
	utilities::setPaletteColor(dutyBarLabel, QPalette::Foreground, Qt::black, true);
	dutyBarLabel->setAlignment(Qt::AlignCenter);
	dutyBarLabel->setFixedWidth(bottomContentBarWidth);

	QFont dutyBarLabelFont = dutyBarLabel->font();
	dutyBarLabelFont.setBold(true);
	dutyBarLabelFont.setPixelSize(bottomContentBarLabelSize);
	dutyBarLabelFont.setStyleStrategy(QFont::PreferAntialias);
	dutyBarLabel->setFont(dutyBarLabelFont);

	//utilities::setPaletteColor(dutyBarLabel, QPalette::Background, Qt::gray);

	bottomContentBarLabelHBoxLayout->addWidget(dutyBarLabel);

	//

	bottomContentBarHBoxLayout = new QHBoxLayout();

	bottomContentBarHBoxLayout->setContentsMargins(0, 0, 0, 0);
	bottomContentBarHBoxLayout->setSpacing(contentPadding);

	bottomContentBarVBoxLayout->addLayout(bottomContentBarHBoxLayout);

	//

	throttleBar = new QProgressBar(bottomContent);

	//throttleBar->setContentsMargins(contentPadding, contentPadding, contentPadding, contentPadding);

	throttleBar->setOrientation(Qt::Vertical);
	throttleBar->setMinimum(0);
	throttleBar->setMaximum(100);
	throttleBar->setTextVisible(false);
	throttleBar->setFixedWidth(bottomContentBarWidth);

	throttleBar->setValue(0);

	/*utilities::setPaletteColor(throttleBar, QPalette::Highlight, Qt::black, true);
	utilities::setPaletteColor(throttleBar, QPalette::Foreground, Qt::gray, true);
	utilities::setPaletteColor(throttleBar, QPalette::Background, Qt::white);*/
	//utilities::setPaletteColor(throttleBar, QPalette::Background, Qt::gray);

	bottomContentBarHBoxLayout->addWidget(throttleBar);
	
	//

	dutyBar = new QProgressBar(bottomContent);

	//dutyBar->setContentsMargins(contentPadding, contentPadding, contentPadding, contentPadding);

	dutyBar->setOrientation(Qt::Vertical);
	dutyBar->setMinimum(0);
	dutyBar->setMaximum(180);
	dutyBar->setTextVisible(false);
	dutyBar->setFixedWidth(bottomContentBarWidth);

	dutyBar->setValue(0);

	//utilities::setPaletteColor(dutyBar, QPalette::Background, Qt::gray);

	bottomContentBarHBoxLayout->addWidget(dutyBar);
	
	//
	// Bar Percentage Labels go here

	bottomContentBarPercentLabelHBoxLayout = new QHBoxLayout();

	bottomContentBarPercentLabelHBoxLayout->setContentsMargins(0, 0, 0, 0);
	bottomContentBarPercentLabelHBoxLayout->setSpacing(contentPadding);

	bottomContentBarVBoxLayout->addLayout(bottomContentBarPercentLabelHBoxLayout);
	
	//

	const int bottomContentBarPercentLabelSize = 13;

	//

	throttleBarPercentLabel = new QLabel(bottomContent);

	throttleBarPercentLabel->setText("0%");
	utilities::setPaletteColor(throttleBarPercentLabel, QPalette::Foreground, Qt::black, true);
	throttleBarPercentLabel->setAlignment(Qt::AlignCenter);
	//throttleBarPercentLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	//throttleBarPercentLabel->setWordWrap(false);
	throttleBarPercentLabel->setFixedWidth(bottomContentBarWidth);

	QFont throttleBarPercentLabelFont = throttleBarPercentLabel->font();
	throttleBarPercentLabelFont.setPixelSize(bottomContentBarPercentLabelSize);
	throttleBarPercentLabel->setFont(throttleBarPercentLabelFont);

	//utilities::setPaletteColor(throttleBarPercentLabel, QPalette::Background, Qt::gray);

	bottomContentBarPercentLabelHBoxLayout->addWidget(throttleBarPercentLabel);

	//

	dutyBarPercentLabel = new QLabel(bottomContent);

	dutyBarPercentLabel->setText("0%");
	utilities::setPaletteColor(dutyBarPercentLabel, QPalette::Foreground, Qt::black, true);
	dutyBarPercentLabel->setAlignment(Qt::AlignCenter);
	//dutyBarPercentLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	dutyBarPercentLabel->setFixedWidth(bottomContentBarWidth);

	QFont dutyBarPercentLabelFont = dutyBarPercentLabel->font();
	dutyBarPercentLabelFont.setPixelSize(bottomContentBarPercentLabelSize);
	dutyBarPercentLabel->setFont(dutyBarPercentLabelFont);
	//utilities::setPaletteColor(dutyBarPercentLabel, QPalette::Background, Qt::gray);

	bottomContentBarPercentLabelHBoxLayout->addWidget(dutyBarPercentLabel);

	///
	// Model Label

	bottomContentModelVBoxLayout = new QVBoxLayout();

	bottomContentModelVBoxLayout->setContentsMargins(contentPadding, 0, contentPadding, 0);
	bottomContentModelVBoxLayout->setSpacing(contentPadding);
	bottomContentModelVBoxLayout->setAlignment(Qt::AlignHCenter);

	bottomContentHBoxLayout->addLayout(bottomContentModelVBoxLayout);

	//

	modelLabel = new QLabel(bottomContent);

	//modelLabel->setContentsMargins(contentPadding, 0, contentPadding, 0);

	QPixmap modelPixMap(":/Assets/Model/topdownboat.png");
	double modelWidthToHeightRatio = modelPixMap.height() / modelPixMap.width();

	modelPixMap.scaled(modelLabel->width(), modelLabel->width() * modelWidthToHeightRatio, Qt::KeepAspectRatio);

	modelLabel->setPixmap(modelPixMap);
	modelLabel->setScaledContents(1);

	bottomContentModelVBoxLayout->addWidget(modelLabel);

	//utilities::setPaletteColor(modelLabel, QPalette::Background, Qt::gray);

	//

	motorButton = new QPushButton(bottomContent);

	updateMotorButtonStatus();

	//motorButton->setText("Stop Motor");
    utilities::setPaletteColor(motorButton, QPalette::ButtonText, Qt::black);
	//motorButton->setContentMargins(contentPadding, 0, contentPadding, 0);

	connect(motorButton, &QPushButton::released, this, &leftContentSlateWidget::handleMotorButton);
	connect(boatKernel::getInstance(), &boatKernel::motorStatusUpdateSignal, this, &leftContentSlateWidget::updateMotorButtonStatus);

	QFont motorButtonFont = motorButton->font();
	motorButtonFont.setPixelSize(13);
	motorButton->setFont(motorButtonFont);

	bottomContentModelVBoxLayout->addWidget(motorButton);

}

void leftContentSlateWidget::renderBatteryWidget(){

	const int topContentBatteryHBoxVerticalPadding = 2;
	const int topContentBatteryHBoxHorizontalPadding = 3;
	const int topContentBatteryLabelFontSize = 10;

	topContentBatteryWidgetHBoxLayout = new QHBoxLayout(topContentBatteryWidget);

	topContentBatteryWidgetHBoxLayout->setContentsMargins(topContentBatteryHBoxHorizontalPadding, topContentBatteryHBoxVerticalPadding, topContentBatteryHBoxHorizontalPadding, topContentBatteryHBoxVerticalPadding);
	topContentBatteryWidgetHBoxLayout->setSpacing(2);

	//

	topContentBatteryPercentLabel = new QLabel(topContentBatteryWidget);

	topContentBatteryPercentLabel->setText("0%");
	utilities::setPaletteColor(topContentBatteryPercentLabel, QPalette::Foreground, Qt::darkGray, true);
	topContentBatteryPercentLabel->setAlignment(Qt::AlignVCenter | Qt::AlignRight);

	QFont topContentBatteryPercentLabelFont = topContentBatteryPercentLabel->font();
	topContentBatteryPercentLabelFont.setPixelSize(topContentBatteryLabelFontSize);
	topContentBatteryPercentLabel->setFont(topContentBatteryPercentLabelFont);

	topContentBatteryWidgetHBoxLayout->addWidget(topContentBatteryPercentLabel);

	//

	topContentBatteryPercentBar = new QProgressBar(topContentBatteryWidget);
	
	topContentBatteryPercentBar->setOrientation(Qt::Horizontal);
	topContentBatteryPercentBar->setMinimum(0);
	topContentBatteryPercentBar->setMaximum(100);
	topContentBatteryPercentBar->setTextVisible(false);
	//topContentBatteryPercentBar->setFixedWidth(bottomContentBarWidth);

	topContentBatteryPercentBar->setValue(0);

	topContentBatteryWidgetHBoxLayout->addWidget(topContentBatteryPercentBar);

	//

	/*topContentBatteryVoltageLabel = new QLabel(topContentBatteryWidget);

	topContentBatteryVoltageLabel->setText("0 V");
	utilities::setPaletteColor(topContentBatteryVoltageLabel, QPalette::Foreground, Qt::black, true);
	topContentBatteryVoltageLabel->setAlignment(Qt::AlignHCenter);

	QFont topContentBatteryVoltageLabelFont = topContentBatteryVoltageLabel->font();
	topContentBatteryVoltageLabelFont.setPixelSize(topContentBatteryLabelFontSize);
	topContentBatteryVoltageLabel->setFont(topContentBatteryVoltageLabelFont);

	topContentBatteryWidgetHBoxLayout->addWidget(topContentBatteryVoltageLabel);

	

	topContentBatteryCurrentLabel = new QLabel(topContentBatteryWidget);

	topContentBatteryCurrentLabel->setText("0 A");
	utilities::setPaletteColor(topContentBatteryCurrentLabel, QPalette::Foreground, Qt::black, true);
	topContentBatteryCurrentLabel->setAlignment(Qt::AlignHCenter);

	QFont topContentBatteryCurrentLabelFont = topContentBatteryCurrentLabel->font();
	topContentBatteryCurrentLabelFont.setPixelSize(topContentBatteryLabelFontSize);
	topContentBatteryCurrentLabel->setFont(topContentBatteryCurrentLabelFont);

	topContentBatteryWidgetVBoxLayout->addWidget(topContentBatteryCurrentLabel);*/
}

//

void leftContentSlateWidget::resizeEvent(QResizeEvent*){
	//qInfo() << "resize -> " << topContent->size();

	//

	const float topContentBatteryWidgetHeightToWidthRatio = 4;
	const int topContentBatteryWidgetHeight = speedometerUnitLabel->height() * 0.6;
	const int topContentBatteryWidgetWidth = topContentBatteryWidgetHeight * topContentBatteryWidgetHeightToWidthRatio;
	topContentBatteryWidget->setGeometry(topContent->width() - topContentBatteryWidgetWidth, topContent->height() - topContentBatteryWidgetHeight, topContentBatteryWidgetWidth, topContentBatteryWidgetHeight);
	topContentBatteryPercentLabel->setFixedWidth(topContentBatteryWidget->width() * 0.36);
}

//

void leftContentSlateWidget::updateSpeedLabel(double speed){
	if (speedometerLabel != nullptr)
		speedometerLabel->setText(QString::number(round(speed)));
}

void leftContentSlateWidget::updateThrottle(int percent){
	if (throttleBar != nullptr){
		if (percent >= 0 && percent <= 100){
			throttleBar->setValue(percent);
			throttleBarPercentLabel->setText(QString::number(percent) + "%");
		}
		else
			qInfo() << "Invalid throttle percent recvd - " << percent;
	}
}

void leftContentSlateWidget::updateDuty(int percent){
	if (dutyBar != nullptr){
		if (percent >= 0 && percent <= 100){
			dutyBar->setValue(percent);
			dutyBarPercentLabel->setText(QString::number(percent) + "%");
		}
		else
			qInfo() << "Invalid duty percent recvd - " << percent;
	}
}

void leftContentSlateWidget::handleMotorButton(){
	//qInfo() << "motor";
	boatKernel::getInstance()->toggleMotor();
	updateMotorButtonStatus();
}

void leftContentSlateWidget::updateMotorButtonStatus(){
	if (boatKernel::getInstance()->getIsMotorEnabled()){
		this->motorButton->setText("Stop Motor");
	}
	else{
		this->motorButton->setText("Start Motor");
	}
}