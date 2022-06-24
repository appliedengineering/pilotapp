#ifndef SETTINGS_OPTIONS_WIDGET_H_
#define SETTINGS_OPTIONS_WIDGET_H_

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScroller>
#include <QLineEdit>

class settingsOptionsWidget : public QWidget{
    Q_OBJECT

private:
    QVBoxLayout* vBoxLayout = nullptr;
    QScrollArea* scrollArea = nullptr;
    QWidget* scrollAreaContentWidget = nullptr;
    QVBoxLayout* scrollAreaContentLayout = nullptr;
    const int scrollAreaContentLayoutPadding = 10;

    QPushButton* exitButton = nullptr;

    void setupLayout();
    void renderContent();

    //

    void renderDivider();

    void renderExitButton();
    
    //
    
    void handleExit();

public:
    settingsOptionsWidget(QWidget* parent = nullptr);
    ~settingsOptionsWidget();

};

#endif

