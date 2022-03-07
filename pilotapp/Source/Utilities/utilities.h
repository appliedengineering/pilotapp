#ifndef UTILITIES_H
#define UTILITIES_H

#include <QApplication>
#include <QMainWindow>
#include <QPainterPath>
#include <QRegion>
#include <QBitmap>
#include <QPainter>
#include "../MainWindow.h"

class utilities {
private:
	static MainWindow* mainWindow;
public:
	static MainWindow* findMainWindow();
	static void changeFontSize(QLabel* l, int s);
	static void setPaletteColor(QWidget* w, QPalette::ColorRole r, Qt::GlobalColor c);
	static void setWidgetRoundedCorner(QWidget* w, int r);
};

#endif // !UTILITIES_H
