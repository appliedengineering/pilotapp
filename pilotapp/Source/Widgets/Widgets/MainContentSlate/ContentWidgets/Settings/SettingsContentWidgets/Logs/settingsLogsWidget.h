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

class settingsLogsWidget : public QWidget{
    Q_OBJECT

private:
    QVBoxLayout* vBoxLayout = nullptr;

    QScrollArea* logScrollArea = nullptr;
    const int logScrollAreaStretchFactor = 85;
    QWidget* logScrollAreaContentWidget = nullptr;
    QVBoxLayout* logScrollAreaContentLayout = nullptr;
    const int logScrollAreaContentLayoutPadding = 10;

    QWidget* optionsTopWidget = nullptr;
    QHBoxLayout* optionsTopLayout = nullptr;
    QWidget* optionsBottomWidget = nullptr;
    QHBoxLayout* optionsBottomLayout = nullptr;
    const int optionsLayoutHoriziontalPadding = 10;
    const int optionsCheckBoxFontSize = 14;
    QCheckBox* stopCheckBox = nullptr;
    QCheckBox* infoCheckBox = nullptr;
    QCheckBox* debugCheckBox = nullptr;
    QCheckBox* errorCheckBox = nullptr;
    QCheckBox* telemetryCheckBox = nullptr;
    QCheckBox* saveOptionCheckBox = nullptr; // append / replace mode
    QPushButton* saveButton = nullptr;

    //

    void setupLayout();
    void setupLogs();
    void renderLogs();
    QLabel* renderLogEntry(std::string entry);

    void renderTopOptions();
    void renderBottomOptions();

    void handleSaveButton();

public:
    settingsLogsWidget(QWidget* parent = nullptr);
    ~settingsLogsWidget();

public slots:
    void removeFrontLogEntry();
    void appendLogEntry();

};

#endif