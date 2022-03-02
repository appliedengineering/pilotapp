#ifndef MAIN_CONTENT_SLATE_H_
#define MAIN_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>
#include <QHBoxLayout>
#include <QFrame>

#include "ContentWidgets/Map/mapWidget.h"
#include "ContentWidgets/Settings/settingsWidget.h"

class mainContentSlateWidget : public QWidget {
	Q_OBJECT

private:
	QHBoxLayout* mapLayout;
	mapWidget* map;

	QFrame* contentFrame;
	QWidget* contentWidget;

	void setupMapWidget();
	
	void createContentWidgetForIndex(int index);
	void showContentWidget(int index);
	void hideContentWidget();

public:
	mainContentSlateWidget(QWidget* parent = nullptr);
	~mainContentSlateWidget();

	void updateToWidgetIndex(int index);
};

#endif // !MAIN_CONTENT_SLATE_H_
