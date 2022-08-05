#ifndef SETTINGS_OPTIONS_WIDGET_H_
#define SETTINGS_OPTIONS_WIDGET_H_

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScroller>
#include <QLineEdit>
#include <QLabel>

#include "../../../../../../../Custom/TouchKeypad/touchKeypad.h"
#include "../../../../../../../Custom/TouchInputWidgets/TouchNumericalLineEdit/touchNumericalLineEdit.h"
#include "../../../../../../../Custom/RangeSlider/RangeSlider.h"

class settingsOptionsWidget : public QWidget{
    Q_OBJECT

private:
    const int verticalPadding = 10;
    const int horizontalPadding = 10;

    QVBoxLayout* vBoxLayout = nullptr;
    QScrollArea* scrollArea = nullptr;
    QWidget* scrollAreaContentWidget = nullptr;
    QVBoxLayout* scrollAreaContentLayout = nullptr;
    const int scrollAreaContentPadding = 10;

    //

    const int headerLabelFontSize = 18;
    const int subHeaderLabelFontSize = 14;

    //

    QWidget* boatKernelSettingsWidget = nullptr;
    QVBoxLayout* boatKernelLayout = nullptr;
    QLabel* boatKernelLabel = nullptr;
    QHBoxLayout* voltageBoxLayout = nullptr;
    RangeSlider* minMaxVoltageSlider = nullptr;
    QLabel* minVoltageRangeLabel = nullptr;
    QLabel* maxVoltageRangeLabel = nullptr;
    QLabel* voltageRangeLabel = nullptr;

    //

    QWidget* communicationsSettingsWidget = nullptr;
    QVBoxLayout* communicationsLayout = nullptr;
    QLabel* communicationsLabel = nullptr;
    QLabel* ipcSubAddressLabel = nullptr;
    QLabel* ipcSubPortLabel = nullptr;
    QLabel* scriptPairAddressLabel = nullptr;
    QLabel* scriptPairPortLabel = nullptr;

    //

    QVBoxLayout* commsThreadLayout = nullptr;
    QLabel* communicationsThreadLabel = nullptr;
    QLabel* loopTimeoutLabel = nullptr;
    QLabel* stopThreadLabel = nullptr;

    //

    QVBoxLayout* leftContentSlateLayout = nullptr;
    QLabel* leftContentSlateLabel = nullptr;
    QLabel* speedometerUnitsLabel = nullptr;

    //


    QVBoxLayout* mapSettingsLayout = nullptr;
    QHBoxLayout* maxCoordPrecisionLayout = nullptr;
    QLabel* mapSettingsLabel = nullptr;
    QLabel* maxCoordPrecisionLabel = nullptr;
    QLabel* leftMaxCoordPrecisionLabel = nullptr;
    QLabel* rightMaxCoordPrecisionLabel = nullptr;

    //

    QVBoxLayout* mapLayout = nullptr;
    QLabel* mapLabel = nullptr;
    QLabel* buoyMarkerSizeLabel = nullptr;
    QLabel* boatMarkerSizeLabel = nullptr;
    QLabel* mapCacheDataLabel = nullptr;

    //

    const int bottomActionsFontSize = 14;
    QHBoxLayout* bottomActionsLayout = nullptr;
    QPushButton* saveOptionsButton = nullptr;
    QPushButton* exitButton = nullptr;

    //

    void setupLayout();
    void renderContent();

    void renderBoatKernel();
    void renderCommunicationsManager();
    void renderCommunicationsThread();
    void renderLeftContentSlate();
    void renderMapSettings();
    void renderMap();
    void renderDivider();
    void renderBottomActions();

    //
    
    void handleExit();

public:
    settingsOptionsWidget(QWidget* parent = nullptr);
    ~settingsOptionsWidget();

};

#endif