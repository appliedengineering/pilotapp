#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QEvent>

//

#include "Widgets/Pages/Home/homePage.h"
#include "Backend/Display Control/displayControlEventFilter.h"

//

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    homePage* home;
    displayControlEventFilter* displayFilter;

public slots:
    void closeApplication();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    static const int windowWidth;
    static const int windowHeight;

    void closeEvent(QCloseEvent* event);

    homePage* getHomePageWidget();
    displayControlEventFilter* getDisplayFilter();

    void showTouchKeypad();
};
#endif // MAINWINDOW_H
