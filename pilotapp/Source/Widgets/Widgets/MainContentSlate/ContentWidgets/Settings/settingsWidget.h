#ifndef SETTINGS_WIDGET_H_
#define SETTINGS_WIDGET_H_

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../../contentWidget.h"

class settingsWidget : public ContentWidget{
    Q_OBJECT

private:
    /*const int horizontalPadding = 15;
    const int verticalPadding = 10;*/

    QHBoxLayout* hBoxLayout = nullptr;

    QVBoxLayout* selectionVBoxLayout = nullptr;
    QWidget* settingsContentWidget = nullptr;

    void setupLayout();
    //void handleExit();

    //

    void createSettingsContentWidgetForIndex(int index);

public:
    settingsWidget(QWidget* parent = nullptr);
    ~settingsWidget();

};

#endif // !SETTINGS_WIDGET_H_