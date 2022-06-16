#include "settingsWidget.h"

#include "../../../../../Backend/Utilities/utilities.h"

#include "SettingsContentWidgets/Options/settingsOptionsWidget.h"

//

settingsWidget::settingsWidget(QWidget* parent){
    this->widgetType = fullscreen;
	utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    setupLayout();
    //setupContent();
}

settingsWidget::~settingsWidget(){
}

//

void settingsWidget::setupLayout(){

    hBoxLayout = new QHBoxLayout(this);
    this->setLayout(hBoxLayout);
    
    hBoxLayout->setContentsMargins(0, 0, 0, 0);
    hBoxLayout->setSpacing(0);
    /*hBoxLayout->setContentsMargins(horizontalPadding, verticalPadding, horizontalPadding, verticalPadding);
    hBoxLayout->setSpacing(horizontalPadding);*/

    //

    const int selectionVBoxLayoutStretchFactor = 25;

    selectionVBoxLayout = new QVBoxLayout();
    
    selectionVBoxLayout->setContentsMargins(0, 0, 0, 0);
    selectionVBoxLayout->setSpacing(0);

    hBoxLayout->addLayout(selectionVBoxLayout, selectionVBoxLayoutStretchFactor);

    //

    createSettingsContentWidgetForIndex(0); // default index

    hBoxLayout->addWidget(settingsContentWidget, 100 - selectionVBoxLayoutStretchFactor);
    settingsContentWidget->show();

}

void settingsWidget::createSettingsContentWidgetForIndex(int index){
    switch (index){
    case 0:
        settingsContentWidget = new settingsOptionsWidget(this);
        break;

    default:
        qWarning() << "invalid index for content widget creation";
        settingsContentWidget = new settingsOptionsWidget(this);
        break;
    }

    settingsContentWidget->setParent(this);
}

/*void settingsWidget::setupContent(){

    exitButton = new QPushButton(this);

    exitButton->setText("Close App");
    //exitButton->setContentsMargins(10, 0, 10, 0);
    
    QFont exitButtonFont = exitButton->font();
    exitButtonFont.setPixelSize(12);
    exitButton->setFont(exitButtonFont);

    utilities::setPaletteColor(exitButton, QPalette::ButtonText, Qt::white);

    //vBoxLayout->setAlignment(Qt::AlignLeft);
    hBoxLayout->addWidget(exitButton, 0, Qt::AlignHCenter);

    connect(exitButton, &QPushButton::released, this, &settingsWidget::handleExit);

    //
}*/

/*void settingsWidget::handleExit(){
    utilities::findMainWindow()->closeApplication();
}*/