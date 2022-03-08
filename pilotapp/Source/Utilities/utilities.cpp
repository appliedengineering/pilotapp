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

void utilities::setPaletteColor(QWidget* w, QPalette::ColorRole r, Qt::GlobalColor c) {
	QPalette pal = w->palette();

	pal.setColor(r, c);
	w->setAutoFillBackground(true);
	
	w->setPalette(pal);
}

// https://stackoverflow.com/a/15289912/
void utilities::setWidgetRoundedCorner(QWidget* w, int r, std::vector<corners> noRoundCorner){
	QBitmap bmp(w->size());
    bmp.clear();
    QPainter painter(&bmp);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QColor(Qt::black));
    painter.setBrush(QColor(Qt::black));
    painter.drawRoundedRect(w->rect(), r, r, Qt::AbsoluteSize);
	
	for (int i = 0; i < noRoundCorner.size(); i++){
		switch (noRoundCorner[i])
		{	
		case topLeft:
			painter.drawRect(0, 0, r, r);
			break;
		
		case topRight:
			painter.drawRect(w->width() - r, 0, r, r);
			break;

		case bottomLeft:
			painter.drawRect(0, w->height() - r, r, r);
			break;

		case bottomRight:
			painter.drawRect(w->width() - r, w->height() - r, r, r);
			break;

		default:
			break;
		}
	}
	/*painter.drawRect(0, w->height() - r, r, r);
	painter.drawRect(w->width() - r, w->height() - r, r, r);*/
    
	w->setMask(bmp);
}