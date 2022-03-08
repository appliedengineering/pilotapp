#include "settingsWidget.h"

#include "../../../../../Utilities/utilities.h"

settingsWidget::settingsWidget(QWidget* parent){
    this->widgetType = fullscreen;
	utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    setupLayout();
}

settingsWidget::~settingsWidget(){

}

//

void settingsWidget::setupLayout(){

    QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
    this->setLayout(hBoxLayout);

    //

    exitButton = new QPushButton(this);
    exitButton->setText("Exit");
    utilities::setPaletteColor(exitButton, QPalette::Text, Qt::white);

    hBoxLayout->addWidget(exitButton);

    connect(exitButton, &QPushButton::released, this, &settingsWidget::handleExit);

    //


}

void settingsWidget::handleExit(){
    utilities::findMainWindow()->closeApplication();
}