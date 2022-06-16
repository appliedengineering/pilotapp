#ifndef SETTINGS_OPTIONS_WIDGET_H_
#define SETTINGS_OPTIONS_WIDGET_H_

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class settingsOptionsWidget : public QWidget{
    Q_OBJECT

private:
    QVBoxLayout* vBoxLayout = nullptr;
    
    QPushButton* exitButton = nullptr;

    void renderContent();
    void handleExit();

public:
    settingsOptionsWidget(QWidget* parent = nullptr);
    ~settingsOptionsWidget();

};

#endif

