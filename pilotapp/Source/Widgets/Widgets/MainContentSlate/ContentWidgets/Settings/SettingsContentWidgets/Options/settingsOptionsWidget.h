#ifndef SETTINGS_OPTIONS_WIDGET_H_
#define SETTINGS_OPTIONS_WIDGET_H_

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScroller>
#include <QLineEdit>
#include <QLabel>

class settingsOptionsWidget : public QWidget{
    Q_OBJECT

private:
    const int verticalPadding = 10;
    const int horizontalPadding = 10;

    QVBoxLayout* vBoxLayout = nullptr;
    QScrollArea* scrollArea = nullptr;
    QWidget* scrollAreaContentWidget = nullptr;
    QVBoxLayout* scrollAreaContentLayout = nullptr;
    const int scrollAreaContentLayoutPadding = 10;

    const int bottomActionsFontSize = 14;
    QHBoxLayout* bottomActionsLayout = nullptr;
    QVBoxLayout* boatKernelLayout = nullptr;
    QVBoxLayout* commsManagerLayout = nullptr;
    QVBoxLayout* commsThreadLayout = nullptr;
    QVBoxLayout* leftContentSlateLayout = nullptr;
    QVBoxLayout* mapSettingsLayout = nullptr;
    QVBoxLayout* mapLayout = nullptr;
    QPushButton* saveOptionsButton = nullptr;
    QPushButton* exitButton = nullptr;

    QHBoxLayout* voltageBoxLayout = nullptr;
    QLabel* boatKernelLabel = nullptr;
    QLabel* minVoltageRangeLabel = nullptr;
    QLabel* maxVoltageRangeLabel = nullptr;
    QLabel* minMaxVoltageLabel = nullptr;

    QLabel* communicationsLabel = nullptr;
    QLabel* ipcSubAddressLabel = nullptr;
    QLabel* ipcSubPortLabel = nullptr;
    QLabel* scriptPairAddressLabel = nullptr;
    QLabel* scriptPairPortLabel = nullptr;

    QLabel* communicationsThreadLabel = nullptr;
    QLabel* loopTimeoutLabel = nullptr;
    QLabel* stopThreadLabel = nullptr;

    QLabel* leftContentSlateLabel = nullptr;
    QLabel* speedometerUnitsLabel = nullptr;

    QHBoxLayout* maxCoordPrecisionLayout = nullptr;
    QLabel* mapSettingsLabel = nullptr;
    QLabel* maxCoordPrecisionLabel = nullptr;
    QLabel* leftMaxCoordPrecisionLabel = nullptr;
    QLabel* rightMaxCoordPrecisionLabel = nullptr;

    QLabel* mapLabel = nullptr;
    QLabel* buoyMarkerSizeLabel = nullptr;
    QLabel* boatMarkerSizeLabel = nullptr;
    QLabel* mapCacheDataLabel = nullptr;

    void setupLayout();
    void renderContent();

    //

    void renderDivider();

    void renderBottomActions();
    void renderBoatKernel();
    void renderCommunicationsManager();
    void renderCommunicationsThread();
    void renderLeftContentSlate();
    void renderMapSettings();
    void renderMap();
    //
    
    void handleExit();

public:
    settingsOptionsWidget(QWidget* parent = nullptr);
    ~settingsOptionsWidget();

};

#endif