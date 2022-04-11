#include "settingsWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

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

    exitButton->setText("Close App");
    //exitButton->setContentsMargins(10, 0, 10, 0);
    
    QFont exitButtonFont = exitButton->font();
    exitButtonFont.setPointSize(12);
    exitButton->setFont(exitButtonFont);

    utilities::setPaletteColor(exitButton, QPalette::ButtonText, Qt::white);

    //vBoxLayout->setAlignment(Qt::AlignLeft);
    vBoxLayout->addWidget(exitButton, 0, Qt::AlignRight);

    connect(exitButton, &QPushButton::released, this, &settingsWidget::handleExit);

    //
}

void settingsWidget::handleExit(){
    utilities::findMainWindow()->closeApplication();
}