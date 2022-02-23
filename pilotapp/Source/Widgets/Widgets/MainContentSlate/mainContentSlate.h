#ifndef MAIN_CONTENT_SLATE_H_
#define MAIN_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>

class mainContentSlateWidget : public QWidget {
	Q_OBJECT

private:
	const float widthRatio = 0.7; // 1.0 - leftContentSlate width ratio

public:
	mainContentSlateWidget(QWidget* parent = nullptr);
	~mainContentSlateWidget();
};

#endif // !MAIN_CONTENT_SLATE_H_
