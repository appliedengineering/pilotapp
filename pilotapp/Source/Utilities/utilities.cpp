#include "utilities.h"

MainWindow* utilities::mainWindow = nullptr;

MainWindow* utilities::findMainWindow() {
	
	if (utilities::mainWindow)
		return utilities::mainWindow;

	for (QWidget* w : QApplication::topLevelWidgets()) {
		MainWindow* wnd = qobject_cast<MainWindow*>(w);
		if (wnd) {
			utilities::mainWindow = wnd;
			return wnd;
		}
	}

	return nullptr;
}

void utilities::changeFontSize(QLabel* l, int s) {
	QFont f = l->font();
	f.setPointSize(s);
	l->setFont(f);
}

void utilities::setBackgroundColor(QWidget* w, Qt::GlobalColor c) {
	QPalette pal = w->palette();

	pal.setColor(QPalette::Background, c);
	w->setAutoFillBackground(true);
	
	w->setPalette(pal);
}