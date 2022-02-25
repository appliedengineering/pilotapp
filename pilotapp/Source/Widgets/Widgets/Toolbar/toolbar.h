#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include <QWidget>

#include <QPalette>
#include <QPushButton>
#include <QHBoxLayout>
#include <QString>
#include <QPixmap>
#include <QString>

#define toolbarButtonSize 7

class toolbarWidget : public QWidget{
	Q_OBJECT

private:
	const float heightRatio = 0.14;

	QHBoxLayout* hLayout;

	// home, audio, display, battery/solar (electronics), environment, telemetry, graphs/stats
	QPushButton* toolbarButtons[toolbarButtonSize]; 
	const QString toolBarButtonIconNames[toolbarButtonSize] = {"home.png", "sound.png", "screen.png", "electronics.png", "environment.png", "telemetry.png", "graphs.png"};

	void setupButtons();

public:
	toolbarWidget(QWidget* parent = nullptr);
	~toolbarWidget();
};

#endif // !TOOLBAR_H_
