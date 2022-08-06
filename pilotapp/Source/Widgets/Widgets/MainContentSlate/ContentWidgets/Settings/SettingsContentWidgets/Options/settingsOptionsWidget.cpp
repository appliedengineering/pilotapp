#include "settingsOptionsWidget.h"

#include <QMessageBox>
#include <QFrame>

#include "../../../../../../../Backend/Utilities/utilities.h"
#include "../../../../../../../Backend/Communication/dataManager.h"

//

settingsOptionsWidget::settingsOptionsWidget(QWidget* parent){
    //utilities::setPaletteColor(this, QPalette::Background, Qt::blue);

    setupLayout();
    renderContent();
}

settingsOptionsWidget::~settingsOptionsWidget(){
}

//

void settingsOptionsWidget::setupLayout(){
    vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->setSpacing(0);

    //

    scrollArea = new QScrollArea(this);

    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);

    utilities::setPaletteColor(scrollArea, QPalette::Background, Qt::black);

    vBoxLayout->addWidget(scrollArea);

    //

    scrollAreaContentWidget = new QWidget(scrollArea);

    utilities::setPaletteColor(scrollAreaContentWidget, QPalette::Background, Qt::black);

    scrollArea->setWidget(scrollAreaContentWidget);

    //

    scrollAreaContentLayout = new QVBoxLayout(scrollAreaContentWidget);

    scrollAreaContentWidget->setLayout(scrollAreaContentLayout);

    scrollAreaContentLayout->setContentsMargins(scrollAreaContentPadding, scrollAreaContentPadding/2, scrollAreaContentPadding + scrollAreaContentPadding/2, scrollAreaContentPadding/2);
    scrollAreaContentLayout->setSpacing(scrollAreaContentPadding);
}

void settingsOptionsWidget::renderContent(){
    renderBoatKernel();
    renderCommunicationsManager();
    renderCommunicationsThread();
    renderLeftContentSlate();
    renderMapSettings();
    //renderMap();
    renderDivider();
    renderBottomActions();
}

//

void settingsOptionsWidget::renderBoatKernel(){

    boatKernelSettingsWidget = new QWidget(this);
    scrollAreaContentLayout->addWidget(boatKernelSettingsWidget);

    //

    boatKernelLayout = new QVBoxLayout(boatKernelSettingsWidget);
    boatKernelLayout->setContentsMargins(0, 0, 0, 0);

    //

    boatKernelLabel = new QLabel(boatKernelSettingsWidget);
    boatKernelLabel->setText("Boat Kernel");
    boatKernelLabel->setAlignment(Qt::AlignLeft);

    QFont boatKernelLabelFont = boatKernelLabel->font();
    boatKernelLabelFont.setPixelSize(headerLabelFontSize);
    boatKernelLabelFont.setBold(true);
    boatKernelLabel->setFont(boatKernelLabelFont);
    
    boatKernelLayout->addWidget(boatKernelLabel);

    /*

    voltageRangeLabel = new QLabel(boatKernelSettingsWidget);
    voltageRangeLabel->setFrameStyle(QFrame::Plain);
    voltageRangeLabel->setText("Min/Max Voltage");
    voltageRangeLabel->setAlignment(Qt::AlignRight);

    QFont voltageRangeLabelFont = voltageRangeLabel->font();
    voltageRangeLabelFont.setPixelSize(subHeaderLabelFontSize);
    voltageRangeLabel->setFont(voltageRangeLabelFont);

    boatKernelLayout->addWidget(voltageRangeLabel);

    //

    voltageBoxLayout = new QHBoxLayout();
    voltageBoxLayout->setContentsMargins(0, 0, 0, 0);
    voltageBoxLayout->setSpacing(horizontalPadding);

    boatKernelLayout->addLayout(voltageBoxLayout);

    //

    minVoltageRangeLabel = new QLabel(boatKernelSettingsWidget);
    minVoltageRangeLabel->setAlignment(Qt::AlignHCenter);
    minVoltageRangeLabel->setFixedWidth(30);
    minVoltageRangeLabel->setText(QString::number(boatDataPack::minPossibleVoltage)); //need backend changes

    voltageBoxLayout->addWidget(minVoltageRangeLabel);

    //

    minMaxVoltageSlider = new RangeSlider(Qt::Horizontal, RangeSlider::DoubleHandles, boatKernelSettingsWidget);
    minMaxVoltageSlider->SetRange(boatDataPack::minPossibleVoltage, boatDataPack::maxPossibleVoltage); //TODO: needs preference manager integration
    minMaxVoltageSlider->SetUpperValue(boatDataPack::maxPossibleVoltage);
    minMaxVoltageSlider->SetLowerValue(boatDataPack::minPossibleVoltage);

    voltageBoxLayout->addWidget(minMaxVoltageSlider);

    //

    maxVoltageRangeLabel = new QLabel(boatKernelSettingsWidget);
    maxVoltageRangeLabel->setAlignment(Qt::AlignHCenter);
    maxVoltageRangeLabel->setFixedWidth(30);
    maxVoltageRangeLabel->setText(QString::number(boatDataPack::maxPossibleVoltage)); //need backend changes

    voltageBoxLayout->addWidget(maxVoltageRangeLabel);*/

    //

    minVoltageLabel = new QLabel(boatKernelSettingsWidget);

    minVoltageLabel->setAlignment(Qt::AlignRight);
    minVoltageLabel->setText("Min Voltage");

    QFont minVoltageLabelFont = minVoltageLabel->font();
    minVoltageLabelFont.setPixelSize(subHeaderLabelFontSize);
    minVoltageLabel->setFont(minVoltageLabelFont);

    boatKernelLayout->addWidget(minVoltageLabel);

    //

    minVoltageLineEdit = new TouchNumericalLineEdit(boatKernelSettingsWidget);
    minVoltageLineEdit->setAlignment(Qt::AlignRight);
    boatKernelLayout->addWidget(minVoltageLineEdit);

    //

    maxVoltageLabel = new QLabel(boatKernelSettingsWidget);

    maxVoltageLabel->setAlignment(Qt::AlignRight);
    maxVoltageLabel->setText("Max Voltage");

    QFont maxVoltageLabelFont = maxVoltageLabel->font();
    maxVoltageLabelFont.setPixelSize(subHeaderLabelFontSize);
    maxVoltageLabel->setFont(maxVoltageLabelFont);

    boatKernelLayout->addWidget(maxVoltageLabel);

    //

    maxVoltageLineEdit = new TouchNumericalLineEdit(boatKernelSettingsWidget);
    maxVoltageLineEdit->setAlignment(Qt::AlignRight);
    boatKernelLayout->addWidget(maxVoltageLineEdit);

}

void settingsOptionsWidget::renderCommunicationsManager(){

    communicationsSettingsWidget = new QWidget(this);
    scrollAreaContentLayout->addWidget(communicationsSettingsWidget);
   
    //

    communicationsLayout = new QVBoxLayout(communicationsSettingsWidget);
    communicationsLayout->setContentsMargins(0, 0, 0, 0);

    //

    communicationsLabel = new QLabel(communicationsSettingsWidget);
    //communicationsLabel->setStyleSheet("font-weight: bold; font-size: 20px");
    communicationsLabel->setText("Communications");
    communicationsLabel->setAlignment(Qt::AlignLeft);

    QFont communicationsLabelFont = communicationsLabel->font();
    communicationsLabelFont.setPixelSize(headerLabelFontSize);
    communicationsLabelFont.setBold(true);
    communicationsLabel->setFont(communicationsLabelFont);

    communicationsLayout->addWidget(communicationsLabel);

    //

    ipcSubAddressLabel = new QLabel(communicationsSettingsWidget);
    ipcSubAddressLabel->setText("IPC IP Address");
    ipcSubAddressLabel->setAlignment(Qt::AlignRight);

    QFont ipcSubAddressLabelFont = ipcSubAddressLabel->font();
    ipcSubAddressLabelFont.setPixelSize(subHeaderLabelFontSize);
    ipcSubAddressLabel->setFont(ipcSubAddressLabelFont);

    communicationsLayout->addWidget(ipcSubAddressLabel);

    //

    ipcSubAddressLineEdit = new TouchNumericalLineEdit(communicationsSettingsWidget);
    ipcSubAddressLineEdit->setAlignment(Qt::AlignRight);
    communicationsLayout->addWidget(ipcSubAddressLineEdit);

    //

    ipcSubPortLabel = new QLabel(communicationsSettingsWidget);
    ipcSubPortLabel->setText("IPC Port");
    ipcSubPortLabel->setAlignment(Qt::AlignRight);

    QFont ipcSubPortLabelFont = ipcSubPortLabel->font();
    ipcSubPortLabelFont.setPixelSize(subHeaderLabelFontSize);
    ipcSubPortLabel->setFont(ipcSubPortLabelFont);

    communicationsLayout->addWidget(ipcSubPortLabel);

    //

    ipcSubPortLineEdit = new TouchNumericalLineEdit(communicationsSettingsWidget);
    ipcSubPortLineEdit->setAlignment(Qt::AlignRight);
    communicationsLayout->addWidget(ipcSubPortLineEdit);

    //

    scriptPairAddressLabel = new QLabel(communicationsSettingsWidget);
    scriptPairAddressLabel->setText("Script Pair Address");
    scriptPairAddressLabel->setAlignment(Qt::AlignRight);

    QFont scriptPairAddressLabelFont = scriptPairAddressLabel->font();
    scriptPairAddressLabelFont.setPixelSize(subHeaderLabelFontSize);
    scriptPairAddressLabel->setFont(scriptPairAddressLabelFont);

    communicationsLayout->addWidget(scriptPairAddressLabel);

    //
    
    scriptPairAddressLineEdit = new TouchNumericalLineEdit(communicationsSettingsWidget);
    scriptPairAddressLineEdit->setAlignment(Qt::AlignRight);
    communicationsLayout->addWidget(scriptPairAddressLineEdit);

    //

    scriptPairPortLabel = new QLabel(communicationsSettingsWidget);
    scriptPairPortLabel->setText("Script Pair Port");
    scriptPairPortLabel->setAlignment(Qt::AlignRight);

    QFont scriptPairPortLabelFont = scriptPairPortLabel->font();
    scriptPairPortLabelFont.setPixelSize(subHeaderLabelFontSize);
    scriptPairPortLabel->setFont(scriptPairPortLabelFont);

    communicationsLayout->addWidget(scriptPairPortLabel);

    //
    
    scriptPairPortLineEdit = new TouchNumericalLineEdit(communicationsSettingsWidget);
    scriptPairPortLineEdit->setAlignment(Qt::AlignRight);
    communicationsLayout->addWidget(scriptPairPortLineEdit);    
}

void settingsOptionsWidget::renderCommunicationsThread(){

    communicationsSettingsWidget = new QWidget(this);
    scrollAreaContentLayout->addWidget(communicationsSettingsWidget);

    //

    communicationsThreadLayout = new QVBoxLayout(communicationsSettingsWidget);
    communicationsThreadLayout->setContentsMargins(0, 0, 0, 0);

    //

    communicationsThreadLabel = new QLabel(communicationsSettingsWidget);
    //communicationsThreadLabel->setStyleSheet("font-weight: bold; font-size: 20px");
    communicationsThreadLabel->setText("Communications Thread");
    communicationsThreadLabel->setAlignment(Qt::AlignLeft);

    QFont communicationsThreadLabelFont = communicationsThreadLabel->font();
    communicationsThreadLabelFont.setPixelSize(headerLabelFontSize);
    communicationsThreadLabelFont.setBold(true);
    communicationsThreadLabel->setFont(communicationsThreadLabelFont);

    communicationsThreadLayout->addWidget(communicationsThreadLabel);

    //

    loopTimeoutLabel = new QLabel(communicationsSettingsWidget);
    loopTimeoutLabel->setText("Loop Timeout");
    loopTimeoutLabel->setAlignment(Qt::AlignRight);

    QFont loopTimeoutLabelFont = loopTimeoutLabel->font();
    loopTimeoutLabelFont.setPixelSize(subHeaderLabelFontSize);
    loopTimeoutLabel->setFont(loopTimeoutLabelFont);

    communicationsThreadLayout->addWidget(loopTimeoutLabel);

    //

    loopTimeoutLineEdit = new TouchNumericalLineEdit(communicationsSettingsWidget);
    loopTimeoutLineEdit->setAlignment(Qt::AlignRight);

    communicationsThreadLayout->addWidget(loopTimeoutLineEdit);

    //

    stopThreadLabel = new QLabel(communicationsSettingsWidget);
    stopThreadLabel->setText("Stop Thread");
    stopThreadLabel->setAlignment(Qt::AlignRight);

    QFont stopThreadLabelFont = stopThreadLabel->font();
    stopThreadLabelFont.setPixelSize(subHeaderLabelFontSize);
    stopThreadLabel->setFont(stopThreadLabelFont);

    communicationsThreadLayout->addWidget(stopThreadLabel);

    //

    stopThreadLineEdit = new TouchNumericalLineEdit(communicationsSettingsWidget);
    stopThreadLineEdit->setAlignment(Qt::AlignRight);

    communicationsThreadLayout->addWidget(stopThreadLineEdit);
}

void settingsOptionsWidget::renderLeftContentSlate(){

    leftContentSlateSettingsWidget = new QWidget(this);
    scrollAreaContentLayout->addWidget(leftContentSlateSettingsWidget);

    //

    leftContentSlateLayout = new QVBoxLayout(leftContentSlateSettingsWidget);
    leftContentSlateLayout->setContentsMargins(0, 0, 0, 0);

    //

    leftContentSlateLabel = new QLabel(leftContentSlateSettingsWidget);
    //leftContentSlateLabel->setStyleSheet("font-weight: bold; font-size: 20px");
    leftContentSlateLabel->setText("Left Content Slate");
    leftContentSlateLabel->setAlignment(Qt::AlignLeft);

    QFont leftContentSlateLabelFont = leftContentSlateLabel->font();
    leftContentSlateLabelFont.setPixelSize(headerLabelFontSize);
    leftContentSlateLabelFont.setBold(true);
    leftContentSlateLabel->setFont(leftContentSlateLabelFont);

    leftContentSlateLayout->addWidget(leftContentSlateLabel);

    //

    speedometerUnitsLabel = new QLabel(leftContentSlateSettingsWidget);
    speedometerUnitsLabel->setText("Speedometer Units");
    speedometerUnitsLabel->setAlignment(Qt::AlignRight);

    QFont speedometerUnitsLabelFont = speedometerUnitsLabel->font();
    speedometerUnitsLabelFont.setPixelSize(subHeaderLabelFontSize);
    speedometerUnitsLabel->setFont(speedometerUnitsLabelFont);

    leftContentSlateLayout->addWidget(speedometerUnitsLabel);

    //

    /*QLineEdit* speedometerUnitsLineEdit = new QLineEdit(leftContentSlateSettingsWidget);
    speedometerUnitsLineEdit->setAlignment(Qt::AlignRight);

    leftContentSlateLayout->addWidget(speedometerUnitsLineEdit);*/

    //

    unitsHorizontalLayout = new QHBoxLayout();
    unitsHorizontalLayout->setContentsMargins(0, 0, 0, 0);
    unitsHorizontalLayout->setAlignment(Qt::AlignRight);

    leftContentSlateLayout->addLayout(unitsHorizontalLayout);

    //

    knotsRadioButton = new QRadioButton(leftContentSlateSettingsWidget);

    knotsRadioButton->setContentsMargins(0, 0, 0, 0);
    knotsRadioButton->setText("Knots");
    knotsRadioButton->setChecked(true); // needs preferences manager integration

    unitsHorizontalLayout->addWidget(knotsRadioButton);

    //

    mphRadioButton = new QRadioButton(leftContentSlateSettingsWidget);

    mphRadioButton->setContentsMargins(0, 0, 0, 0);
    mphRadioButton->setText("MPH");

    unitsHorizontalLayout->addWidget(mphRadioButton);

}

void settingsOptionsWidget::renderMapSettings(){

    mapSettingsWidget = new QWidget(this);
    scrollAreaContentLayout->addWidget(mapSettingsWidget);

    //

    mapSettingsLayout = new QVBoxLayout(mapSettingsWidget);
    mapSettingsLayout->setContentsMargins(0, 0, 0, 0);

    //

    mapSettingsLabel = new QLabel(mapSettingsWidget);
    //mapSettingsLabel->setStyleSheet("font-weight: bold; font-size: 20px");
    mapSettingsLabel->setText("Map Settings");
    mapSettingsLabel->setAlignment(Qt::AlignLeft);

    QFont mapSettingsLabelFont = mapSettingsLabel->font();
    mapSettingsLabelFont.setPixelSize(headerLabelFontSize);
    mapSettingsLabelFont.setBold(true);
    mapSettingsLabel->setFont(mapSettingsLabelFont);

    mapSettingsLayout->addWidget(mapSettingsLabel);

    //

    coordinatePrecisionLabel = new QLabel(mapSettingsWidget);
    coordinatePrecisionLabel->setText("Coordinate Decimal Precision");
    coordinatePrecisionLabel->setAlignment(Qt::AlignRight);

    QFont coordinatePrecisionLabelFont = coordinatePrecisionLabel->font();
    coordinatePrecisionLabelFont.setPixelSize(subHeaderLabelFontSize);
    coordinatePrecisionLabel->setFont(coordinatePrecisionLabelFont);

    mapSettingsLayout->addWidget(coordinatePrecisionLabel);

    ///

    coordinatePrecisionLayout = new QHBoxLayout();
    coordinatePrecisionLayout->setContentsMargins(0, 0, 0, 0);
    coordinatePrecisionLayout->setSpacing(horizontalPadding);

    mapSettingsLayout->addLayout(coordinatePrecisionLayout);

    //

    RangeSlider* coordinatePrecisionSlider = new RangeSlider(Qt::Horizontal, RangeSlider::RightHandle, mapSettingsWidget);
    coordinatePrecisionSlider->SetRange(1, 6);
    coordinatePrecisionSlider->SetUpperValue(6);
    coordinatePrecisionSlider->SetLowerValue(1);

    coordinatePrecisionLayout->addWidget(coordinatePrecisionSlider);

    //

    coordinatePrecisionValueLabel = new QLabel(mapSettingsWidget);

    coordinatePrecisionValueLabel->setAlignment(Qt::AlignHCenter);
    coordinatePrecisionValueLabel->setFixedWidth(30);
    coordinatePrecisionValueLabel->setText("-1"); //need backend changes

    coordinatePrecisionLayout->addWidget(coordinatePrecisionValueLabel);

    ///

    buoyMarkerSizeLabel = new QLabel(mapSettingsWidget);
    buoyMarkerSizeLabel->setText("Buoy Marker Size");
    buoyMarkerSizeLabel->setAlignment(Qt::AlignRight);

    QFont buoyMarkerSizeLabelFont = buoyMarkerSizeLabel->font();
    buoyMarkerSizeLabelFont.setPixelSize(subHeaderLabelFontSize);
    buoyMarkerSizeLabel->setFont(buoyMarkerSizeLabelFont);

    mapSettingsLayout->addWidget(buoyMarkerSizeLabel);

    //

    QLineEdit* buoyMarkerSizeLineEdit = new TouchNumericalLineEdit(mapSettingsWidget);
    buoyMarkerSizeLineEdit->setAlignment(Qt::AlignRight);

    mapSettingsLayout->addWidget(buoyMarkerSizeLineEdit);
    
    //

    boatMarkerSizeLabel = new QLabel(mapSettingsWidget);
    boatMarkerSizeLabel->setText("Boat Marker Size");
    boatMarkerSizeLabel->setAlignment(Qt::AlignRight);

    QFont boatMarkerSizeLabelFont = boatMarkerSizeLabel->font();
    boatMarkerSizeLabelFont.setPixelSize(subHeaderLabelFontSize);
    boatMarkerSizeLabel->setFont(boatMarkerSizeLabelFont);

    mapSettingsLayout->addWidget(boatMarkerSizeLabel);

    //

    QLineEdit* boatMarkerSizeLineEdit = new TouchNumericalLineEdit(mapSettingsWidget);
    boatMarkerSizeLineEdit->setAlignment(Qt::AlignRight);

    mapSettingsLayout->addWidget(boatMarkerSizeLineEdit);

    //

    mapCacheDataLabel = new QLabel(mapSettingsWidget);
    mapCacheDataLabel->setText("Map Cache Data");
    mapCacheDataLabel->setAlignment(Qt::AlignRight);

    QFont mapCacheDataLabelFont = mapCacheDataLabel->font();
    mapCacheDataLabelFont.setPixelSize(subHeaderLabelFontSize);
    mapCacheDataLabel->setFont(mapCacheDataLabelFont);

    mapSettingsLayout->addWidget(mapCacheDataLabel);

    //

    QLineEdit* mapCacheDataLineEdit = new TouchNumericalLineEdit(mapSettingsWidget);
    mapCacheDataLineEdit->setAlignment(Qt::AlignRight);

    mapSettingsLayout->addWidget(mapCacheDataLineEdit);

    //
}

/*void settingsOptionsWidget::renderMap(){
    mapLayout = new QVBoxLayout(this);
    mapLayout->setContentsMargins(0, 0, 0, 0);
    mapLayout->setAlignment(Qt::AlignRight);
    auto leftLayout = new QVBoxLayout(this);
    leftLayout->setContentsMargins(0, 0, 0, 0);
    leftLayout->setAlignment(Qt::AlignLeft);

    scrollAreaContentLayout->addLayout(leftLayout);
    scrollAreaContentLayout->addLayout(mapLayout);

    mapLabel = new QLabel(this);
    //mapLabel->setStyleSheet("font-weight: bold; font-size: 20px");
    mapLabel->setText("Map");
    mapLabel->setAlignment(Qt::AlignLeft);

    QFont mapLabelFont = mapLabel->font();
    mapLabelFont.setPixelSize(headerLabelFontSize);
    mapLabelFont.setBold(true);
    mapLabel->setFont(mapLabelFont);

    leftLayout->addWidget(mapLabel);

    buoyMarkerSizeLabel = new QLabel(this);
    buoyMarkerSizeLabel->setFrameStyle(QFrame::Plain);
    buoyMarkerSizeLabel->setText("Buoy Marker Size");
    buoyMarkerSizeLabel->setAlignment(Qt::AlignRight);

    mapLayout->addWidget(buoyMarkerSizeLabel);

    QLineEdit* buoyMarkerSizeLineEdit = new TouchNumericalLineEdit(this);
    buoyMarkerSizeLineEdit->setAlignment(Qt::AlignRight);
    buoyMarkerSizeLineEdit->setFixedWidth(300);

    mapLayout->addWidget(buoyMarkerSizeLineEdit);

    boatMarkerSizeLabel = new QLabel(this);
    boatMarkerSizeLabel->setFrameStyle(QFrame::Plain);
    boatMarkerSizeLabel->setText("Boat Marker Size");
    boatMarkerSizeLabel->setAlignment(Qt::AlignRight);

    mapLayout->addWidget(boatMarkerSizeLabel);

    QLineEdit* boatMarkerSizeLineEdit = new TouchNumericalLineEdit(this);
    boatMarkerSizeLineEdit->setAlignment(Qt::AlignRight);
    boatMarkerSizeLineEdit->setFixedWidth(300);

    mapLayout->addWidget(boatMarkerSizeLineEdit);

    mapCacheDataLabel = new QLabel(this);
    mapCacheDataLabel->setFrameStyle(QFrame::Plain);
    mapCacheDataLabel->setText("Map Cache Data");
    mapCacheDataLabel->setAlignment(Qt::AlignRight);

    mapLayout->addWidget(mapCacheDataLabel);

    QLineEdit* mapCacheDataLineEdit = new QLineEdit(this);
    mapCacheDataLineEdit->setAlignment(Qt::AlignRight);
    mapCacheDataLineEdit->setFixedWidth(300);

    mapLayout->addWidget(mapCacheDataLineEdit);
}*/

void settingsOptionsWidget::renderDivider(){
    QFrame* divider = new QFrame(this);

    divider->setContentsMargins(0, 0, 0, 0);
    divider->setFrameShape(QFrame::HLine);
    divider->setFrameShadow(QFrame::Sunken);

    scrollAreaContentLayout->addWidget(divider);
}

void settingsOptionsWidget::renderBottomActions(){
    bottomActionsLayout = new QHBoxLayout();

    bottomActionsLayout->setContentsMargins(0, 0, 0, 0);
    bottomActionsLayout->setSpacing(horizontalPadding);

    scrollAreaContentLayout->addLayout(bottomActionsLayout);
    
    //

    saveOptionsButton = new QPushButton(this);

    saveOptionsButton->setText("Save Options");

    QFont saveOptionsButtonFont = saveOptionsButton->font();
    saveOptionsButtonFont.setPixelSize(bottomActionsFontSize);
    saveOptionsButton->setFont(saveOptionsButtonFont);

    utilities::setPaletteColor(saveOptionsButton, QPalette::ButtonText, Qt::white);

    bottomActionsLayout->addWidget(saveOptionsButton);

    //

    exitButton = new QPushButton(this);

    exitButton->setText("Close App");
    //exitButton->setContentsMargins(10, 0, 10, 0);
    
    QFont exitButtonFont = exitButton->font();
    exitButtonFont.setPixelSize(bottomActionsFontSize);
    exitButton->setFont(exitButtonFont);

    utilities::setPaletteColor(exitButton, QPalette::ButtonText, Qt::white);

    //vBoxLayout->setAlignment(Qt::AlignLeft);
    bottomActionsLayout->addWidget(exitButton);

    connect(exitButton, &QPushButton::released, this, &settingsOptionsWidget::handleExit);
}

//

void settingsOptionsWidget::handleExit(){
    QMessageBox b;
    b.setText("Close App");
    b.setInformativeText("Are you sure?");
    b.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    b.setDefaultButton(QMessageBox::Yes);

    if (b.exec() == QMessageBox::Yes)
        utilities::findMainWindow()->closeApplication();
}