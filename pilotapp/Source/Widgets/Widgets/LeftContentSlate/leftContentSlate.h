#ifndef LEFT_CONTENT_SLATE_H_
#define LEFT_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QProgressBar>
#include <QPushButton>
#include <QResizeEvent>

class leftContentSlateWidget : public QWidget {
	Q_OBJECT

private:
	QVBoxLayout* mainVBoxLayout;

	QFrame* dividerLine;
	
	//
	QWidget* topContent;
	
	//QHBoxLayout* topContentHBoxLayout;

	QWidget* topContentBatteryWidget;
	QHBoxLayout* topContentBatteryWidgetHBoxLayout;
	
	QProgressBar* topContentBatteryPercentBar;
	QLabel* topContentBatteryPercentLabel;
	QLabel* topContentBatteryVoltageLabel;
	QLabel* topContentBatteryCurrentLabel;

	QVBoxLayout* topContentVBoxLayout;
	QLabel* speedometerLabel;

	QHBoxLayout* topContentBottomHBoxLayout;
	QLabel* speedometerUnitLabel;

	//

	QWidget* bottomContent;

	QHBoxLayout* bottomContentHBoxLayout;
	//
	
	QVBoxLayout* bottomContentModelVBoxLayout;

	QLabel* modelLabel;
	QPushButton* motorButton;

	//

	QVBoxLayout* bottomContentBarVBoxLayout;

	QHBoxLayout* bottomContentBarLabelHBoxLayout;
	QLabel* throttleBarLabel;
	QLabel* dutyBarLabel;

	QHBoxLayout* bottomContentBarHBoxLayout;
	QProgressBar* throttleBar;
	QProgressBar* dutyBar;

	QHBoxLayout* bottomContentBarPercentLabelHBoxLayout;
	QLabel* throttleBarPercentLabel;
	QLabel* dutyBarPercentLabel;

	//

	void setupLayout();
	
	void renderTopContent();
	void renderBottomContent();

	void renderBatteryWidget();

	void resizeEvent(QResizeEvent*);

	void handleMotorButton();

public:
	static const float widthRatio; // 0.45

	leftContentSlateWidget(QWidget* parent = nullptr);
	~leftContentSlateWidget();

public slots:
	void updateSpeed(double speed);
	void updateThrottle(int percent);
	void updateDuty(int percent);
	void updateMotorButtonStatus();
	void updateBatteryPercent(int percent);

};

#endif // !LEFT_CONTENT_SLATE_H_
