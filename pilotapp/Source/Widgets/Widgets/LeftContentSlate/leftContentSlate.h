#ifndef LEFT_CONTENT_SLATE_H_
#define LEFT_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>

class leftContentSlateWidget : public QWidget {
	Q_OBJECT

private:
	const float widthRatio = 0.3; // 1.0 - mainContentSlateWidget width ratio

public:
	leftContentSlateWidget(QWidget* parent = nullptr);
	~leftContentSlateWidget();

};

#endif // !LEFT_CONTENT_SLATE_H_
