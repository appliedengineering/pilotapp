#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

//

#include "Widgets/Pages/Home/homePage.h"

//

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    homePage* home;

public slots:
    void closeApplication();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent* event);

    homePage* getHomePageWidget();
};
#endif // MAINWINDOW_H
