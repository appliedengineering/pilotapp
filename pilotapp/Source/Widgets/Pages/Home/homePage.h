#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QDebug>

//

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "../../Widgets/Toolbar/toolbar.h"
#include "../../Widgets/LeftContentSlate/leftContentSlate.h"
#include "../../Widgets/MainContentSlate/mainContentSlate.h"

//

class homePage : public QWidget{
	Q_OBJECT

private:
	QVBoxLayout* vBox;
	QHBoxLayout* topContentHBox;
	
	leftContentSlateWidget* leftContentSlate;
	mainContentSlateWidget* mainContentSlate;
	toolbarWidget* toolbar;

	void setupLayout();

public:
	homePage(QWidget* parent = nullptr);
	~homePage();

	leftContentSlateWidget* getLeftContentSlateWidget();
	mainContentSlateWidget* getMainContentSlateWidget();
	toolbarWidget* getToolbarWidget();

};
#endif // !HOMEPAGE_H
