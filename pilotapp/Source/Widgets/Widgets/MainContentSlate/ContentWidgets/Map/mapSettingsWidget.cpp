#include "mapSettingsWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"
#include "../../../../../Backend/boatKernel.h"
#include "../../../../../Backend/logManager.h"

#include <QDateTime>

mapSettingsWidget::mapSettingsWidget(QWidget* parent){
    //this->widgetType = fullscreen;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    const int mapSettingsWidgetWidth = parent->width() * 0.8;
    const int mapSettingsWidgetHeight = parent->height() * 0.13;
    this->setGeometry((parent->width()/2) - (mapSettingsWidgetWidth/2), parent->height() - mapSettingsWidgetHeight, mapSettingsWidgetWidth, mapSettingsWidgetHeight);
    utilities::setWidgetRoundedCorner(this, 10, {utilities::bottomLeft, utilities::bottomRight});

    //

    setupContent();

    //

    connect(boatKernel::getInstance(), &boatKernel::locationUpdateSignal, this, &mapSettingsWidget::updateBoatLocation);

}

mapSettingsWidget::~mapSettingsWidget(){
    disconnect(boatKernel::getInstance(), &boatKernel::locationUpdateSignal, this, &mapSettingsWidget::updateBoatLocation);
}

//

void mapSettingsWidget::setupContent(){
    hBoxLayout = new QHBoxLayout(this);

    const int contentPadding = 10;

    hBoxLayout->setContentsMargins(contentPadding, 0, contentPadding, 0);
    hBoxLayout->setSpacing(contentPadding);

    // 

    const int sideContentStretchFactor = 25;

    //

    titleLabel = new QLabel(this);

    titleLabel->setText("Boat\nPosition");
    utilities::setPaletteColor(titleLabel, QPalette::Foreground, Qt::white, true);
    //utilities::setPaletteColor(titleLabel, QPalette::Background, Qt::gray);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setWordWrap(true);

    QFont titleLabelFont = titleLabel->font();
    titleLabelFont.setPixelSize(15);
    titleLabel->setFont(titleLabelFont);

    hBoxLayout->addWidget(titleLabel, sideContentStretchFactor);

    //

    coordinateLabel = new QLabel(this);

    updateBoatLocation(boatKernel::getInstance()->getBoatLat(), boatKernel::getInstance()->getBoatLon());
    //coordinateLabel->setText();
    utilities::setPaletteColor(coordinateLabel, QPalette::Foreground, Qt::white, true);
    //utilities::setPaletteColor(coordinateLabel, QPalette::Background, Qt::gray);
    coordinateLabel->setAlignment(Qt::AlignCenter);

    QFont coordinateLabelFont = coordinateLabel->font();
    coordinateLabelFont.setPixelSize(15);
    coordinateLabel->setFont(coordinateLabelFont);

    hBoxLayout->addWidget(coordinateLabel, 100 - 2*sideContentStretchFactor);

    //

    saveCoordinateButton = new QPushButton(this);

    saveCoordinateButton->setText("Save");
    utilities::setPaletteColor(saveCoordinateButton, QPalette::Background, Qt::gray);
    utilities::setPaletteColor(saveCoordinateButton, QPalette::ButtonText, Qt::white);
    //utilities::setPaletteColor(saveCoordinateButton, QPalette::Background, Qt::white);

    QFont saveCoordinateButtonFont = saveCoordinateButton->font();
    saveCoordinateButtonFont.setPixelSize(12);
    saveCoordinateButton->setFont(saveCoordinateButtonFont);

    hBoxLayout->addWidget(saveCoordinateButton, sideContentStretchFactor);

    connect(saveCoordinateButton, &QPushButton::released, this, &mapSettingsWidget::saveCurrentCoordinates);
}

void mapSettingsWidget::saveCurrentCoordinates(){
    QFile coordinatelog(coordinateLogPath);

    if (coordinatelog.open(QIODevice::WriteOnly | QIODevice::Append)){
        QString timestamp = "//" + QString::number(QDateTime::currentSecsSinceEpoch()) + "\n";
        QString data = QString::number(boatKernel::getInstance()->getBoatLat()) + "," + QString::number(boatKernel::getInstance()->getBoatLon()) + "\n";
        coordinatelog.write(timestamp.toUtf8());
        coordinatelog.write(data.toUtf8());

        logManager::i("Saved coordinate - " + data.toStdString());

        utilities::createStatusDialogBox("Saved Coordinates")->exec();
    }

    coordinatelog.close();
}

//

void mapSettingsWidget::updateBoatLocation(double lat, double lon){
    coordinateLabel->setText("(" + QString::number(utilities::roundDouble(lat, coordinateDecimalPrecision)) + ", " + QString::number(utilities::roundDouble(lon, coordinateDecimalPrecision)) + ")");
}