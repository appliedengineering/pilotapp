#include "screenWidget.h"

#include <QFont>
#include <QInputDialog>

#include "../../../../../Backend/Utilities/utilities.h"

screenWidget::screenWidget(QWidget* parent){
    //this->widgetType = fullscreen;
    utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    const int screenWidgetWidth = parent->width() * 0.7;
    const int screenWidgetHeight = parent->height() * 0.25;
    this->setGeometry((parent->width()/2) - (screenWidgetWidth/2), parent->height() - screenWidgetHeight, screenWidgetWidth, screenWidgetHeight);
    utilities::setWidgetRoundedCorner(this, 10, {utilities::bottomLeft, utilities::bottomRight});

    //

    vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->setContentsMargins(horizontalPadding, verticalPadding, horizontalPadding, verticalPadding);
    vBoxLayout->setSpacing(verticalPadding);

    //

    renderContent();
}

screenWidget::~screenWidget(){
}

//

void screenWidget::renderContent(){
    displayControlEventFilter* displayFilter = utilities::findMainWindow()->getDisplayFilter();

    //

    timeoutHBoxLayout = new QHBoxLayout();

    timeoutHBoxLayout->setContentsMargins(0, 0, 0, 0);
    timeoutHBoxLayout->setSpacing(0);

    vBoxLayout->addLayout(timeoutHBoxLayout);

    //


    autoSleepCheckBox = new QCheckBox(this);

    autoSleepCheckBox->setText("Auto Sleep");
    autoSleepCheckBox->setChecked(displayFilter->getIsAutoSleepEnabled());

    utilities::setPaletteColor(autoSleepCheckBox, QPalette::WindowText, Qt::white, true);

    QFont autoSleepCheckBoxFont = autoSleepCheckBox->font();
    autoSleepCheckBoxFont.setPixelSize(contentFontSize);
    autoSleepCheckBox->setFont(autoSleepCheckBoxFont);

    connect(autoSleepCheckBox, &QCheckBox::clicked, this, &screenWidget::handleAutoSleepCheckBox);

    timeoutHBoxLayout->addWidget(autoSleepCheckBox, 100 - timeoutPushButtonStretchFactor);

    //

    timeoutPushButton = new QPushButton(this);

    timeoutPushButton->setText("Timeout");

    utilities::setPaletteColor(timeoutPushButton, QPalette::Background, Qt::gray);
    utilities::setPaletteColor(timeoutPushButton, QPalette::ButtonText, Qt::white);

    QFont timeoutPushButtonFont = timeoutPushButton->font();
    timeoutPushButtonFont.setPixelSize(contentFontSize);
    timeoutPushButton->setFont(timeoutPushButtonFont);

    connect(timeoutPushButton, &QPushButton::released, this, &screenWidget::handleTimeoutButton);

    timeoutHBoxLayout->addWidget(timeoutPushButton, timeoutPushButtonStretchFactor);

    ///

    brightnessRangeHBoxLayout = new QHBoxLayout();

    brightnessRangeHBoxLayout->setContentsMargins(0, 0, 0, 0);
    brightnessRangeHBoxLayout->setSpacing(horizontalPadding);

    vBoxLayout->addLayout(brightnessRangeHBoxLayout);

    //

    minimumBrightnessRangeLabel = new QLabel(this);

    minimumBrightnessRangeLabel->setText(QString::number(displayFilter->getMinBrightness()));
    minimumBrightnessRangeLabel->setAlignment(Qt::AlignHCenter);
    //minimumBrightnessRangeLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);

    utilities::setPaletteColor(minimumBrightnessRangeLabel, QPalette::Foreground, Qt::white, true);

    QFont minimumBrightnessRangeLabelFont = minimumBrightnessRangeLabel->font();
    minimumBrightnessRangeLabelFont.setPixelSize(contentFontSize);
    minimumBrightnessRangeLabel->setFont(minimumBrightnessRangeLabelFont);

    brightnessRangeHBoxLayout->addWidget(minimumBrightnessRangeLabel, (100 - brightnessRangeSliderStretchFactor) / 2);

    //

    brightnessRangeSlider = new RangeSlider(Qt::Horizontal, RangeSlider::DoubleHandles, this);

    //brightnessRangeSlider->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    brightnessRangeSlider->SetRange(displayFilter->getAbsoluteMinBrightness(), displayFilter->getAbsoluteMaxBrightness());
    brightnessRangeSlider->SetUpperValue(displayFilter->getMaxBrightness());
    brightnessRangeSlider->SetLowerValue(displayFilter->getMinBrightness());

    brightnessRangeHBoxLayout->addWidget(brightnessRangeSlider, brightnessRangeSliderStretchFactor);

    //

    maximumBrightnessRangeLabel = new QLabel(this);

    maximumBrightnessRangeLabel->setText(QString::number(displayFilter->getMaxBrightness()));
    maximumBrightnessRangeLabel->setAlignment(Qt::AlignHCenter);
    //maximumBrightnessRangeLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);

    utilities::setPaletteColor(maximumBrightnessRangeLabel, QPalette::Foreground, Qt::white, true);

    QFont maximumBrightnessRangeLabelFont = maximumBrightnessRangeLabel->font();
    maximumBrightnessRangeLabelFont.setPixelSize(contentFontSize);
    maximumBrightnessRangeLabel->setFont(maximumBrightnessRangeLabelFont);

    brightnessRangeHBoxLayout->addWidget(maximumBrightnessRangeLabel, (100 - brightnessRangeSliderStretchFactor) / 2);

    ///

    brightnessHBoxLayout = new QHBoxLayout();

    brightnessHBoxLayout->setContentsMargins(0, 0, 0, 0);
    brightnessHBoxLayout->setSpacing(horizontalPadding);

    vBoxLayout->addLayout(brightnessHBoxLayout);

    //

    brightnessSlider = new RangeSlider(Qt::Horizontal, RangeSlider::RightHandle, this);

    //brightnessSlider->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);    
    brightnessSlider->SetRange(displayFilter->getAbsoluteMinBrightness(), displayFilter->getAbsoluteMaxBrightness());
    brightnessSlider->SetUpperValue(displayFilter->getCurrentBrightness());

    brightnessHBoxLayout->addWidget(brightnessSlider, brightnessSliderStretchFactor);

    //

    brightnessLabel = new QLabel(this);

    brightnessLabel->setText(QString::number(displayFilter->getCurrentBrightness()));
    //brightnessLabel->setText("288");
    brightnessLabel->setWordWrap(true);
    brightnessLabel->setAlignment(Qt::AlignHCenter);
    //brightnessLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);

    utilities::setPaletteColor(brightnessLabel, QPalette::Foreground, Qt::white, true);
    //utilities::setPaletteColor(brightnessLabel, QPalette::Background, Qt::blue);

    QFont brightnessLabelFont = brightnessLabel->font();
    brightnessLabelFont.setPixelSize(contentFontSize);
    brightnessLabel->setFont(brightnessLabelFont);

    brightnessHBoxLayout->addWidget(brightnessLabel, 100 - brightnessSliderStretchFactor);

}

//

void screenWidget::handleAutoSleepCheckBox(){
    utilities::findMainWindow()->getDisplayFilter()->setAutoSleep(autoSleepCheckBox->isChecked());
}

void screenWidget::handleTimeoutButton(){
    QInputDialog b;
    b.setLabelText("Timeout (mins)");

    QFont bFont = b.font();
    bFont.setPixelSize(15);
    b.setFont(bFont);

    b.setIntMinimum(1);
    b.setIntMaximum(360);
    b.setIntStep(5);
    b.setIntValue(utilities::findMainWindow()->getDisplayFilter()->getTimeOut());

    //connect(b, &QInputDialog::);
    
    if (b.exec())
        utilities::findMainWindow()->getDisplayFilter()->setTimeOut(b.intValue());
}