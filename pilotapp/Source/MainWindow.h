#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QEvent>
#include <QMouseEvent>
#include <QQuickWidget>

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

    QQuickWidget* virtualKeyboardWidget = nullptr;

    void displayVirtualKeyboard();
    void hideVirtualKeyboard();

public slots:
    void closeApplication();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent* event);
    void mousePressEvent(QMouseEvent* e);

    homePage* getHomePageWidget();
    displayControlEventFilter* getDisplayFilter();
};
#endif // MAINWINDOW_H
