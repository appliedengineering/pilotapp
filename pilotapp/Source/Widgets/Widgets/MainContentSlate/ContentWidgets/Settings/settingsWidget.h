#ifndef SETTINGS_WIDGET_H_
#define SETTINGS_WIDGET_H_

#include <QWidget>

class settingsWidget : public QWidget{
    Q_OBJECT

private:

public:
    settingsWidget(QWidget* parent = nullptr);
    ~settingsWidget();

};

#endif // !SETTINGS_WIDGET_H_