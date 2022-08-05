#ifndef SETTINGS_OPTIONS_WIDGET_H_
#define SETTINGS_OPTIONS_WIDGET_H_

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QScroller>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>

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
    const int subHeaderLabelFontSize = 15;

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
    QLineEdit* ipcSubAddressLineEdit = nullptr;
    QLabel* ipcSubPortLabel = nullptr;
    QLineEdit* ipcSubPortLineEdit = nullptr;
    QLabel* scriptPairAddressLabel = nullptr;
    QLineEdit* scriptPairAddressLineEdit = nullptr;
    QLabel* scriptPairPortLabel = nullptr;
    QLineEdit* scriptPairPortLineEdit = nullptr;

    //

    QWidget* communicationsThreadSettingsWidget = nullptr;
    QVBoxLayout* communicationsThreadLayout = nullptr;
    QLabel* communicationsThreadLabel = nullptr;
    QLabel* loopTimeoutLabel = nullptr;
    QLineEdit* loopTimeoutLineEdit = nullptr;
    QLabel* stopThreadLabel = nullptr;
    QLineEdit* stopThreadLineEdit = nullptr;

    //

    QWidget* leftContentSlateSettingsWidget = nullptr;
    QVBoxLayout* leftContentSlateLayout = nullptr;
    QLabel* leftContentSlateLabel = nullptr;
    
    QLabel* speedometerUnitsLabel = nullptr;
    QHBoxLayout* unitsHorizontalLayout = nullptr;
    QRadioButton* knotsRadioButton = nullptr;
    QRadioButton* mphRadioButton = nullptr;    

    //

    QWidget* mapSettingsWidget = nullptr;
    QVBoxLayout* mapSettingsLayout = nullptr;
    QLabel* mapSettingsLabel = nullptr;
    
    QHBoxLayout* coordinatePrecisionLayout = nullptr;
    QLabel* coordinatePrecisionLabel = nullptr;
    QLabel* coordinatePrecisionValueLabel = nullptr;

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
    void renderDivider();
    void renderBottomActions();

    //
    
    void handleExit();

public:
    settingsOptionsWidget(QWidget* parent = nullptr);
    ~settingsOptionsWidget();

};

#endif