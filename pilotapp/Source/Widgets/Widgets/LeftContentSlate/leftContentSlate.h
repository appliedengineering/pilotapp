#ifndef LEFT_CONTENT_SLATE_H_
#define LEFT_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>

class leftContentSlateWidget : public QWidget {
	Q_OBJECT

private:
	const float widthRatio = 0.38;

public:
	leftContentSlateWidget(QWidget* parent = nullptr);
	~leftContentSlateWidget();

};

#endif // !LEFT_CONTENT_SLATE_H_
