#include "toolbar.h"

#include "../../../Backend/Utilities/utilities.h"

#include <QDebug>

const float toolbarWidget::heightRatio = 0.14;

toolbarWidget::toolbarWidget(QWidget* parent) {

	home = qobject_cast<homePage*>(parent);

	//

	this->setFixedHeight((parent->height() * toolbarWidget::heightRatio));

	//

	utilities::setPaletteColor(this, QPalette::Background, Qt::black);

	//

	hLayout = new QHBoxLayout(this);
	hLayout->setContentsMargins(0,0,0,0);

	setupButtons();

}

toolbarWidget::~toolbarWidget() {
}

//

void toolbarWidget::setupButtons(){
	for (int i = 0; i < toolbarButtonSize; i++){
		toolbarButtons[i] = new QPushButton(this);
		toolbarButtons[i]->setObjectName("iconPushButton");
		
		toolbarButtons[i]->setMaximumWidth(this->height());
		toolbarButtons[i]->setFixedSize(this->height(), this->height());
		
		toolbarButtons[i]->setFlat(true);

		hLayout->addWidget(toolbarButtons[i]);

		//

		QPixmap pmap((":/Assets/Icons/" + toolBarButtonIconNames[i]));
		QIcon ic(pmap);

		toolbarButtons[i]->setIcon(ic);

		const int iconPadding = 20;
		toolbarButtons[i]->setIconSize(QSize(this->height() - 2*iconPadding, this->height() - 2*iconPadding));
		//toolbarButtons[i]->setIconSize(pmap.rect().size());

		utilities::setPaletteColor(toolbarButtons[i], QPalette::Button, Qt::black);
		//utilities::setPaletteColor(toolbarButtons[i], QPalette::Foreground, Qt::black);

		connect(toolbarButtons[i], &QPushButton::released, this, [=]{ handleToolbarButton(i); });

		//
		
	}
}

void toolbarWidget::handleToolbarButton(int buttonIndex){
	//qInfo() << "button pressed " << buttonIndex;
	home->getMainContentSlateWidget()->updateToWidgetIndex(buttonIndex);
}