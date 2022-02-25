#include "toolbar.h"

#include "../../../Utilities/utilities.h"

#include <QDebug>

toolbarWidget::toolbarWidget(QWidget* parent) {

	this->setMaximumHeight(parent->height() * heightRatio);

	//

	utilities::setBackgroundColor(this, Qt::black);

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

		QPixmap pmap(("/Assets/Icons/" + toolBarButtonIconNames[i]));
		QIcon ic(pmap);

		qInfo() << pmap.isNull();

		toolbarButtons[i]->setIcon(ic);
		toolbarButtons[i]->setIconSize(pmap.rect().size());

		//
		
	}
}