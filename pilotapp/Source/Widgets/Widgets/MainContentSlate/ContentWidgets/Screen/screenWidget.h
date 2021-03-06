#ifndef SCREEN_WIDGET_H_
#define SCREEN_WIDGET_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QResizeEvent>

#include "../../contentWidget.h"
#include "../../../../../Custom/RangeSlider/RangeSlider.h"
#include "../../../../../Backend/Display Control/displayControlEventFilter.h"
class screenWidget : public ContentWidget{
    Q_OBJECT

private:
    displayControlEventFilter* displayFilter = nullptr;

    const int horizontalPadding = 10;
    const int verticalPadding = 10;
    const int contentFontSize = 14;

    QVBoxLayout* vBoxLayout = nullptr;
    
    QHBoxLayout* timeoutHBoxLayout = nullptr;
    QCheckBox* autoSleepCheckBox = nullptr;
    QPushButton* timeoutPushButton = nullptr;
    const int timeoutPushButtonStretchFactor = 70;

    QHBoxLayout* brightnessRangeHBoxLayout = nullptr;
    QLabel* minimumBrightnessRangeLabel = nullptr;
    RangeSlider* brightnessRangeSlider = nullptr;
    const int brightnessRangeSliderStretchFactor = 80;
    QLabel* maximumBrightnessRangeLabel = nullptr;

    QHBoxLayout* brightnessHBoxLayout = nullptr;
    QLabel* brightnessIconLabel = nullptr;
    RangeSlider* brightnessSlider = nullptr;
    const int brightnessSliderStretchFactor = 80;
    QLabel* brightnessLabel = nullptr;

    //

    void renderContent();
    void resizeEvent(QResizeEvent*);

    void handleAutoSleepCheckBox();
    void handleTimeoutButton();
    void handleBrightnessRangeLowerSlider();
    void handleBrightnessRangeUpperSlider();
    void handleBrightnessSlider();

public:
    screenWidget(QWidget* parent = nullptr);
    ~screenWidget();
};

#endif