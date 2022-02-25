#include "toolbar.h"

#include "../../../Utilities/utilities.h"

#include <QDebug>

toolbarWidget::toolbarWidget(QWidget* parent) {

	this->setMaximumHeight(parent->height() * heightRatio);

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

		hLayout->addWidget(toolbarButtons[i]);

		//

		QPixmap pmap((":/Assets/Icons/" + toolBarButtonIconNames[i]));
		QIcon ic(pmap);

		toolbarButtons[i]->setIcon(ic);

		const int iconPadding = 20;
		toolbarButtons[i]->setIconSize(QSize(this->height() - 2*iconPadding, this->height() - 2*iconPadding));
		//toolbarButtons[i]->setIconSize(pmap.rect().size());

		utilities::setPaletteColor(toolbarButtons[i], QPalette::Button, Qt::black);

		//
		
	}
}