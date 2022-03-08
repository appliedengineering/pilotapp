#ifndef UTILITIES_H
#define UTILITIES_H

#include <QApplication>
#include <QMainWindow>
#include <QPainterPath>
#include <QRegion>
#include <QBitmap>
#include <QPainter>
#include <vector>
#include "../MainWindow.h"

class utilities {
private:
	static MainWindow* mainWindow;
public:
	enum corners{
		topLeft = 0,
		topRight = 1,
		bottomLeft = 2,
		bottomRight = 3,
		none = 4
	};

	static MainWindow* findMainWindow();
	static void changeFontSize(QLabel* l, int s);
	static void setPaletteColor(QWidget* w, QPalette::ColorRole r, Qt::GlobalColor c);
	static void setWidgetRoundedCorner(QWidget* w, int r, std::vector<corners> noRoundCorner = {});
};

#endif // !UTILITIES_H
