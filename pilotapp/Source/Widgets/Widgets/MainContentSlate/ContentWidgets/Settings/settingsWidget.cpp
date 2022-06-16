#include "settingsWidget.h"

#include <QFrame>
#include <QPushButton>
#include "../../../../../Backend/Utilities/utilities.h"

#include "SettingsContentWidgets/Options/settingsOptionsWidget.h"

//

settingsWidget::settingsWidget(QWidget* parent){
    this->widgetType = fullscreen;
	utilities::setPaletteColor(this, QPalette::Background, Qt::black);

    //

    setupLayout();
    //setupContent();
    renderSelectionContent();
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

    const int dividerLineStretchFactor = 0;

    QFrame* dividerLine = new QFrame(this);

    //utilities::setPaletteColor(dividerWidget, QPalette::Background, Qt::white);
    dividerLine->setContentsMargins(0, 0, 0, 0);
    dividerLine->setFrameShape(QFrame::VLine);
    dividerLine->setFrameShadow(QFrame::Sunken);

    hBoxLayout->addWidget(dividerLine, dividerLineStretchFactor);

    //

    createSettingsContentWidgetForIndex(0); // default index

    hBoxLayout->addWidget(settingsContentWidget, 100 - selectionVBoxLayoutStretchFactor - dividerLineStretchFactor);
    settingsContentWidget->show();

}

void settingsWidget::renderSelectionContent(){

    for (int i = 0; i < selectionCount; i++){
        
        QPushButton* selectionButton = new QPushButton(this);
        selectionButton->setFixedHeight(50);
        selectionButton->setObjectName("selectionPushButton");
        
        selectionButton->setText(selectionTitles[i]);

        QFont selectionButtonFont = selectionButton->font();
        selectionButtonFont.setPixelSize(12);
        selectionButton->setFont(selectionButtonFont);

        utilities::setPaletteColor(selectionButton, QPalette::ButtonText, Qt::white);

        selectionVBoxLayout->addWidget(selectionButton);

        connect(selectionButton, &QPushButton::released, this, [=]{ handleSelectionButton(i); });

        //

        /*QFrame* dividerLine = new QFrame(this);

        dividerLine->setContentsMargins(0, 0, 0, 0);
        dividerLine->setFrameShape(QFrame::VLine);
        dividerLine->setFrameShadow(QFrame::Sunken);

        selectionVBoxLayout->addWidget(dividerLine);*/

    }
}

//

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

void settingsWidget::handleSelectionButton(int index){
    qDebug() << index;
}