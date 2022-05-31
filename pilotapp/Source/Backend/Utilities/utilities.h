#ifndef UTILITIES_H
#define UTILITIES_H

#include <QApplication>
#include <QMainWindow>
#include <QPainterPath>
#include <QRegion>
#include <QBitmap>
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <vector>
#include <string>
#include <math.h>
#include "../../MainWindow.h"

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
	
	/*static void changeFontSize(QLabel* l, int s);
	static void changeFontSize(QPushButton* b, int s);
	static void setFontAntialias(QFont* f);
	static void setFontLetterSpacing(QFont* f);*/

	static void setPaletteColor(QWidget* w, QPalette::ColorRole r, Qt::GlobalColor c, bool shouldNotAutoFillBackground = false);
	static void setWidgetRoundedCorner(QWidget* w, int r, std::vector<corners> noRoundCorner = {});
	static std::string createPaddingString(int n);
	static double roundDouble(double a, int places);
	static QIcon setIconColor(QIcon ic, QColor color, QColor current = Qt::black);
};

#endif // !UTILITIES_H
