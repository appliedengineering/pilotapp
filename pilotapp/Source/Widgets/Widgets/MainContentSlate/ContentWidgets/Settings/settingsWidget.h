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
    const int horizontalPadding = 15;
    const int verticalPadding = 10;
    QVBoxLayout* vBoxLayout;

    QPushButton* exitButton;

    void setupLayout();
    void setupContent();
    void handleExit();

public:
    settingsWidget(QWidget* parent = nullptr);
    ~settingsWidget();

};

#endif // !SETTINGS_WIDGET_H_