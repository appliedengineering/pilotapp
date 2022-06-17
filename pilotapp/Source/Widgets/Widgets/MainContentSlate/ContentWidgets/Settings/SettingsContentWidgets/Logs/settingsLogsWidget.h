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
    const int logScrollAreaStretchFactor = 86;
    QWidget* logScrollAreaContentWidget = nullptr;
    QVBoxLayout* logScrollAreaContentLayout = nullptr;
    const int logScrollAreaContentLayoutPadding = 10;

    QHBoxLayout* hBoxLayout = nullptr;
    QCheckBox* saveOptionCheckBox = nullptr;
    QLabel* saveOptionLabel = nullptr;
    QPushButton* saveButton = nullptr;

    //

    void setupLayout();
    void setupLogs();
    void renderLogs();
    void renderOptions();

    void resizeEvent(QResizeEvent*);

    void handleSaveButton();

public:
    settingsLogsWidget(QWidget* parent = nullptr);
    ~settingsLogsWidget();
};

#endif