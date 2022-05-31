#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include <QWidget>

#include <QPalette>
#include <QPushButton>
#include <QHBoxLayout>
#include <QString>
#include <QPixmap>
#include <QString>

#define toolbarButtonSize 6

class homePage;
class toolbarWidget : public QWidget{
	Q_OBJECT

private slots:
	void handleToolbarButton(int buttonIndex);

private:
	homePage* home;
	QHBoxLayout* hLayout;

	// home, map, display, battery/solar (electronics), telemetry, settings
	QPushButton* toolbarButtons[toolbarButtonSize]; 
	const QString toolBarButtonIconNames[toolbarButtonSize] = {"home.png", "map.png", "screen.png", "electronics.png", "telemetry.png", "settings.png"};

	void setupButtons();

public:
	static const float heightRatio; // 0.14

	toolbarWidget(QWidget* parent = nullptr);
	~toolbarWidget();
};

#endif // !TOOLBAR_H_
