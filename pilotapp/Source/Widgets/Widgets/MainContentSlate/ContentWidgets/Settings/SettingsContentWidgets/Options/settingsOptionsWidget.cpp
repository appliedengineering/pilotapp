#include "settingsOptionsWidget.h"

#include <QMessageBox>

#include "../../../../../../../Backend/Utilities/utilities.h"

//

settingsOptionsWidget::settingsOptionsWidget(QWidget* parent){
    //utilities::setPaletteColor(this, QPalette::Background, Qt::blue);

    setupLayout();
    renderContent();

}

settingsOptionsWidget::~settingsOptionsWidget(){
}

//

void settingsOptionsWidget::setupLayout(){
    vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->setSpacing(0);

    //

    scrollArea = new QScrollArea(this);

    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);

    utilities::setPaletteColor(scrollArea, QPalette::Background, Qt::black);

    vBoxLayout->addWidget(scrollArea);

    //

    scrollAreaContentWidget = new QWidget(scrollArea);

    utilities::setPaletteColor(scrollAreaContentWidget, QPalette::Background, Qt::black);

    scrollArea->setWidget(scrollAreaContentWidget);

    //

    scrollAreaContentLayout = new QVBoxLayout(scrollAreaContentWidget);

    scrollAreaContentWidget->setLayout(scrollAreaContentLayout);

    scrollAreaContentLayout->setContentsMargins(scrollAreaContentLayoutPadding, scrollAreaContentLayoutPadding/2, scrollAreaContentLayoutPadding + scrollAreaContentLayoutPadding/2, scrollAreaContentLayoutPadding/2);
    scrollAreaContentLayout->setSpacing(scrollAreaContentLayoutPadding);
}

void settingsOptionsWidget::renderContent(){
    exitButton = new QPushButton(this);

    exitButton->setText("Close App");
    //exitButton->setContentsMargins(10, 0, 10, 0);
    
    QFont exitButtonFont = exitButton->font();
    exitButtonFont.setPixelSize(12);
    exitButton->setFont(exitButtonFont);

    utilities::setPaletteColor(exitButton, QPalette::ButtonText, Qt::white);

    //vBoxLayout->setAlignment(Qt::AlignLeft);
    scrollAreaContentLayout->addWidget(exitButton, 0, Qt::AlignHCenter);

    connect(exitButton, &QPushButton::released, this, &settingsOptionsWidget::handleExit);
}

void settingsOptionsWidget::handleExit(){
    QMessageBox b;
    b.setText("Close the program");
    b.setInformativeText("Are you sure?");
    b.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    //b.setDefaultButton(QMessageBox::No);

    if (b.exec() == QMessageBox::Yes)
        utilities::findMainWindow()->closeApplication();
}