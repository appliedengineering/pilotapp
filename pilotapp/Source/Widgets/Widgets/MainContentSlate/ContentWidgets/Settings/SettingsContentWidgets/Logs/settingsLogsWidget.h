#ifndef SETTINGS_LOGS_WIDGET_H_
#define SETTINGS_LOGS_WIDGET_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QResizeEvent>
#include <QLineEdit>

#include "../../../../../../../Backend/logManager.h" // possible header include loop

class settingsLogsWidget : public QWidget{
    Q_OBJECT

private:
    bool shouldStopLogs = false;

    QVBoxLayout* vBoxLayout = nullptr;

    QScrollArea* logScrollArea = nullptr;
    const int logScrollAreaStretchFactor = 85;
    QWidget* logScrollAreaContentWidget = nullptr;
    QVBoxLayout* logScrollAreaContentLayout = nullptr;
    const int logScrollAreaContentLayoutPadding = 10;

    const int optionsLayoutHoriziontalPadding = 10;
    const int optionsTopWidgetFontSize = 12;
    const int optionsCheckBoxFontSize = 14;

    QWidget* optionsTopWidget = nullptr;
    QHBoxLayout* optionsTopLayout = nullptr;
    QCheckBox* stopCheckBox = nullptr;
    //QLineEdit* bufferSizeLineEdit = nullptr;
    QPushButton* bufferSizeButton = nullptr;
    QCheckBox* saveOptionCheckBox = nullptr; // append / replace mode
    QPushButton* saveButton = nullptr;

    QWidget* optionsBottomWidget = nullptr;
    QHBoxLayout* optionsBottomLayout = nullptr;
    QCheckBox* filterCheckBoxes[4];
    QCheckBox* infoCheckBox = nullptr;
    QCheckBox* debugCheckBox = nullptr;
    QCheckBox* errorCheckBox = nullptr;
    QCheckBox* telemetryCheckBox = nullptr;
    QPushButton* clearLogsButton = nullptr;

    //

    void setupLayout();
    void setupLogs();
    void renderLogs();
    QLabel* renderLogEntry(std::string entry);

    void renderTopOptions();
    void renderBottomOptions();

    void handleStopCheckBox(bool shouldStop);

    void handleSaveButton();
    void handleFilterCheckBoxes(logManager::logType t);
    void handleClearButton();
    void handleBufferSizeButton();

    //

    bool isLogEntryTypeEnabled(const std::string& entry);

public:
    settingsLogsWidget(QWidget* parent = nullptr);
    ~settingsLogsWidget();

public slots:
    void removeFrontLogEntry();
    void appendLogEntry();

};

#endif