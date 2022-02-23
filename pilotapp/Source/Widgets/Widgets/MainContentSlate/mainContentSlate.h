#ifndef MAIN_CONTENT_SLATE_H_
#define MAIN_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>

class mainContentSlateWidget : public QWidget {
	Q_OBJECT

public:
	mainContentSlateWidget(QWidget* parent = nullptr);
	~mainContentSlateWidget();
};

#endif // !MAIN_CONTENT_SLATE_H_
