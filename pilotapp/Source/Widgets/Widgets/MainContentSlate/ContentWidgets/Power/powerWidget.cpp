#include "powerWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

#include <QPixmap>

powerWidget::powerWidget(QWidget* parent){
    //this->widgetType = windowed;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    const int powerWidgetWidth = parent->width() * 0.6;
    const int powerWidgetHeight = parent->height() * 0.15;
    this->setGeometry((parent->width()/2) - (powerWidgetWidth/2), parent->height() - powerWidgetHeight, powerWidgetWidth, powerWidgetHeight);
    utilities::setWidgetRoundedCorner(this, 10, {utilities::bottomLeft, utilities::bottomRight});

    renderContent();
}

powerWidget::~powerWidget(){
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

    powerSourceVLayout->setContentsMargins(powerSourcePadding, powerSourcePadding - mainContentPadding, powerSourcePadding, powerSourcePadding - mainContentPadding);
    powerSourceVLayout->setSpacing(0);

    mainContentHLayout->addLayout(powerSourceVLayout, powerSourceLayoutStretchFactor);

    //

    powerSourceIconLabel = new QLabel(this);

    QPixmap iconPixMap(":/Assets/Icons/electronics.png");

	iconPixMap.scaled(powerSourceIconLabel->width(), powerSourceIconLabel->width() * 0.8, Qt::KeepAspectRatio);

	powerSourceIconLabel->setPixmap(iconPixMap);
	powerSourceIconLabel->setScaledContents(1);

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

    voltageValueLabel->setText("24");
    utilities::setPaletteColor(voltageValueLabel, QPalette::Text, Qt::white, true);
    voltageValueLabel->setAlignment(Qt::AlignHCenter);

    QFont voltageValueLabelFont = voltageValueLabel->font();
	voltageValueLabelFont.setPixelSize(dataValueLabelSize);
	voltageValueLabel->setFont(voltageValueLabelFont);

    dataValueHLayout->addWidget(voltageValueLabel);

    //

    currentValueLabel = new QLabel(this);

    currentValueLabel->setText("20");
    utilities::setPaletteColor(currentValueLabel, QPalette::Text, Qt::white, true);
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
    utilities::setPaletteColor(voltageLabelLabel, QPalette::Text, Qt::white, true);
    voltageLabelLabel->setAlignment(Qt::AlignHCenter);

    QFont voltageLabelLabelFont = voltageLabelLabel->font();
    voltageLabelLabelFont.setPixelSize(dataLabelLabelSize);
    voltageLabelLabel->setFont(voltageLabelLabelFont);

    dataLabelHLayout->addWidget(voltageLabelLabel);

    //

    currentLabelLabel = new QLabel(this);

    currentLabelLabel->setText("Amps");
    utilities::setPaletteColor(currentLabelLabel, QPalette::Text, Qt::white, true);
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
