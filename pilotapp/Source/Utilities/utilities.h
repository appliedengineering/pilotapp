#ifndef UTILITIES_H
#define UTILITIES_H

#include <QApplication>
#include <QMainWindow>
#include "../MainWindow.h"

class utilities {
private:
	static MainWindow* mainWindow;
public:
	static MainWindow* findMainWindow();
};

#endif // !UTILITIES_H
