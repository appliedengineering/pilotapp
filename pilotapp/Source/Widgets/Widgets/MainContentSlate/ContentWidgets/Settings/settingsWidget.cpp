#include "settingsWidget.h"

#include "../../../../../Utilities/utilities.h"

settingsWidget::settingsWidget(QWidget* parent){
    this->widgetType = fullscreen;
	utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    setupLayout();
    setupContent();
}

settingsWidget::~settingsWidget(){
}

//

void settingsWidget::setupLayout(){

    vBoxLayout = new QVBoxLayout(this);
    this->setLayout(vBoxLayout);
    
    vBoxLayout->setContentsMargins(horizontalPadding, verticalPadding, horizontalPadding, verticalPadding);
    vBoxLayout->setSpacing(verticalPadding);

}

void settingsWidget::setupContent(){

    exitButton = new QPushButton(this);

    exitButton->setText("Close Application");
    utilities::setPaletteColor(exitButton, QPalette::Text, Qt::white);

    //vBoxLayout->setAlignment(Qt::AlignLeft);
    vBoxLayout->addWidget(exitButton, 0, Qt::AlignRight);

    connect(exitButton, &QPushButton::released, this, &settingsWidget::handleExit);

    //
}

void settingsWidget::handleExit(){
    utilities::findMainWindow()->closeApplication();
}