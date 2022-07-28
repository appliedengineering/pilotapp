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
    QPushButton* saveOptionsButton = nullptr;
    QPushButton* exitButton = nullptr;

    QLabel* minVoltage = nullptr;
    QLabel* maxVoltage = nullptr;

    void setupLayout();
    void renderContent();

    //

    void renderDivider();

    void renderBottomActions();
    void renderBoatKernel();
    void renderBoatKernel2();
    //
    
    void handleExit();

public:
    settingsOptionsWidget(QWidget* parent = nullptr);
    ~settingsOptionsWidget();

};

#endif