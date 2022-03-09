#ifndef LEFT_CONTENT_SLATE_H_
#define LEFT_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>
#include <QVBoxLayout>
#include <QHBoxLayout>

class leftContentSlateWidget : public QWidget {
	Q_OBJECT

private:
	QVBoxLayout* mainVBoxLayout;
	QWidget* topContent;
	QWidget* bottomContent;

	void setupLayout();

public:
	static const float widthRatio; // 0.45

	leftContentSlateWidget(QWidget* parent = nullptr);
	~leftContentSlateWidget();

};

#endif // !LEFT_CONTENT_SLATE_H_
