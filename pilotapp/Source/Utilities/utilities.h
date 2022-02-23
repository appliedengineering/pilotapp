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
	static void changeFontSize(QLabel* l, int s);
	static void setBackgroundColor(QWidget* w, Qt::GlobalColor c);
};

#endif // !UTILITIES_H
