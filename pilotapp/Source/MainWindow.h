#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//

#include "Widgets/Pages/Home/homePage.h"

//

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    homePage* home;

public slots:
    void handleExit();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
