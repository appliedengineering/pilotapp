#ifndef LEFT_CONTENT_SLATE_H_
#define LEFT_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>

class leftContentSlateWidget : public QWidget {
	Q_OBJECT

private:
	QVBoxLayout* mainVBoxLayout;

	QFrame* dividerLine;
	
	//
	QWidget* topContent;
	
	QVBoxLayout* topContentVBoxLayout;
	QLabel* speedometerLabel;

	QHBoxLayout* topContentBottomHBoxLayout;
	QLabel* speedometerUnitLabel;
	QWidget* batteryWidget;

	//

	QWidget* bottomContent;

	QVBoxLayout* bottomContentVBoxLayout;
	QLabel* modelLabel;

	//

	void setupLayout();
	
	void renderTopContent();
	void renderBottomContent();

public:
	static const float widthRatio; // 0.45

	leftContentSlateWidget(QWidget* parent = nullptr);
	~leftContentSlateWidget();

	void updateSpeedLabel(double speed);

};

#endif // !LEFT_CONTENT_SLATE_H_
