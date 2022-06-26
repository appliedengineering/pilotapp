#include "settingsOptionsWidget.h"

#include <QMessageBox>
#include <QFrame>

#include "../../../../../../../Backend/Utilities/utilities.h"
#include "../../../../../../../Custom/TouchKeypad/touchKeypad.h"
#include "../../../../../../../Custom/TouchInputWidgets/TouchNumericalLineEdit/touchNumericalLineEdit.h"

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
    QLineEdit* l = new TouchNumericalLineEdit(this);

    l->setText("0");

    scrollAreaContentLayout->addWidget(l);

    //

    renderDivider();
    renderBottomActions();
}

//

void settingsOptionsWidget::renderDivider(){
    QFrame* divider = new QFrame(this);

    divider->setContentsMargins(0, 0, 0, 0);
    divider->setFrameShape(QFrame::HLine);
    divider->setFrameShadow(QFrame::Sunken);

    scrollAreaContentLayout->addWidget(divider);
}

void settingsOptionsWidget::renderBottomActions(){
    bottomActionsLayout = new QHBoxLayout();

    bottomActionsLayout->setContentsMargins(0, 0, 0, 0);
    bottomActionsLayout->setSpacing(horizontalPadding);

    scrollAreaContentLayout->addLayout(bottomActionsLayout);
    
    //

    saveOptionsButton = new QPushButton(this);

    saveOptionsButton->setText("Save Options");

    QFont saveOptionsButtonFont = saveOptionsButton->font();
    saveOptionsButtonFont.setPixelSize(bottomActionsFontSize);
    saveOptionsButton->setFont(saveOptionsButtonFont);

    utilities::setPaletteColor(saveOptionsButton, QPalette::ButtonText, Qt::white);

    bottomActionsLayout->addWidget(saveOptionsButton);

    //

    exitButton = new QPushButton(this);

    exitButton->setText("Close App");
    //exitButton->setContentsMargins(10, 0, 10, 0);
    
    QFont exitButtonFont = exitButton->font();
    exitButtonFont.setPixelSize(bottomActionsFontSize);
    exitButton->setFont(exitButtonFont);

    utilities::setPaletteColor(exitButton, QPalette::ButtonText, Qt::white);

    //vBoxLayout->setAlignment(Qt::AlignLeft);
    bottomActionsLayout->addWidget(exitButton);

    connect(exitButton, &QPushButton::released, this, &settingsOptionsWidget::handleExit);
}

//

void settingsOptionsWidget::handleExit(){
    QMessageBox b;
    b.setText("Close program");
    b.setInformativeText("Are you sure?");
    b.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    //b.setDefaultButton(QMessageBox::No);

    if (b.exec() == QMessageBox::Yes)
        utilities::findMainWindow()->closeApplication();
}