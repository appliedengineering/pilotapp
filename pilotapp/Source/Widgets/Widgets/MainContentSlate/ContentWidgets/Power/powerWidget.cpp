#include "powerWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"
#include "../../../../../Backend/boatKernel.h"

powerWidget::powerWidget(QWidget* parent){
    //this->widgetType = windowed;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    const int powerWidgetWidth = parent->width() * 0.6;
    const int powerWidgetHeight = parent->height() * 0.15;
    this->setGeometry((parent->width()/2) - (powerWidgetWidth/2), parent->height() - powerWidgetHeight, powerWidgetWidth, powerWidgetHeight);
    utilities::setWidgetRoundedCorner(this, 10, {utilities::bottomLeft, utilities::bottomRight});

    renderContent();

    //

    updateBatteryData(boatKernel::getInstance()->getBatteryVoltage(), boatKernel::getInstance()->getBatteryCurrent(), boatKernel::getInstance()->getIsSolar());

    //

    connect(boatKernel::getInstance(), &boatKernel::batteryDataUpdateSignal, this, &powerWidget::updateBatteryData);
}

powerWidget::~powerWidget(){
    disconnect(boatKernel::getInstance(), &boatKernel::batteryDataUpdateSignal, this, &powerWidget::updateBatteryData);
}

//

void powerWidget::renderContent(){
    mainContentHLayout = new QHBoxLayout(this);
    
    const int mainContentPadding = 10;

    mainContentHLayout->setContentsMargins(mainContentPadding, mainContentPadding, mainContentPadding, mainContentPadding);
    mainContentHLayout->setSpacing(0);

    ///

    powerSourceVLayout = new QVBoxLayout();

    const int powerSourcePadding = 20;
    const int powerSourceLayoutStretchFactor = 30;

    //powerSourceVLayout->setContentsMargins(powerSourcePadding, powerSourcePadding - mainContentPadding, powerSourcePadding, powerSourcePadding - mainContentPadding);
    powerSourceVLayout->setContentsMargins(0, -mainContentPadding, 0, -mainContentPadding);
    powerSourceVLayout->setSpacing(0);

    mainContentHLayout->addLayout(powerSourceVLayout, powerSourceLayoutStretchFactor);

    //

    powerSourceIconLabel = new QLabel(this);

    batteryIconPixMap = QPixmap(":/Assets/Icons/electronics.png");
    solarIconPixMap = QPixmap(":/Assets/Icons/solar.png");

	//powerSourceIconLabel->setPixmap(solarIconPixMap);
    powerSourceIconLabel->setPixmap(batteryIconPixMap.scaled(powerSourceIconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    powerSourceIconLabel->setAlignment(Qt::AlignCenter);
	//powerSourceIconLabel->setScaledContents(1);

    //utilities::setPaletteColor(powerSourceIconLabel, QPalette::Background, Qt::gray);

    powerSourceVLayout->addWidget(powerSourceIconLabel);

    ///

    dataStackVLayout = new QVBoxLayout();

    dataStackVLayout->setContentsMargins(0, 0, 0, 0);
    dataStackVLayout->setSpacing(0);

    mainContentHLayout->addLayout(dataStackVLayout, 100 - powerSourceLayoutStretchFactor);

    //

    dataValueHLayout = new QHBoxLayout();

    dataValueHLayout->setContentsMargins(0, 0, 0, 0);
    dataValueHLayout->setSpacing(0);

    dataStackVLayout->addLayout(dataValueHLayout);

    const int dataValueLabelSize = 20;

    //

    voltageValueLabel = new QLabel(this);

    voltageValueLabel->setText("0");
    utilities::setPaletteColor(voltageValueLabel, QPalette::Foreground, Qt::white, true);
    voltageValueLabel->setAlignment(Qt::AlignHCenter);

    QFont voltageValueLabelFont = voltageValueLabel->font();
	voltageValueLabelFont.setPixelSize(dataValueLabelSize);
	voltageValueLabel->setFont(voltageValueLabelFont);

    dataValueHLayout->addWidget(voltageValueLabel);

    //

    currentValueLabel = new QLabel(this);

    currentValueLabel->setText("0");
    utilities::setPaletteColor(currentValueLabel, QPalette::Foreground, Qt::white, true);
    currentValueLabel->setAlignment(Qt::AlignHCenter);

    QFont currentValueLabelFont = currentValueLabel->font();
    currentValueLabelFont.setPixelSize(dataValueLabelSize);
    currentValueLabel->setFont(currentValueLabelFont);

    dataValueHLayout->addWidget(currentValueLabel);

    //

    dataLabelHLayout = new QHBoxLayout();

    dataLabelHLayout->setContentsMargins(0, 0, 0, 0);
    dataLabelHLayout->setSpacing(0);

    dataStackVLayout->addLayout(dataLabelHLayout);

    const int dataLabelLabelSize = 10;

    //

    voltageLabelLabel = new QLabel(this);

    voltageLabelLabel->setText("Volts");
    utilities::setPaletteColor(voltageLabelLabel, QPalette::Foreground, Qt::white, true);
    voltageLabelLabel->setAlignment(Qt::AlignHCenter);

    QFont voltageLabelLabelFont = voltageLabelLabel->font();
    voltageLabelLabelFont.setPixelSize(dataLabelLabelSize);
    voltageLabelLabel->setFont(voltageLabelLabelFont);

    dataLabelHLayout->addWidget(voltageLabelLabel);

    //

    currentLabelLabel = new QLabel(this);

    currentLabelLabel->setText("Amps");
    utilities::setPaletteColor(currentLabelLabel, QPalette::Foreground, Qt::white, true);
    currentLabelLabel->setAlignment(Qt::AlignHCenter);

    QFont currentLabelLabelFont = currentLabelLabel->font();
    currentLabelLabelFont.setPixelSize(dataLabelLabelSize);
    currentLabelLabel->setFont(currentLabelLabelFont);

    dataLabelHLayout->addWidget(currentLabelLabel);

    //
}

void powerWidget::resizeEvent(QResizeEvent*){
    //mainContentHLayout->setStretchFactor(powerSourceVLayout, this->height() / this->width());
}

void powerWidget::updateBatteryData(double voltage, double current, bool isSolar){
    
    // update icon
    powerSourceIconLabel->setPixmap((isSolar ? solarIconPixMap : batteryIconPixMap).scaled(powerSourceIconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //

    voltageValueLabel->setText(QString::number(utilities::roundDouble(voltage, 1)));

    currentValueLabel->setText(QString::number(utilities::roundDouble(current, 1)));

}