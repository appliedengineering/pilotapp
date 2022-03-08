#ifndef SETTINGS_WIDGET_H_
#define SETTINGS_WIDGET_H_

#include <QWidget>
#include <QPushButton>
#include "../../contentWidget.h"

class settingsWidget : public ContentWidget{
    Q_OBJECT

private:
    QPushButton* exitButton;

    void setupLayout();
    void handleExit();

public:
    settingsWidget(QWidget* parent = nullptr);
    ~settingsWidget();

};

#endif // !SETTINGS_WIDGET_H_